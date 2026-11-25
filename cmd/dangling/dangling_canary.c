/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/*
 * Canary for the dangling-pointer detector (cmd/dangling/dangling.c).
 *
 * Leaves exactly one stale pointer where the detector must find it. The test
 * harness runs this with the detector preloaded and NSS_DANGLING_HOLDER_RE
 * pointing at this file, and fails the run if no report appears. Without it
 * a detector that is silently inert -- no symbolizer, an address layout it
 * does not expect, a sanitizer runtime it cannot hook -- would pass every
 * suite as clean.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(void)
{
    void *volatile *holder = calloc(8, sizeof(void *));
    void *target = malloc(48);
    int i;

    if (!holder || !target) {
        return 2;
    }
    memset(target, 0, 48);
    holder[3] = target;
    free(target);

    /* Age the free past any sensible NSS_DANGLING_MIN_AGE and cross several
     * scan intervals. The churn uses another size class so the freed target
     * is not handed out again while it should still be in quarantine. */
    for (i = 0; i < 4000; i++) {
        char *p = malloc(96);
        if (!p) {
            return 2;
        }
        p[0] = (char)i;
        free(p);
    }

    printf("canary holder %p still holds %p\n", (void *)holder, holder[3]);
    free((void *)holder);
    return 0;
}
