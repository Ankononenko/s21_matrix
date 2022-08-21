#include "tests.h"

START_TEST(zero) {
    ck_assert_double_eq(s21_log(0), -s21_INF);
} END_TEST

START_TEST(one) {
    ck_assert_double_eq(s21_log(1), log(1));
} END_TEST

START_TEST(fifty) {
    ck_assert_ldouble_eq_tol(s21_log(50), log(50), 1e-06);
} END_TEST

START_TEST(negative_fifty) {
    ck_assert_ldouble_nan(s21_log(-50));
} END_TEST

START_TEST(negative) {
    ck_assert_double_nan(s21_log(-1));
} END_TEST

START_TEST(thirteen) {
    ck_assert_double_eq_tol(s21_log(13), log(13), 1e-06);
} END_TEST

START_TEST(not_a_num) {
    ck_assert_double_nan(s21_log(s21_NAN));
} END_TEST

START_TEST(infinity) {
    ck_assert_double_eq(s21_log(s21_INF), log(s21_INF));
} END_TEST

START_TEST(negative_infinity) {
    ck_assert_double_nan(s21_log(-s21_INF));
} END_TEST

/* */
START_TEST(log_1) {
  double num = 456.789;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_2) {
  double num = NAN;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_3) {
  double num = 0.001;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_4) {
  double num = 0.4;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-06)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_5) {
  double num = -INFINITY;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_6) {
  double num = INFINITY;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if (isinf(our_res) && isinf(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_7) {
  ck_assert_ldouble_infinite(s21_log(INFINITY));
  ck_assert_ldouble_infinite(log(INFINITY));

  ck_assert_ldouble_nan(s21_log(-INFINITY));
  ck_assert_ldouble_nan(log(-INFINITY));
}
END_TEST

START_TEST(log_8) {
  ck_assert_ldouble_nan(s21_log(NAN));
  ck_assert_ldouble_nan(log(NAN));
}
END_TEST

START_TEST(log_9) {
  ck_assert_ldouble_eq_tol(s21_log(1.0), log(1.0), 1e-06);
  ck_assert_ldouble_eq_tol(s21_log(1.1), log(1.1), 1e-06);
}
END_TEST

START_TEST(log_10) {
  ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-06);
}
END_TEST

START_TEST(log_11) {
  ck_assert_ldouble_eq_tol(s21_log(1), log(1), 1e-06);
}
END_TEST

START_TEST(log_12) {
  ck_assert_ldouble_eq_tol(s21_log(100), log(100), 1e-06);
}
END_TEST

START_TEST(log_13) {
  ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-06);
}
END_TEST

START_TEST(log_14) {
    ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-06);
}
END_TEST

START_TEST(log_15) {
    ck_assert_ldouble_eq_tol(s21_log(DBL_MAX), log(DBL_MAX), 1e-06);
}
END_TEST

START_TEST(log_16) {
  ck_assert_ldouble_eq_tol(s21_log(s21_PI / 3), log(s21_PI / 3), 1e-06);
}
END_TEST

START_TEST(log_17) {
  ck_assert_ldouble_eq_tol(s21_log(9.234578353457e-6), log(9.234578353457e-6),
                           1e-06);
}
END_TEST

START_TEST(log_18) {
  ck_assert_ldouble_eq_tol(s21_log(9.234578353457e6), log(9.234578353457e6),
                           1e-06);
}
END_TEST

START_TEST(log_19) {
  ck_assert_ldouble_eq_tol(s21_log(1234567.000000004), log(1234567.000000004),
                           1e-06);
}
END_TEST

START_TEST(log_20) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-16), log(1.1e-16), 1e-06);
}
END_TEST

START_TEST(log_24) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-45), log(1.1e-45), 1e-06);
}
END_TEST

START_TEST(log_25) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-18), log(1.1e-18), 1e-06);
}
END_TEST

START_TEST(log_26) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-19), log(1.1e-19), 1e-06);
}
END_TEST

START_TEST(log_27) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-23), log(1.1e-23), 1e-06);
}
END_TEST

START_TEST(log_21) {
  ck_assert_ldouble_eq_tol(s21_log(987654321123.123e-30),
                           log(987654321123.123e-30), 1e-06);
}
END_TEST

START_TEST(log_22) {
  ck_assert_ldouble_eq_tol(s21_log(98765.123e-11), log(98765.123e-11), 1e-06);
}
END_TEST

START_TEST(log_23) {
  ck_assert_ldouble_infinite(s21_log(0));
}
END_TEST

START_TEST(log_28) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-17), log(1.1e-17), 1e-06);
}
END_TEST

START_TEST(log_29) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-15), log(1.1e-15), 1e-06);
}
END_TEST

START_TEST(log_30) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-14), log(1.1e-14), 1e-06);
}
END_TEST

START_TEST(log_31) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-13), log(1.1e-13), 1e-06);
}
END_TEST

START_TEST(log_32) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-12), log(1.1e-12), 1e-06);
}
END_TEST

START_TEST(log_33) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-11), log(1.1e-11), 1e-06);
}
END_TEST

START_TEST(log_34) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-80), log(1.1e-80), 1e-06);
}
END_TEST

void log_tests(TCase *tc) {
    tcase_add_test(tc, zero);
    tcase_add_test(tc, one);
    tcase_add_test(tc, fifty);
    tcase_add_test(tc, negative_fifty);
    tcase_add_test(tc, negative);
    tcase_add_test(tc, thirteen);
    tcase_add_test(tc, not_a_num);
    tcase_add_test(tc, infinity);
    tcase_add_test(tc, negative_infinity);
    /* */
    tcase_add_test(tc, log_1);
    tcase_add_test(tc, log_2);
    tcase_add_test(tc, log_3);
    tcase_add_test(tc, log_4);
    tcase_add_test(tc, log_5);
    tcase_add_test(tc, log_6);
    tcase_add_test(tc, log_7);
    tcase_add_test(tc, log_8);
    tcase_add_test(tc, log_9);
    tcase_add_test(tc, log_10);
    tcase_add_test(tc, log_11);
    tcase_add_test(tc, log_12);
    tcase_add_test(tc, log_13);
    tcase_add_test(tc, log_14);
    tcase_add_test(tc, log_15);
    tcase_add_test(tc, log_16);
    tcase_add_test(tc, log_17);
    tcase_add_test(tc, log_18);
    tcase_add_test(tc, log_19);
    tcase_add_test(tc, log_20);
    tcase_add_test(tc, log_21);
    tcase_add_test(tc, log_22);
    tcase_add_test(tc, log_23);
    tcase_add_test(tc, log_24);
    tcase_add_test(tc, log_25);
    tcase_add_test(tc, log_26);
    tcase_add_test(tc, log_27);
    tcase_add_test(tc, log_28);
    tcase_add_test(tc, log_29);
    tcase_add_test(tc, log_30);
    tcase_add_test(tc, log_31);
    tcase_add_test(tc, log_32);
    tcase_add_test(tc, log_33);
    tcase_add_test(tc, log_34);
    UNUSED_SHIT(log_tests);
}
