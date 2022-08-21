#include "tests.h"

START_TEST(negative_one) {
    ck_assert_int_eq(abs(-1), s21_abs(-1));
} END_TEST

START_TEST(int_min) {
    ck_assert_int_eq(abs(INT_MIN), s21_abs(INT_MIN));
} END_TEST

START_TEST(negative_int_max) {
    ck_assert_int_eq(abs(-INT_MAX), s21_abs(-INT_MAX));
} END_TEST

/* */
START_TEST(abs_1) { ck_assert_int_eq(s21_abs(21), abs(21)); }
END_TEST

START_TEST(abs_2) { ck_assert_int_eq(s21_abs(-21), abs(-21)); }
END_TEST

START_TEST(abs_3) { ck_assert_int_eq(s21_abs(-2147483647), abs(-2147483647)); }
END_TEST

START_TEST(abs_4) { ck_assert_int_eq(s21_abs(2147483647), abs(2147483647)); }
END_TEST

START_TEST(abs_5) { ck_assert_int_eq(s21_abs(-0), abs(-0)); }
END_TEST

START_TEST(abs_6) { ck_assert_int_eq(s21_abs(+0), abs(+0)); }
END_TEST

START_TEST(abs_7) { ck_assert_int_eq(s21_abs((int)NAN), abs((int)NAN)); }
END_TEST

START_TEST(abs_8) {
  ck_assert_int_eq(s21_abs((int)INFINITY), abs((int)INFINITY));
}
END_TEST

START_TEST(abs_9) {
  ck_assert_int_eq(s21_abs((int)-INFINITY), abs((int)-INFINITY));
}
END_TEST

START_TEST(abs_10) { ck_assert_int_eq(s21_abs(0), abs(0)); }
END_TEST

void abs_tests(TCase *tc) {
    tcase_add_test(tc, negative_one);
    tcase_add_test(tc, int_min);
    tcase_add_test(tc, negative_int_max);
/* */
    tcase_add_test(tc, abs_1);
    tcase_add_test(tc, abs_2);
    tcase_add_test(tc, abs_3);
    tcase_add_test(tc, abs_4);
    tcase_add_test(tc, abs_5);
    tcase_add_test(tc, abs_6);
    tcase_add_test(tc, abs_7);
    tcase_add_test(tc, abs_8);
    tcase_add_test(tc, abs_9);
    tcase_add_test(tc, abs_10);
    UNUSED_SHIT(abs_tests);
}
