#include "tests.h"

START_TEST(zero) {
    ck_assert_double_eq(s21_factorial(0), 1);
} END_TEST

START_TEST(one) {
    ck_assert_double_eq(s21_factorial(1), 1);
} END_TEST

START_TEST(fifty) {
    ck_assert_double_eq(s21_factorial(10), 3628800);
} END_TEST

START_TEST(negative) {
    ck_assert_double_nan(s21_factorial(-1));
} END_TEST

START_TEST(thirteen) {
    ck_assert_double_eq(s21_factorial(13), 6227020800);
} END_TEST


void fact_tests(TCase *tc) {
    tcase_add_test(tc, zero);
    tcase_add_test(tc, one);
    tcase_add_test(tc, fifty);
    tcase_add_test(tc, negative);
    tcase_add_test(tc, thirteen);
}
