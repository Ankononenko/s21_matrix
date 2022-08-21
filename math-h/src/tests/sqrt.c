#include "tests.h"

START_TEST(standart_int) {
    ck_assert_double_eq(sqrt(4), s21_sqrt(4));
} END_TEST

START_TEST(three_digit_num) {
    ck_assert_double_eq(sqrt(612), s21_sqrt(612));
} END_TEST

START_TEST(standart_float) {
    ck_assert_double_eq(sqrt(4.4), s21_sqrt(4.4));
} END_TEST

START_TEST(long_int) {
    ck_assert_double_eq(sqrt(LONG_MAX), s21_sqrt(LONG_MAX));
} END_TEST

START_TEST(negative_int) {
    ck_assert_double_nan(s21_sqrt(-1));
} END_TEST

START_TEST(zero) {
    ck_assert_double_eq(sqrt(0), s21_sqrt(0));
} END_TEST

START_TEST(one) {
    ck_assert_double_eq(sqrt(1), s21_sqrt(1));
} END_TEST

START_TEST(int_min) {
    ck_assert_double_nan(s21_sqrt(INT_MIN));
} END_TEST

START_TEST(negative_int_max) {
    ck_assert_double_nan(s21_sqrt(-INT_MAX));
} END_TEST

START_TEST(two) {
    ck_assert_double_eq_tol(s21_sqrt(2), sqrt(2), 1e-06);
} END_TEST

/* */
START_TEST(sqrt_1) {
    ck_assert_double_infinite(s21_sqrt(s21_INF));
} END_TEST

START_TEST(sqrt_2) {
    ck_assert_double_nan(s21_sqrt(-s21_INF));
} END_TEST

START_TEST(sqrt_3) {
    double num = -15.01;
    ck_assert_ldouble_nan(s21_sqrt(num));
} END_TEST

START_TEST(sqrt_4) {
    double num = 0.9999;
    long double orig_res = sqrt(num), our_res = s21_sqrt(num);
    int suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);
} END_TEST

START_TEST(sqrt_5) {
    double num = NAN;
    long double orig_res = sqrt(num), our_res = s21_sqrt(num);
    int suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);
} END_TEST

START_TEST(sqrt_6) {
    ck_assert_ldouble_infinite(s21_sqrt(INFINITY));
    ck_assert_ldouble_infinite(sqrt(INFINITY));
}
END_TEST

START_TEST(sqrt_7) {
    ck_assert_ldouble_nan(s21_sqrt(NAN));
    ck_assert_ldouble_nan(sqrt(NAN));
}
END_TEST

START_TEST(sqrt_8) {
    ck_assert_ldouble_eq_tol(s21_sqrt(1.0), sqrt(1.0), 1e-06);
    ck_assert_ldouble_eq_tol(s21_sqrt(1.1), sqrt(1.1), 1e-06);
}
END_TEST

START_TEST(sqrt_9) {
    ck_assert_ldouble_eq_tol(s21_sqrt(0.0), sqrt(0.0), 1e-06);
    ck_assert_ldouble_eq_tol(s21_sqrt(-0.0), sqrt(-0.0), 1e-06);
} END_TEST

START_TEST(sqrt_10) {
    ck_assert_ldouble_eq_tol(s21_sqrt(10e+16), sqrt(10e+16), 1e-06);
} END_TEST

START_TEST(sqrt_12) {
    ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), 1e-06);
} END_TEST

START_TEST(sqrt_13) {
    ck_assert_ldouble_eq_tol(s21_sqrt(100), sqrt(100), 1e-06);
} END_TEST

START_TEST(sqrt_14) {
    ck_assert_ldouble_eq_tol(s21_sqrt(98765432.123), sqrt(98765432.123), 1e-06);
} END_TEST

START_TEST(sqrt_15) {
    ck_assert_ldouble_eq_tol(s21_sqrt(981.123e6), sqrt(981.123e6), 1e-06);
} END_TEST

START_TEST(sqrt_16) {
    ck_assert_ldouble_eq_tol(s21_sqrt(981.123e-15), sqrt(981.123e-15), 1e-06);
} END_TEST

void sqrt_tests(TCase *tc) {
    tcase_add_test(tc, standart_int);
    tcase_add_test(tc, three_digit_num);
    tcase_add_test(tc, standart_float);
    tcase_add_test(tc, long_int);
    tcase_add_test(tc, negative_int);
    tcase_add_test(tc, zero);
    tcase_add_test(tc, one);
    tcase_add_test(tc, int_min);
    tcase_add_test(tc, negative_int_max);
    tcase_add_test(tc, two);
    /* */
    tcase_add_test(tc, sqrt_1);
    tcase_add_test(tc, sqrt_2);
    tcase_add_test(tc, sqrt_3);
    tcase_add_test(tc, sqrt_4);
    tcase_add_test(tc, sqrt_5);
    tcase_add_test(tc, sqrt_6);
    tcase_add_test(tc, sqrt_7);
    tcase_add_test(tc, sqrt_8);
    tcase_add_test(tc, sqrt_9);
    tcase_add_test(tc, sqrt_10);
    tcase_add_test(tc, sqrt_12);
    tcase_add_test(tc, sqrt_13);
    tcase_add_test(tc, sqrt_14);
    tcase_add_test(tc, sqrt_15);
    tcase_add_test(tc, sqrt_16);
    UNUSED_SHIT(sqrt_tests);
}
