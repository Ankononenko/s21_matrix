#include "tests.h"

START_TEST(zero) {
    ck_assert_double_eq(s21_cos(0), cos(0));
} END_TEST

START_TEST(one) {
    ck_assert_double_eq_tol(s21_cos(1), cos(1), 1e-06);
} END_TEST

START_TEST(ten) {
    ck_assert_double_eq_tol(s21_cos(10), cos(10), 1e-06);
} END_TEST

START_TEST(negative) {
    ck_assert_double_eq_tol(s21_cos(-1), cos(-1), 1e-06);
} END_TEST

START_TEST(thirteen) {
    ck_assert_double_eq_tol(s21_cos(13), cos(13), 1e-06);
} END_TEST

START_TEST(hundred) {
    ck_assert_double_eq_tol(s21_cos(100), cos(100), 1e-06);
} END_TEST

START_TEST(negative_zero) {
    ck_assert_double_eq_tol(s21_cos(-0), cos(-0), 1e-06);
} END_TEST

START_TEST(negative_ten) {
    ck_assert_double_eq_tol(s21_cos(-10), cos(-10), 1e-06);
} END_TEST

START_TEST(negative_thirteen) {
    ck_assert_double_eq_tol(s21_cos(-13), cos(-13), 1e-06);
} END_TEST

START_TEST(negative_hundred) {
    ck_assert_double_eq_tol(s21_cos(-100), cos(-100), 1e-06);
} END_TEST

START_TEST(negative_hundred_half) {
    ck_assert_double_eq_tol(s21_cos(-100.55), cos(-100.55), 1e-06);
} END_TEST

START_TEST(half) {
    ck_assert_double_eq_tol(s21_cos(0.55), cos(0.55), 1e-06);
} END_TEST

START_TEST(negative_half) {
    ck_assert_double_eq_tol(s21_cos(-0.55), cos(-0.55), 1e-06);
} END_TEST

START_TEST(sq2_div_2) {
    ck_assert_ldouble_eq_tol(s21_cos(sqrt(2) / 2), cos(sqrt(2) / 2), 1e-06);
} END_TEST

START_TEST(negative_sq2_div_2) {
    ck_assert_ldouble_eq_tol(s21_cos(-sqrt(2) / 2), cos(-sqrt(2) / 2), 1e-06);
} END_TEST

/* */
START_TEST(cos_1) {
  double num = 0.55;
  long double orig_res = s21_cos(num), our_res = s21_cos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_2) {
  double num = -0.999999;
  long double orig_res = cos(num), our_res = s21_cos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_3) {
  double num = 628;
  long double orig_res = cos(num), our_res = s21_cos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_4) { ck_assert_float_eq(s21_cos(0), cos(0)); }
END_TEST

START_TEST(cos_5) { ck_assert_float_eq(s21_cos(-1), cos(-1)); }
END_TEST

START_TEST(cos_6) {
  double num = NAN;
  long double orig_res = cos(num), our_res = s21_cos(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_7) {
  double num = INFINITY;
  long double orig_res = cos(num), our_res = s21_cos(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_8) {
  double num = -INFINITY;
  long double orig_res = cos(num), our_res = s21_cos(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_9) {
  double x = 0;
  ck_assert_double_eq_tol(s21_cos(x), cosl(x), 1e-06);
}
END_TEST

START_TEST(cos_10) {
  ck_assert_ldouble_nan(s21_cos(-INFINITY));
  ck_assert_ldouble_nan(cosl(-INFINITY));
}
END_TEST

START_TEST(cos_11) {
  ck_assert_ldouble_nan(s21_cos(INFINITY));
  ck_assert_ldouble_nan(cosl(INFINITY));
}
END_TEST

START_TEST(cos_12) {
  ck_assert_ldouble_nan(s21_cos(NAN));
  ck_assert_ldouble_nan(cosl(NAN));
}
END_TEST

START_TEST(cos_13) { ck_assert_double_eq_tol(s21_cos(0.0), cosl(0.0), 1e-06); }
END_TEST

START_TEST(cos_14) {
  ck_assert_double_eq_tol(s21_cos(M_PI / 4), cosl(M_PI / 4), 1e-06);
}
END_TEST

START_TEST(cos_15) {
  ck_assert_double_eq_tol(s21_cos(M_PI / 6), cosl(M_PI / 6), 1e-06);
}
END_TEST

START_TEST(cos_16) {
  ck_assert_double_eq_tol(s21_cos(M_PI / 3), cosl(M_PI / 3), 1e-06);
}
END_TEST

START_TEST(cos_17) {
    ck_assert_double_eq_tol(s21_cos(M_PI / 2), cosl(M_PI / 2), 1e-06);
    ck_assert_double_eq_tol(s21_cos(M_PI / 2), cos(M_PI / 2), 1e-06);
}
END_TEST

START_TEST(cos_18) {
  ck_assert_double_eq_tol(s21_cos(3 * M_PI / 2), cosl(3 * M_PI / 2), 1e-06);
}
END_TEST

START_TEST(cos_19) {
  ck_assert_double_eq_tol(s21_cos(2 * M_PI), cosl(2 * M_PI), 1e-06);
}
END_TEST

START_TEST(cos_20) {
  ck_assert_double_eq_tol(s21_cos(174.532925199433), cosl(174.532925199433),
                          1e-06);
}
END_TEST

START_TEST(cos_21) {
  ck_assert_double_eq_tol(s21_cos(-174.532925199433), cosl(-174.532925199433),
                          1e-06);
}
END_TEST

void cos_tests(TCase *tc) {
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
    tcase_add_test(tc, sq2_div_2);
    tcase_add_test(tc, negative_sq2_div_2);
    /* */
    tcase_add_test(tc, cos_1);
    tcase_add_test(tc, cos_2);
    tcase_add_test(tc, cos_3);
    tcase_add_test(tc, cos_4);
    tcase_add_test(tc, cos_5);
    tcase_add_test(tc, cos_6);
    tcase_add_test(tc, cos_7);
    tcase_add_test(tc, cos_8);
    tcase_add_test(tc, cos_9);
    tcase_add_test(tc, cos_10);
    tcase_add_test(tc, cos_11);
    tcase_add_test(tc, cos_12);
    tcase_add_test(tc, cos_13);
    tcase_add_test(tc, cos_14);
    tcase_add_test(tc, cos_15);
    tcase_add_test(tc, cos_16);
    tcase_add_test(tc, cos_17);
    tcase_add_test(tc, cos_18);
    tcase_add_test(tc, cos_19);
    tcase_add_test(tc, cos_20);
    tcase_add_test(tc, cos_21);
}
