#include "tests.h"

START_TEST(zero) {
    ck_assert_double_eq(floor(0), s21_floor(0));
} END_TEST

START_TEST(negative_one) {
    ck_assert_double_eq(floor(-1.0), s21_floor(-1.0));
} END_TEST

START_TEST(negative_two) {
    ck_assert_double_eq(floor(-2.0), s21_floor(-2.0));
} END_TEST

START_TEST(negative_integer) {
    ck_assert_double_eq(floor(-212.0), s21_floor(-212.0));
} END_TEST

START_TEST(negative) {
    ck_assert_double_eq(floor(-2.78), s21_floor(-2.78));
} END_TEST

START_TEST(double_min) {
    ck_assert_double_eq(floor(DBL_MIN), s21_floor(DBL_MIN));
} END_TEST

START_TEST(double_max) {
    ck_assert_ldouble_eq(floor(DBL_MAX), s21_floor(DBL_MAX));
} END_TEST

START_TEST(negative_double_max) {
    ck_assert_double_eq(floor(-DBL_MAX), s21_floor(-DBL_MAX));
} END_TEST

START_TEST(three_and_point) {
    double k = 3, i = 0;
    while (k < 4) {
        k += 0.01;
        ck_assert_double_eq(floor(i), s21_floor(i));
    }
} END_TEST

START_TEST(negative_three_and_point) {
    double k = -3, i = 0;
    while (k > -4) {
        k -= 0.01;
        ck_assert_double_eq(floor(i), s21_floor(i));
    }
} END_TEST

START_TEST(infinity) {
    ck_assert_double_eq(floor(s21_INF), s21_floor(s21_INF));
} END_TEST

START_TEST(negative_infinity) {
    ck_assert_double_eq(floor(-s21_INF), s21_floor(-s21_INF));
} END_TEST

/* */
START_TEST(floor_1) { ck_assert_ldouble_eq(s21_floor(0.0), floor(0.0)); }
END_TEST

START_TEST(floor_2) { ck_assert_ldouble_eq(s21_floor(21.21), floor(21.21)); }
END_TEST

START_TEST(floor_3) { ck_assert_ldouble_eq(s21_floor(21.91), floor(21.91)); }
END_TEST

START_TEST(floor_4) { ck_assert_ldouble_eq(s21_floor(-21.21), floor(-21.21)); }
END_TEST

START_TEST(floor_5) { ck_assert_ldouble_eq(s21_floor(-21.91), floor(-21.91)); }
END_TEST

START_TEST(floor_6) {
  ck_assert_ldouble_infinite(s21_floor(INFINITY));
  ck_assert_ldouble_infinite(floor(INFINITY));
}
END_TEST

START_TEST(floor_7) {
  ck_assert_ldouble_nan(s21_floor(NAN));
  ck_assert_ldouble_nan(floor(NAN));
}
END_TEST

START_TEST(floor_8) { ck_assert_ldouble_eq(s21_floor(0), floor(0)); }
END_TEST

START_TEST(floor_10) { ck_assert_ldouble_eq(s21_floor(-15.01), floor(-15.01)); }
END_TEST

START_TEST(floor_11) { ck_assert_ldouble_eq(s21_floor(15.01), floor(15.01)); }
END_TEST

START_TEST(floor_12) {
  ck_assert_ldouble_eq(s21_floor(INFINITY), floor(INFINITY));
}
END_TEST

START_TEST(floor_13) {
  ck_assert_ldouble_eq(s21_floor(-INFINITY), floor(-INFINITY));
}
END_TEST

START_TEST(floor_14) {
  double num = NAN;
  long double orig_res = floor(num), our_res = s21_floor(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(floor_15) { ck_assert_ldouble_eq(s21_floor(-0), floor(-0)); }
END_TEST

void floor_tests(TCase *tc) {
    tcase_add_test(tc, zero);
    tcase_add_test(tc, negative_one);
    tcase_add_test(tc, negative_two);
    tcase_add_test(tc, negative_integer);
    tcase_add_test(tc, negative);
    tcase_add_test(tc, double_min);
    tcase_add_test(tc, double_max);
    tcase_add_test(tc, negative_double_max);
    tcase_add_test(tc, three_and_point);
    tcase_add_test(tc, negative_three_and_point);
    tcase_add_test(tc, infinity);
    tcase_add_test(tc, negative_infinity);
    /* */
    tcase_add_test(tc, floor_1);
    tcase_add_test(tc, floor_2);
    tcase_add_test(tc, floor_3);
    tcase_add_test(tc, floor_4);
    tcase_add_test(tc, floor_5);
    tcase_add_test(tc, floor_6);
    tcase_add_test(tc, floor_7);
    tcase_add_test(tc, floor_8);
    tcase_add_test(tc, floor_10);
    tcase_add_test(tc, floor_11);
    tcase_add_test(tc, floor_12);
    tcase_add_test(tc, floor_13);
    tcase_add_test(tc, floor_14);
    tcase_add_test(tc, floor_15);
}

