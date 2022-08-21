#include "tests.h"

START_TEST(zero) {
    ck_assert_double_eq(s21_atan(0), atan(0));
} END_TEST

START_TEST(one) {
    ck_assert_double_eq_tol(s21_atan(1), atan(1), 1e-06);
} END_TEST

START_TEST(ten) {
    ck_assert_double_eq_tol(s21_atan(-9), atan(-9), 1e-7);
} END_TEST

START_TEST(negative) {
    ck_assert_double_eq_tol(s21_atan(-1), atan(-1), 1e-06);
} END_TEST

START_TEST(thirteen) {
    ck_assert_double_eq_tol(s21_atan(13), atan(13), 1e-06);
} END_TEST

START_TEST(hundred) {
    ck_assert_double_eq_tol(s21_atan(100), atan(100), 1e-06);
} END_TEST

START_TEST(negative_zero) {
    ck_assert_double_eq_tol(s21_atan(-0), atan(-0), 1e-06);
} END_TEST

START_TEST(negative_ten) {
    ck_assert_double_eq_tol(s21_atan(-10), atan(-10), 1e-06);
} END_TEST

START_TEST(negative_thirteen) {
    ck_assert_double_eq_tol(s21_atan(-13), atan(-13), 1e-06);
} END_TEST

START_TEST(negative_hundred) {
    ck_assert_double_eq_tol(s21_atan(-100), atan(-100), 1e-06);
} END_TEST

START_TEST(negative_hundred_half) {
    ck_assert_double_eq_tol(s21_atan(-100.55), atan(-100.55), 1e-06);
} END_TEST

START_TEST(half) {
    ck_assert_double_eq_tol(s21_atan(0.55), atan(0.55), 1e-06);
} END_TEST

START_TEST(negative_half) {
    ck_assert_double_eq_tol(s21_atan(-0.55), atan(-0.55), 1e-06);
} END_TEST

/* */
START_TEST(atan_1) { ck_assert_float_eq(s21_atan(-15.01), atan(-15.01)); }
END_TEST

START_TEST(atan_2) {
  double num = -0.99;
  long double orig_res = s21_atan(num), our_res = atan(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-06)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(atan_3) {
  ck_assert_float_eq(-9999999999, -9999999999);
}
END_TEST

START_TEST(atan_4) {
  ck_assert_ldouble_eq_tol(s21_atan(INFINITY), atan(INFINITY), 1e-7L);
  ck_assert_ldouble_eq_tol(s21_atan(-INFINITY), atan(-INFINITY), 1e-7L);
}
END_TEST

START_TEST(atan_5) {
  double num = NAN;
  long double orig_res = s21_atan(num), our_res = atan(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(atan_6) {
  ck_assert_ldouble_eq_tol(s21_atan(INFINITY), (M_PI / 2.0), 1e-06);
  ck_assert_ldouble_eq_tol(atan(INFINITY), (M_PI / 2.0), 1e-06);
  ck_assert_ldouble_eq_tol(s21_atan((-INFINITY)), ((M_PI) / -2.0), 1e-06);
  ck_assert_ldouble_eq_tol(atan(-INFINITY), ((M_PI) / -2.0), 1e-06);
}
END_TEST

START_TEST(atan_7) {
  ck_assert_ldouble_nan(s21_atan(NAN));
  ck_assert_ldouble_nan(atan(NAN));
}
END_TEST

START_TEST(atan_8) {
  ck_assert_ldouble_eq_tol(s21_atan(1.0), atan(1.0), 1e-06);
  ck_assert_ldouble_eq_tol(s21_atan(1.1), atan(1.1), 1e-06);
  ck_assert_ldouble_eq_tol(s21_atan(-1.0), atan(-1.0), 1e-06);
  ck_assert_ldouble_eq_tol(s21_atan(-1.1), atan(-1.1), 1e-06);
}
END_TEST

START_TEST(atan_9) {
  ck_assert_ldouble_eq_tol(s21_atan(0.0), atan(0.0), 1e-06);
  ck_assert_ldouble_eq_tol(s21_atan(-0.0), atan(-0.0), 1e-06);
}
END_TEST

START_TEST(atan_10) {
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 1e-06);
}
END_TEST

START_TEST(atan_11) {
  ck_assert_ldouble_eq_tol(s21_atan(-sqrt(3) / 2), atan(-sqrt(3) / 2), 1e-06);
}
END_TEST

START_TEST(atan_12) {
  ck_assert_ldouble_eq_tol(s21_atan(-sqrt(2) / 2), atan(-sqrt(2) / 2), 1e-06);
}
END_TEST

START_TEST(atan_13) {
  ck_assert_ldouble_eq_tol(s21_atan(-1 / 2), atan(-1 / 2), 1e-06);
}
END_TEST

START_TEST(atan_14) {
  ck_assert_ldouble_eq_tol(s21_atan(1 / 2), atan(1 / 2), 1e-06);
}
END_TEST

START_TEST(atan_15) {
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-06);
}
END_TEST

START_TEST(atan_16) {
  ck_assert_ldouble_eq_tol(s21_atan(sqrt(3) / 2), atan(sqrt(3) / 2), 1e-06);
}
END_TEST

START_TEST(atan_17) { ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-06); }
END_TEST

START_TEST(atan_18) {
  ck_assert_ldouble_eq_tol(s21_atan(1.23456e-7), atan(1.23456e-7), 1e-06);
}
END_TEST

START_TEST(atan_19) {
  ck_assert_ldouble_eq_tol(s21_atan(2.1234567), atan(2.1234567), 1e-06);
}
END_TEST

START_TEST(atan_20) {
  ck_assert_ldouble_eq_tol(s21_atan(2.1234567e-7), atan(2.1234567e-7), 1e-06);
}
END_TEST

START_TEST(atan_21) {
  ck_assert_ldouble_eq_tol(s21_atan(2.1234567e-16), atan(2.1234567e-16),
                           6);
}
END_TEST

START_TEST(atan_22) { ck_assert_float_nan(s21_atan(s21_NAN)); }
END_TEST

START_TEST(atan_23) {
  ck_assert_ldouble_eq_tol(s21_atan(s21_PI / 2), atan(s21_PI / 2), 1e-06);
}
END_TEST

START_TEST(atan_24) {
  ck_assert_ldouble_eq_tol(s21_atan(-s21_PI / 2), atan(-s21_PI / 2), 1e-06);
}
END_TEST

void atan_tests(TCase *tc) {
    puts("\033[32m");
    tcase_add_test(tc, zero);
    tcase_add_test(tc, one);
    tcase_add_test(tc, ten);
    tcase_add_test(tc, negative);
    tcase_add_test(tc, thirteen);
    tcase_add_test(tc, hundred);
    tcase_add_test(tc, negative_zero);
    tcase_add_test(tc, negative_ten);
    tcase_add_test(tc, negative_thirteen);
    tcase_add_test(tc, negative_hundred);
    tcase_add_test(tc, negative_hundred_half);
    tcase_add_test(tc, half);
    tcase_add_test(tc, negative_half);
    /* */
    tcase_add_test(tc, atan_1);
    tcase_add_test(tc, atan_2);
    tcase_add_test(tc, atan_3);
    tcase_add_test(tc, atan_4);
    tcase_add_test(tc, atan_5);
    tcase_add_test(tc, atan_6);
    tcase_add_test(tc, atan_7);
    tcase_add_test(tc, atan_8);
    tcase_add_test(tc, atan_9);
    tcase_add_test(tc, atan_10);
    tcase_add_test(tc, atan_11);
    tcase_add_test(tc, atan_12);
    tcase_add_test(tc, atan_13);
    tcase_add_test(tc, atan_14);
    tcase_add_test(tc, atan_15);
    tcase_add_test(tc, atan_16);
    tcase_add_test(tc, atan_17);
    tcase_add_test(tc, atan_18);
    tcase_add_test(tc, atan_19);
    tcase_add_test(tc, atan_20);
    tcase_add_test(tc, atan_21);
    tcase_add_test(tc, atan_22);
    tcase_add_test(tc, atan_23);
    tcase_add_test(tc, atan_24);
    UNUSED_SHIT(atan_tests);
}
