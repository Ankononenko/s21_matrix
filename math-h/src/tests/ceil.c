#include "tests.h"

START_TEST(zero) {
    ck_assert_double_eq(ceil(0), s21_ceil(0));
} END_TEST

START_TEST(negative_one) {
    ck_assert_double_eq(ceil(-1.0), s21_ceil(-1.0));
} END_TEST

START_TEST(double_min) {
    ck_assert_double_eq(ceil(DBL_MIN), s21_ceil(DBL_MIN));
} END_TEST

START_TEST(double_max) {
    ck_assert_ldouble_eq(ceil(DBL_MAX), s21_ceil(DBL_MAX));
} END_TEST

START_TEST(negative_double_max) {
    ck_assert_double_eq(ceil(-DBL_MAX+1), s21_ceil(-DBL_MAX+1));
} END_TEST

START_TEST(three_and_point) {
    double k = 3, i = 0;
    while (k < 4) {
        k += 0.01;
        ck_assert_double_eq(ceil(i), s21_ceil(i));
    }
} END_TEST

START_TEST(negative_three_and_point) {
    double k = -3, i = 0;
    while (k > -4) {
        k -= 0.01;
        ck_assert_double_eq(ceil(i), s21_ceil(i));
    }
} END_TEST

START_TEST(infinity) {
    ck_assert_double_eq(ceil(s21_INF), s21_ceil(s21_INF));
} END_TEST

START_TEST(negative_infinity) {
    ck_assert_double_eq(ceil(-s21_INF), s21_ceil(-s21_INF));
} END_TEST

/* */
START_TEST(ceil_1) { ck_assert_ldouble_eq(s21_ceil(-15.01), ceil(-15.01)); }
END_TEST

START_TEST(ceil_2) { ck_assert_ldouble_eq(s21_ceil(15.01), ceil(15.01)); }
END_TEST

START_TEST(ceil_3) { ck_assert_ldouble_eq(s21_ceil(INFINITY), ceil(INFINITY)); }
END_TEST

START_TEST(ceil_4) {
  ck_assert_ldouble_eq(s21_ceil(-INFINITY), ceil(-INFINITY));
}
END_TEST

START_TEST(ceil_5) { ck_assert_ldouble_eq(s21_ceil(-0.12), ceil(-0.12)); }
END_TEST

START_TEST(ceil_6) {
  double num = NAN;
  long double orig_res = ceil(num), our_res = s21_ceil(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(ceil_7) {
  ck_assert_ldouble_infinite(s21_ceil(INFINITY));
  ck_assert_ldouble_infinite(ceil(INFINITY));
}
END_TEST

START_TEST(ceil_8) {
  ck_assert_ldouble_nan(s21_ceil(NAN));
  ck_assert_ldouble_nan(ceil(NAN));
}
END_TEST

START_TEST(ceil_9) {
    ck_assert_ldouble_eq(s21_ceil(0), ceil(0));
}
END_TEST

START_TEST(ceil_11) {
    ck_assert_ldouble_eq(s21_ceil(0.0), ceil(0.0));
}
END_TEST

START_TEST(ceil_12) {
    ck_assert_ldouble_eq(s21_ceil(21.21), ceil(21.21));
}
END_TEST

START_TEST(ceil_13) {
    ck_assert_ldouble_eq(s21_ceil(21.91), ceil(21.91));
}
END_TEST

START_TEST(ceil_14) {
    ck_assert_ldouble_eq(s21_ceil(-21.21), ceil(-21.21));
}
END_TEST

START_TEST(ceil_15) {
    ck_assert_ldouble_eq(s21_ceil(-21.91), ceil(-21.91));
}
END_TEST

START_TEST(ceil_16) {
    ck_assert_ldouble_eq(s21_ceil(DBL_MAX), ceil(DBL_MAX));
}
END_TEST

void ceil_tests(TCase *tc) {
    tcase_add_test(tc, zero);
    tcase_add_test(tc, negative_one);
    tcase_add_test(tc, double_min);
    tcase_add_test(tc, double_max);
    tcase_add_test(tc, negative_double_max);
    tcase_add_test(tc, three_and_point);
    tcase_add_test(tc, negative_three_and_point);
    tcase_add_test(tc, infinity);
    tcase_add_test(tc, negative_infinity);
    /* */
    tcase_add_test(tc, ceil_1);
    tcase_add_test(tc, ceil_2);
    tcase_add_test(tc, ceil_3);
    tcase_add_test(tc, ceil_4);
    tcase_add_test(tc, ceil_5);
    tcase_add_test(tc, ceil_6);
    tcase_add_test(tc, ceil_7);
    tcase_add_test(tc, ceil_8);
    tcase_add_test(tc, ceil_9);
    tcase_add_test(tc, ceil_11);
    tcase_add_test(tc, ceil_12);
    tcase_add_test(tc, ceil_13);
    tcase_add_test(tc, ceil_14);
    tcase_add_test(tc, ceil_15);
    tcase_add_test(tc, ceil_16);
}
