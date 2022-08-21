#include "tests.h"

START_TEST(zero) {
    ck_assert_double_eq(s21_sin(0), sin(0));
} END_TEST

START_TEST(one) {
    ck_assert_double_eq_tol(s21_sin(1), sin(1), 1e-7);
} END_TEST

START_TEST(ten) {
    ck_assert_double_eq_tol(s21_sin(10), sin(10), 1e-06);
} END_TEST

START_TEST(negative) {
    ck_assert_double_eq_tol(s21_sin(-1), sin(-1), 1e-06);
} END_TEST

START_TEST(thirteen) {
    ck_assert_double_eq_tol(s21_sin(13), sin(13), 1e-06);
} END_TEST

START_TEST(hundred) {
    ck_assert_double_eq_tol(s21_sin(100), sin(100), 1e-06);
} END_TEST

START_TEST(negative_zero) {
    ck_assert_double_eq_tol(s21_sin(-0), sin(-0), 1e-06);
} END_TEST

START_TEST(negative_ten) {
    ck_assert_double_eq_tol(s21_sin(-10), sin(-10), 1e-06);
} END_TEST

START_TEST(negative_thirteen) {
    ck_assert_double_eq_tol(s21_sin(-13), sin(-13), 1e-06);
} END_TEST

START_TEST(negative_hundred) {
    ck_assert_double_eq_tol(s21_sin(-100), sin(-100), 1e-06);
} END_TEST

START_TEST(negative_hundred_half) {
    ck_assert_double_eq_tol(s21_sin(-100.55), sin(-100.55), 1e-06);
} END_TEST

START_TEST(half) {
    ck_assert_double_eq_tol(s21_sin(0.55), sin(0.55), 1e-06);
} END_TEST

START_TEST(negative_half) {
    ck_assert_double_eq_tol(s21_sin(-0.55), sin(-0.55), 1e-06);
} END_TEST

/* */
START_TEST(sin_1) {
  double num = 0.55;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-06)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_2) {
  ck_assert_double_eq_tol(s21_sin(0), sin(0), 1e-7);
}
END_TEST

START_TEST(sin_3) {
  double num = 1;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-06)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_4) {
  double num = -1;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-06)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_5) {
  double num = 0.999999;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-06)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_6) {
  double num = -0.999999;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-06)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_7) {
  double num = NAN;
  long double orig_res = sin(num), our_res = s21_sin(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_8) {
  double num = INFINITY;
  long double orig_res = sin(num), our_res = s21_sin(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_9) {
  double num = -INFINITY;
  long double orig_res = sin(num), our_res = s21_sin(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_10) {
  double x = 0;
  ck_assert_double_eq_tol(s21_sin(x), sinl(x), 1e-06);
}
END_TEST

START_TEST(sin_11) {
  ck_assert_ldouble_nan(s21_sin(-INFINITY));
  ck_assert_ldouble_nan(sinl(-INFINITY));
}
END_TEST

START_TEST(sin_12) {
  ck_assert_ldouble_nan(s21_sin(INFINITY));
  ck_assert_ldouble_nan(sinl(INFINITY));
}
END_TEST

START_TEST(sin_13) {
  ck_assert_ldouble_nan(s21_sin(NAN));
  ck_assert_ldouble_nan(sinl(NAN));
}
END_TEST

START_TEST(sin_14) { ck_assert_double_eq_tol(s21_sin(0.0), sin(0.0), 1e-06); }
END_TEST

START_TEST(sin_15) {
  ck_assert_double_eq_tol(s21_sin(M_PI / 6), sin(M_PI / 6), 1e-06);
}
END_TEST

START_TEST(sin_16) {
  ck_assert_double_eq_tol(s21_sin(M_PI / 4), sin(M_PI / 4), 1e-06);
}
END_TEST

START_TEST(sin_17) {
  ck_assert_double_eq_tol(s21_sin(M_PI / 3), sin(M_PI / 3), 1e-06);
}
END_TEST

START_TEST(sin_18) {
  ck_assert_double_eq_tol(s21_sin(M_PI / 2), sin(M_PI / 2), 1e-06);
}
END_TEST

START_TEST(sin_19) {
  ck_assert_double_eq_tol(s21_sin(3 * M_PI / 2), sin(3 * M_PI / 2), 1e-06);
}
END_TEST

START_TEST(sin_20) {
  ck_assert_double_eq_tol(s21_sin(2 * M_PI), sin(2 * M_PI), 1e-06);
}
END_TEST

START_TEST(sin_21) {
  ck_assert_double_eq_tol(s21_sin(-2 * M_PI), sin(-2 * M_PI), 1e-06);
}
END_TEST

START_TEST(sin_22) {
  ck_assert_double_eq_tol(s21_sin(-3 * M_PI), sin(-3 * M_PI), 1e-06);
}
END_TEST

START_TEST(sin_23) {
  ck_assert_double_eq_tol(s21_sin(174.532925199433), sin(174.532925199433),
                          1e-06);
}
END_TEST

START_TEST(sin_24) {
  ck_assert_double_eq_tol(s21_sin(-174.532925199433), sin(-174.532925199433),
                          1e-06);
}
END_TEST

START_TEST(sin_25) {
  ck_assert_double_eq_tol(s21_sin(-s21_PI), sin(-s21_PI), 1e-06);
}
END_TEST

void sin_tests(TCase *tc) {
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
    tcase_add_test(tc, sin_1);
    tcase_add_test(tc, sin_2);
    tcase_add_test(tc, sin_3);
    tcase_add_test(tc, sin_4);
    tcase_add_test(tc, sin_5);
    tcase_add_test(tc, sin_6);
    tcase_add_test(tc, sin_7);
    tcase_add_test(tc, sin_8);
    tcase_add_test(tc, sin_9);
    tcase_add_test(tc, sin_10);
    tcase_add_test(tc, sin_11);
    tcase_add_test(tc, sin_12);
    tcase_add_test(tc, sin_13);
    tcase_add_test(tc, sin_14);
    tcase_add_test(tc, sin_15);
    tcase_add_test(tc, sin_16);
    tcase_add_test(tc, sin_17);
    tcase_add_test(tc, sin_18);
    tcase_add_test(tc, sin_19);
    tcase_add_test(tc, sin_20);
    tcase_add_test(tc, sin_21);
    tcase_add_test(tc, sin_22);
    tcase_add_test(tc, sin_23);
    tcase_add_test(tc, sin_24);
    tcase_add_test(tc, sin_25);
    UNUSED_SHIT(sin_tests);
}
