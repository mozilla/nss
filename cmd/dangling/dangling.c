/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/*
 * Dangling-pointer detector for AddressSanitizer builds.
 *
 * This is a diagnostic shim, not a library used by NSS. It is built only in
 * sanitizer builds and is loaded into the NSS test binaries with LD_PRELOAD
 * (the test harness does this when NSS_DANGLING is set). It reports pointer
 * fields inside live NSS heap objects that still point into memory which was
 * freed a non-trivial time ago -- i.e. latent use-after-free hazards that ASan
 * cannot see because nothing dereferences them.
 *
 * It piggybacks entirely on the ASan runtime already linked into the process:
 *   - __sanitizer_install_malloc_and_free_hooks  track live chunks
 *   - asan_address_is_poisoned / asan_get_free_stack  recognise freed memory
 *   - asan_locate_address, asan_get_alloc_stack       describe it
 *   - sanitizer_symbolize_pc                            print stacks
 * ASan keeps freed memory in a quarantine, which is the detection window.
 *
 * "Non-trivial time" is measured in allocations performed since the free, not
 * in wall-clock time: only reuse of the freed storage can turn a stale pointer
 * into a vulnerability, and reuse requires an allocation. This also makes
 * ordinary teardown (free the children, then the parent, with no allocation in
 * between) fall below the threshold and disappear.
 *
 * It is inert in non-ASan processes: if the hook-installer symbol is absent it
 * does nothing, so it is safe to export into the whole shell harness.
 *
 * Tunables (environment variables):
 *   NSS_DANGLING_SCAN_EVERY    scan once per this many frees          (1000)
 *   NSS_DANGLING_MIN_AGE       report only if freed >= this many
 *                              allocations ago                         (100)
 *   NSS_DANGLING_HOLDER_RE     extended regex; only holders whose
 *                              allocation stack matches are reported
 *   NSS_DANGLING_ARENA_HOLDERS 1 = also scan inside arena blocks        (0)
 *   NSS_DANGLING_FOREIGN_TARGETS 1 = also report pointers into memory
 *                              NSS neither allocated nor freed           (0)
 *   NSS_DANGLING_SUPPRESSIONS  path to a suppression file (one extended
 *                              regex per line; '#' comments). A report is
 *                              dropped if any regex matches a line of its
 *                              holder, free, or target-allocation stack.
 *   NSS_DANGLING_STATS         1 = print scan counts at exit
 *
 * Cost: each scan walks every live chunk that could be a reportable holder,
 * so the slowdown is (scan cost) x (frees / SCAN_EVERY). SCAN_EVERY is the
 * sensitivity knob -- a stale pointer that lives for fewer frees than that
 * can be missed -- and the holder prefilter at malloc time is the cost knob.
 */

#define _GNU_SOURCE
#include <dlfcn.h>
#include <pthread.h>
#include <regex.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <time.h>
#include <unistd.h>

/* ASan/sanitizer runtime entry points, resolved with dlsym at load. Keeping
 * them as pointers (rather than linking the symbols) means this .so has no
 * undefined references, so loading it into a non-ASan process -- a shell, sed,
 * the symbolizer child -- resolves nothing and the constructor simply bails. */
static int (*asan_address_is_poisoned)(const volatile void *);
static size_t (*asan_get_free_stack)(void *, void **, size_t, int *);
static size_t (*asan_get_alloc_stack)(void *, void **, size_t, int *);
static const char *(*asan_locate_address)(void *, char *, size_t, void **, size_t *);
static void (*asan_get_shadow_mapping)(size_t *, size_t *);
static void (*sanitizer_symbolize_pc)(void *, const char *, char *, size_t);

/* ---- mmap-backed open-addressing map: uintptr_t -> uintptr_t ----
 * key 0 means empty, key 1 means tombstone. Backed by mmap so the hooks never
 * re-enter the allocator we are instrumenting. |n| counts live keys and |used|
 * counts live keys plus tombstones; a rebuild is sized from |n| so the table
 * tracks the live set rather than every key ever inserted. That matters for
 * scan(), which walks the whole table of live chunks. */
typedef struct {
    uintptr_t *k, *v;
    size_t cap, n, used;
} map_t;

static void *
raw_alloc(size_t sz)
{
    return mmap(0, sz, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
}
static size_t
map_slot(const map_t *m, uintptr_t key)
{
    return (key * 0x9E3779B97F4A7C15ull >> 20) & (m->cap - 1);
}
static void map_put(map_t *m, uintptr_t key, uintptr_t val);
/* Rebuild without tombstones, at a capacity that keeps the live load under
 * 25%. The table may shrink. */
static void
map_grow(map_t *m)
{
    map_t nm = { 0 };
    nm.cap = 1 << 16;
    while (nm.cap < (m->n + 1) * 4)
        nm.cap *= 2;
    nm.k = raw_alloc(nm.cap * sizeof *nm.k);
    nm.v = raw_alloc(nm.cap * sizeof *nm.v);
    for (size_t i = 0; i < m->cap; i++)
        if (m->k[i] > 1)
            map_put(&nm, m->k[i], m->v[i]);
    if (m->cap) {
        munmap(m->k, m->cap * sizeof *m->k);
        munmap(m->v, m->cap * sizeof *m->v);
    }
    *m = nm;
}
static void
map_put(map_t *m, uintptr_t key, uintptr_t val)
{
    if ((m->used + 1) * 2 > m->cap)
        map_grow(m);
    size_t i = map_slot(m, key), tomb = (size_t)-1;
    while (m->k[i] != 0 && m->k[i] != key) {
        if (m->k[i] == 1 && tomb == (size_t)-1)
            tomb = i;
        i = (i + 1) & (m->cap - 1);
    }
    if (m->k[i] != key) {
        m->n++;
        if (tomb != (size_t)-1)
            i = tomb;
        else
            m->used++;
    }
    m->k[i] = key;
    m->v[i] = val;
}
static uintptr_t *
map_get(map_t *m, uintptr_t key)
{
    if (!m->cap)
        return 0;
    for (size_t i = map_slot(m, key); m->k[i]; i = (i + 1) & (m->cap - 1))
        if (m->k[i] == key)
            return &m->v[i];
    return 0;
}
static void
map_del(map_t *m, uintptr_t key)
{
    uintptr_t *v = map_get(m, key);
    if (v) {
        m->k[v - m->v] = 1;
        m->n--;
    }
}

/* ---- state ---- */
static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
static map_t live;      /* live chunk address -> size */
static map_t dead;      /* freed chunk address -> allocation counter at free */
static map_t reported;  /* dedupe key -> 1 */
static map_t pc_class;  /* pc -> 1 wrapper | 2 owner, +4 if arena allocator */
static map_t pc_holder; /* pc -> 1 reportable holder site | 2 not */
static map_t pc_supp;   /* pc -> 1 matches a suppression | 2 not */
static uint64_t allocs;
static uint64_t frees;
/* A live chunk whose allocation stack could never produce a report (not an
 * NSS/NSPR holder, vendored, arena, or suppressed) is flagged at malloc time
 * and skipped by scan(). This is purely a cost saving: report() would have
 * dropped anything found in it anyway. */
#define LIVE_SKIP ((uintptr_t)1 << (sizeof(uintptr_t) * 8 - 1))
static uint64_t stat_scans, stat_words, stat_chunks, stat_skipped, stat_scan_ns;
static uint64_t scan_every = 1000;
static uint64_t min_age = 100;
static int arena_holders;
static int foreign_targets;
static uintptr_t shadow_lo, shadow_hi;
/* One past the highest user-space address, derived at load from addresses
 * we can observe (stack, heap, this library). x86-64 uses 47 bits, aarch64
 * commonly 48; a hardcoded 47 would silently drop every aarch64 pointer. */
static uintptr_t addr_limit;
static __thread int in_hook;

/* A holder frame counts as NSS/NSPR if its source file is under lib/ or
 * /pr/src/ (available when the binary has DWARF), OR -- for stripped binaries
 * where only function and module names resolve -- if the owning module is an
 * NSS or NSPR shared library. The module alternation matches basenames like
 * libssl3.so, libfreeblpriv3.so, libnspr4.so inside the symbolized string. */
static const char *holder_re =
    "(^|/)lib/[A-Za-z0-9_]+/[A-Za-z0-9_.-]+[.][ch]:|/pr/src/"
    "|/lib(nss3|nssutil3|ssl3|smime3|freebl|softokn3|nssdbm3|nssckbi"
    "|nsssysinit|nspr4|plc4|plds4)";
static const char *vendored_re = "/lib/(sqlite|zlib)/";
static const char *wrapper_re =
    "^(malloc|calloc|realloc|free|memalign|posix_memalign|operator new|"
    "operator delete|PR_Malloc|PR_Calloc|PR_Realloc|PR_Free|"
    "PORT_(Z?Alloc|Z?Free|Realloc|Arena|FreeArena|NewArena|Strdup|ZNew)|"
    "PL_Arena|PL_FinishArenaPool|PL_FreeArenaPool|FreeArenaList|"
    "nss_Z|nss_z|nsslibc_)";
static const char *arena_re = "PL_ArenaAllocate|nss_zalloc_arena_locked";
static regex_t re_holder, re_vendored, re_wrapper, re_arena;

/* Suppressions loaded from NSS_DANGLING_SUPPRESSIONS. */
#define MAX_SUPPRESSIONS 256
static regex_t suppressions[MAX_SUPPRESSIONS];
static int num_suppressions;

static uintptr_t
classify(void *pc)
{
    uintptr_t *c = map_get(&pc_class, (uintptr_t)pc);
    if (c)
        return *c;
    char buf[1024];
    sanitizer_symbolize_pc(pc, "%f", buf, sizeof buf);
    uintptr_t v = regexec(&re_wrapper, buf, 0, 0, 0) ? 2 : 1;
    if (!regexec(&re_arena, buf, 0, 0, 0))
        v |= 4;
    map_put(&pc_class, (uintptr_t)pc, v);
    return v;
}

/* Index of the first frame that is not allocation plumbing; sets *arena if the
 * stack went through an arena allocator. */
static size_t
owner_frame(void **pcs, size_t n, int *arena)
{
    size_t o = n ? n - 1 : 0;
    for (size_t i = 0; i < n; i++) {
        uintptr_t c = classify(pcs[i]);
        if (arena && (c & 4))
            *arena = 1;
        if ((c & 3) == 2) {
            o = i;
            break;
        }
    }
    return o;
}

static int
loc_matches(void *pc, regex_t *re)
{
    char buf[1024];
    /* Include the module (%m) as well as function (%f) and file:line (%L):
     * when the binary carries no DWARF (stripped artifacts), %L is empty and
     * only the function name and the shared-library name resolve, so holder
     * classification must be able to match on those. */
    sanitizer_symbolize_pc(pc, "%f %L %m", buf, sizeof buf);
    return !regexec(re, buf, 0, 0, 0);
}

/* True if |pc| is a site whose allocations count as NSS/NSPR holders. */
static int
pc_is_holder(void *pc)
{
    uintptr_t *c = map_get(&pc_holder, (uintptr_t)pc);
    if (c)
        return *c == 1;
    int v = loc_matches(pc, &re_holder) && !loc_matches(pc, &re_vendored);
    map_put(&pc_holder, (uintptr_t)pc, v ? 1 : 2);
    return v;
}

/* True if |pc| matches any loaded suppression regex. */
static int
pc_is_suppressed(void *pc)
{
    uintptr_t *c = map_get(&pc_supp, (uintptr_t)pc);
    if (c)
        return *c == 1;
    char buf[1024];
    int v = 0;
    sanitizer_symbolize_pc(pc, "%f %L %m", buf, sizeof buf);
    for (int s = 0; s < num_suppressions && !v; s++)
        if (!regexec(&suppressions[s], buf, 0, 0, 0))
            v = 1;
    map_put(&pc_supp, (uintptr_t)pc, v ? 1 : 2);
    return v;
}

/* True if any frame matches any loaded suppression regex. */
static int
stack_suppressed(void **pcs, size_t n)
{
    for (size_t i = 0; i < n; i++)
        if (pc_is_suppressed(pcs[i]))
            return 1;
    return 0;
}

/* Decide at allocation time whether a finding in this chunk could ever be
 * reported; mirrors the holder-side checks in report(). Unknown stacks are
 * scanned, so the answer only ever errs towards scanning. */
static int
holder_scannable(const volatile void *p)
{
    void *pcs[32];
    int tid, arena = 0;
    size_t n = asan_get_alloc_stack((void *)p, pcs, 32, &tid);
    if (!n)
        return 1;
    size_t o = owner_frame(pcs, n, &arena);
    if (arena && !arena_holders)
        return 0;
    if (!pc_is_holder(pcs[o]))
        return 0;
    return !stack_suppressed(pcs, n);
}

static void
print_stack(const char *what, void **pcs, size_t n)
{
    char buf[1024];
    fprintf(stderr, "  %s\n", what);
    for (size_t i = 0; i < n; i++) {
        sanitizer_symbolize_pc(pcs[i], "%p %F %L", buf, sizeof buf);
        fprintf(stderr, "    #%zu %s\n", i, buf);
    }
}

static void
report(uintptr_t holder, size_t hsize, size_t off, uintptr_t target, uint64_t age)
{
    void *hpcs[64], *fpcs[64], *apcs[64];
    int tid, arena = 0;
    char name[1];
    void *rb;
    size_t rs;
    size_t nh = asan_get_alloc_stack((void *)holder, hpcs, 64, &tid);
    size_t nf = asan_get_free_stack((void *)target, fpcs, 64, &tid);
    size_t na = asan_get_alloc_stack((void *)target, apcs, 64, &tid);
    asan_locate_address((void *)target, name, 0, &rb, &rs);
    if (!nh || !nf)
        return;

    /* Conservative scan: reject a word that does not actually land inside the
     * freed region. An integer that merely looks like an address (e.g. RSA
     * blinding state) usually points outside any chunk; this drops the obvious
     * cases. Unsigned compare also rejects pointers before the region base. */
    if ((uintptr_t)target - (uintptr_t)rb >= rs)
        return;

    size_t ho = owner_frame(hpcs, nh, &arena), fo = owner_frame(fpcs, nf, 0);
    size_t ao = na ? owner_frame(apcs, na, 0) : 0;
    if (arena && !arena_holders)
        return;

    /* One report per (holder allocation site, field offset, free site). */
    uintptr_t key = ((uintptr_t)hpcs[ho] * 31 + off) * 0x9E3779B97F4A7C15ull ^
                    (uintptr_t)fpcs[fo];
    if (map_get(&reported, key))
        return;
    map_put(&reported, key, 1);

    if (!pc_is_holder(hpcs[ho]))
        return; /* holder is not an NSS/NSPR object */
    /* The target must be NSS/NSPR memory too: a real dangling pointer points
     * into something NSS allocated and freed, not into a freed gtest container
     * or other foreign heap block that merely happens to sit in the quarantine
     * where a data word in the holder points. Requiring an NSS/NSPR frame on
     * the target's own alloc or free stack removes that whole coincidence
     * class (random key material, EC points, session-cache bytes resembling a
     * freed C++ object) without touching real finds, whose target is NSS. Set
     * NSS_DANGLING_FOREIGN_TARGETS=1 to also report pointers into foreign
     * memory, e.g. when chasing a dangler into caller- or NSPR-owned storage. */
    if (!foreign_targets &&
        !(nf && pc_is_holder(fpcs[fo])) &&
        !(na && pc_is_holder(apcs[ao])))
        return;
    if (stack_suppressed(hpcs, nh) || stack_suppressed(fpcs, nf) ||
        stack_suppressed(apcs, na))
        return;

    fprintf(stderr,
            "==%d==WARNING: DanglingPointer: %zu-byte live heap %s +%zu holds %p, "
            "%zu bytes into a freed %zu-byte block (freed %llu allocations ago)\n",
            getpid(), hsize, arena ? "arena block" : "object", off, (void *)target,
            (size_t)((uintptr_t)target - (uintptr_t)rb), rs,
            (unsigned long long)age);
    print_stack(arena ? "arena block allocated by:" : "holder allocated by:",
                hpcs, nh);
    print_stack("target freed by:", fpcs, nf);
    print_stack("target allocated by:", apcs, na);
}

/* scan() deliberately reads arbitrary words out of live allocations, including
 * redzones and the arena tails NSS poisons by hand (PL_MAKE_MEM_NOACCESS). The
 * reads are physically safe; only ASan instrumentation would object, so this
 * one function is built without it. */
__attribute__((no_sanitize("address", "undefined"))) static void
scan(void)
{
    void *pcs[1];
    int tid;
    char nm[1];
    void *rb;
    size_t rs;
    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    stat_scans++;
    for (size_t i = 0; i < live.cap; i++) {
        uintptr_t chunk = live.k[i], size = live.v[i];
        if (chunk <= 1)
            continue;
        if (size & LIVE_SKIP) {
            stat_skipped++;
            continue;
        }
        stat_chunks++;
        stat_words += size / sizeof(void *);
        for (size_t off = 0; off + sizeof(void *) <= size; off += sizeof(void *)) {
            uintptr_t w = *(uintptr_t *)(chunk + off);
            /* Reject small values and (on 64-bit) non-canonical / above-user
             * addresses. Widen before shifting so the shift count is valid when
             * uintptr_t is 32 bits (the 32-bit shift would be a -Werror
             * shift-count-overflow); the test is simply always false there. */
            if (w < 0x10000 || w >= addr_limit ||
                (w >= shadow_lo && w < shadow_hi))
                continue;
            if (!asan_address_is_poisoned((void *)w))
                continue; /* live memory: cheap shadow check */
            if (!asan_get_free_stack((void *)w, pcs, 1, &tid))
                continue; /* not a quarantined chunk */
            asan_locate_address((void *)w, nm, 0, &rb, &rs);
            uintptr_t *fs = map_get(&dead, (uintptr_t)rb);
            uint64_t age = fs ? allocs - *fs : 0;
            if (age >= min_age)
                report(chunk, size, off, w, age);
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);
    stat_scan_ns += (uint64_t)(t1.tv_sec - t0.tv_sec) * 1000000000ull +
                    (uint64_t)(t1.tv_nsec - t0.tv_nsec);
}

static void
on_malloc(const volatile void *p, size_t sz)
{
    if (in_hook)
        return;
    in_hook = 1;
    pthread_mutex_lock(&lock);
    allocs++;
    map_put(&live, (uintptr_t)p, holder_scannable(p) ? sz : (sz | LIVE_SKIP));
    map_del(&dead, (uintptr_t)p);
    pthread_mutex_unlock(&lock);
    in_hook = 0;
}

static void
on_free(const volatile void *p)
{
    if (in_hook)
        return;
    in_hook = 1;
    pthread_mutex_lock(&lock);
    map_del(&live, (uintptr_t)p);
    map_put(&dead, (uintptr_t)p, allocs);
    if (++frees % scan_every == 0)
        scan();
    pthread_mutex_unlock(&lock);
    in_hook = 0;
}

static void
load_suppressions(const char *path)
{
    FILE *f = fopen(path, "r");
    if (!f)
        return;
    char line[1024];
    while (num_suppressions < MAX_SUPPRESSIONS && fgets(line, sizeof line, f)) {
        char *s = line;
        while (*s == ' ' || *s == '\t')
            s++;
        size_t len = strlen(s);
        while (len && (s[len - 1] == '\n' || s[len - 1] == '\r' ||
                       s[len - 1] == ' ' || s[len - 1] == '\t'))
            s[--len] = 0;
        if (!len || *s == '#')
            continue;
        if (regcomp(&suppressions[num_suppressions], s, REG_EXTENDED | REG_NOSUB) == 0)
            num_suppressions++;
    }
    fclose(f);
}

__attribute__((destructor)) static void
dangling_fini(void)
{
    if (stat_scans && getenv("NSS_DANGLING_STATS"))
        fprintf(stderr,
                "==%d==DanglingPointer stats: %llu scans in %llu ms, %llu chunks "
                "(%llu words) scanned, %llu chunks skipped, %llu allocs, %llu "
                "frees, live table %zu/%zu slots, %d suppressions, "
                "%d address bits\n",
                getpid(), (unsigned long long)stat_scans,
                (unsigned long long)(stat_scan_ns / 1000000),
                (unsigned long long)stat_chunks, (unsigned long long)stat_words,
                (unsigned long long)stat_skipped, (unsigned long long)allocs,
                (unsigned long long)frees, live.n, live.cap, num_suppressions,
                64 - __builtin_clzll(addr_limit - 1));
}

__attribute__((constructor)) static void
dangling_init(void)
{
    int (*install)(void (*)(const volatile void *, size_t),
                   void (*)(const volatile void *)) =
        dlsym(RTLD_DEFAULT, "__sanitizer_install_malloc_and_free_hooks");
    asan_address_is_poisoned = dlsym(RTLD_DEFAULT, "__asan_address_is_poisoned");
    asan_get_free_stack = dlsym(RTLD_DEFAULT, "__asan_get_free_stack");
    asan_get_alloc_stack = dlsym(RTLD_DEFAULT, "__asan_get_alloc_stack");
    asan_locate_address = dlsym(RTLD_DEFAULT, "__asan_locate_address");
    asan_get_shadow_mapping = dlsym(RTLD_DEFAULT, "__asan_get_shadow_mapping");
    sanitizer_symbolize_pc = dlsym(RTLD_DEFAULT, "__sanitizer_symbolize_pc");

    /* No malloc-hook installer means this is not an ASan process (a shell, sed,
     * the symbolizer child); stay silent so preloading everywhere is harmless. */
    if (!install)
        return;
    int diag = getenv("NSS_DANGLING_STATS") || getenv("NSS_DANGLING_DIAG");
    if (!asan_address_is_poisoned || !asan_get_free_stack ||
        !asan_get_alloc_stack || !asan_locate_address ||
        !asan_get_shadow_mapping || !sanitizer_symbolize_pc) {
        /* An ASan process whose runtime is missing an entry point we need. */
        if (diag)
            fprintf(stderr, "==%d==dangling: inactive, an __asan/__sanitizer "
                            "entry point could not be resolved\n",
                    getpid());
        return;
    }

    const char *e;
    if ((e = getenv("NSS_DANGLING_SCAN_EVERY")))
        scan_every = strtoull(e, 0, 0);
    if ((e = getenv("NSS_DANGLING_MIN_AGE")))
        min_age = strtoull(e, 0, 0);
    if ((e = getenv("NSS_DANGLING_HOLDER_RE")))
        holder_re = e;
    if ((e = getenv("NSS_DANGLING_ARENA_HOLDERS")))
        arena_holders = atoi(e);
    if ((e = getenv("NSS_DANGLING_FOREIGN_TARGETS")))
        foreign_targets = atoi(e);
    if (!scan_every)
        scan_every = 1;

    regcomp(&re_holder, holder_re, REG_EXTENDED | REG_NOSUB);
    regcomp(&re_vendored, vendored_re, REG_EXTENDED | REG_NOSUB);
    regcomp(&re_wrapper, wrapper_re, REG_EXTENDED | REG_NOSUB);
    regcomp(&re_arena, arena_re, REG_EXTENDED | REG_NOSUB);
    if ((e = getenv("NSS_DANGLING_SUPPRESSIONS")))
        load_suppressions(e);

    size_t scale, off;
    void *heap = malloc(1);
    uintptr_t hi = (uintptr_t)&scale;
    if ((uintptr_t)heap > hi)
        hi = (uintptr_t)heap;
    if ((uintptr_t)dangling_init > hi)
        hi = (uintptr_t)dangling_init;
    free(heap);
    addr_limit = (uintptr_t)1 << (64 - __builtin_clzll(hi));
    asan_get_shadow_mapping(&scale, &off);
    shadow_lo = off;
    shadow_hi = ((addr_limit - 1) >> scale) + off + 1;
    install(on_malloc, on_free);

    /* Diagnostic probe: show that the detector armed and, crucially, what a
     * symbolized frame looks like here -- whether file:line and the module
     * resolve. A holder is classified from exactly this string, so if it
     * lacks both a file path and a known module, the detector cannot work in
     * this environment. Gated on NSS_DANGLING_DIAG so normal runs stay quiet;
     * the harness sets it for the canary. */
    if (getenv("NSS_DANGLING_DIAG")) {
        char b[1024];
        sanitizer_symbolize_pc((void *)(uintptr_t)&dangling_init, "%f %L %m", b,
                               sizeof b);
        fprintf(stderr, "==%d==dangling: armed; self-symbolize='%s'\n",
                getpid(), b);
    }
}
