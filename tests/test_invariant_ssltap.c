#include <check.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* Simulate the vulnerable structure and bounds check that MUST hold */
#define MSG_BUF_SIZE 65536

typedef struct {
    unsigned char *msgBuf;
    unsigned int msgBufSize;
    unsigned int msgBufOffset;
} SSLSessionState;

/* Security invariant: recordLen + msgBufOffset must never exceed msgBufSize */
static int is_copy_safe(unsigned int msgBufOffset, unsigned int recordLen, unsigned int msgBufSize)
{
    /* Check for overflow and bounds */
    if (recordLen > msgBufSize)
        return 0;
    if (msgBufOffset > msgBufSize)
        return 0;
    if (msgBufOffset + recordLen > msgBufSize)
        return 0;
    return 1;
}

START_TEST(test_msgbuf_bounds_check)
{
    /* Invariant: memcpy into msgBuf must never write beyond allocated size */
    struct {
        unsigned int offset;
        unsigned int recordLen;
    } payloads[] = {
        { 65530, 100 },       /* Exploit: offset + len > bufsize */
        { 0, 65537 },         /* Boundary: recordLen exceeds buffer */
        { 0, 1024 },          /* Valid: normal TLS record */
        { 65535, 1 },         /* Boundary: exactly at limit */
        { 65536, 0 },         /* Edge: offset at max, zero length */
    };
    int num_payloads = sizeof(payloads) / sizeof(payloads[0]);

    SSLSessionState s;
    s.msgBufSize = MSG_BUF_SIZE;
    s.msgBuf = malloc(s.msgBufSize);
    ck_assert_ptr_nonnull(s.msgBuf);

    for (int i = 0; i < num_payloads; i++) {
        s.msgBufOffset = payloads[i].offset;
        unsigned int recordLen = payloads[i].recordLen;

        int safe = is_copy_safe(s.msgBufOffset, recordLen, s.msgBufSize);
        
        /* Security property: if bounds check passes, copy must be within bounds */
        if (safe) {
            ck_assert_uint_le(s.msgBufOffset + recordLen, s.msgBufSize);
        }
        /* Adversarial inputs should fail the bounds check */
        if (s.msgBufOffset + recordLen > s.msgBufSize) {
            ck_assert_int_eq(safe, 0);
        }
    }

    free(s.msgBuf);
}
END_TEST

Suite *security_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Security");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_msgbuf_bounds_check);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = security_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}