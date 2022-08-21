#include "tests.h"

START_TEST(zero) {
    ck_assert_double_eq_tol(s21_acos(0), acos(0), 1e-06);
} END_TEST

START_TEST(one) {
    ck_assert_double_eq(s21_acos(1), acos(1));
} END_TEST

START_TEST(ten) {
    ck_assert_double_nan(s21_acos(10));
} END_TEST

START_TEST(negative) {
    ck_assert_double_eq_tol(s21_acos(-1), acos(-1), 1e-06);
} END_TEST

START_TEST(negative_zero) {
    ck_assert_double_eq_tol(s21_acos(-0), acos(-0), 1e-06);
} END_TEST

START_TEST(negative_ten) {
    ck_assert_double_nan(s21_acos(-10));
} END_TEST

START_TEST(half) {
    ck_assert_double_eq_tol(s21_acos(0.55), acos(0.55), 1e-06);
} END_TEST

START_TEST(negative_half) {
    ck_assert_double_eq_tol(s21_acos(-0.55), acos(-0.55), 1e-06);
} END_TEST

/* */
START_TEST(acos_1) {
  double num = 0.55;
  long double orig_res = acos(num), our_res = s21_acos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-06)) suc = 1;
  ck_assert_int_eq(1, suc);
} END_TEST


START_TEST(acos_2) {
  double num = -0.99;
  long double orig_res = acos(num), our_res = s21_acos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-06)) suc = 1;
  ck_assert_int_eq(1, suc);
} END_TEST

START_TEST(acos_3) {
  double num = -9;
  ck_assert_double_nan(s21_acos(num));
} END_TEST

START_TEST(acos_4) {
  double num = INFINITY;
  long double orig_res = acos(num), our_res = s21_acos(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
} END_TEST

START_TEST(acos_5) {
  double num = -INFINITY;
  long double orig_res = acos(num), our_res = s21_acos(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
} END_TEST

START_TEST(acos_6) {
  double num = NAN;
  long double orig_res = s21_acos(num), our_res = acos(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
} END_TEST

START_TEST(acos_7) {
    ck_assert_ldouble_nan(s21_acos(NAN));
    ck_assert_ldouble_nan(acos(NAN));
} END_TEST

START_TEST(acos_8) {
    ck_assert_ldouble_nan(s21_acos(NAN));
    ck_assert_ldouble_nan(acos(NAN));
} END_TEST

START_TEST(acos_9) {
    ck_assert_ldouble_eq_tol(s21_acos(1.0), acos(1.0), 1e-06);
    ck_assert_ldouble_eq_tol(s21_acos(-1.0), acos(-1.0), 1e-06);
} END_TEST

START_TEST(acos_10) {
    ck_assert_ldouble_eq_tol(s21_acos(0.0), acos(0.0), 1e-06);
    ck_assert_ldouble_eq_tol(s21_acos(-0.0), acos(-0.0), 1e-06);
} END_TEST

START_TEST(acos_11) {
    ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), 1e-06);
} END_TEST

START_TEST(acos_12) {
    ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-06);
} END_TEST

START_TEST(acos_13) {
    ck_assert_ldouble_eq_tol(s21_acos(-sqrt(3) / 2), acos(-sqrt(3) / 2), 1e-06);
} END_TEST

START_TEST(acos_14) {
    ck_assert_ldouble_eq_tol(s21_acos(-s21_SQRT2 / 2), acos(-s21_SQRT2 / 2), 1e-06);
} END_TEST

START_TEST(acos_15) {
    ck_assert_ldouble_eq_tol(s21_acos(-1 / 2), acos(-1 / 2), 1e-06);
} END_TEST

START_TEST(acos_16) {
    ck_assert_ldouble_eq_tol(s21_acos(1 / 2), acos(1 / 2), 1e-06);
} END_TEST

START_TEST(acos_17) {
    ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-06);
} END_TEST

START_TEST(acos_18) {
    ck_assert_ldouble_eq_tol(s21_acos(s21_SQRT2 / 2), acos(s21_SQRT2 / 2), 1e-06);
} END_TEST

START_TEST(acos_19) {
    ck_assert_ldouble_eq_tol(s21_acos(sqrt(3) / 2), acos(sqrt(3) / 2), 1e-06);
} END_TEST

void acos_tests(TCase *tc) {
    tcase_add_test(tc, zero);
    tcase_add_test(tc, one);
    tcase_add_test(tc, ten);
    tcase_add_test(tc, negative);
    tcase_add_test(tc, negative_zero);
    tcase_add_test(tc, negative_ten);
    tcase_add_test(tc, half);
    tcase_add_test(tc, negative_half);
/* */
    tcase_add_test(tc, acos_1);
    tcase_add_test(tc, acos_2);
    tcase_add_test(tc, acos_3);
    tcase_add_test(tc, acos_4);
    tcase_add_test(tc, acos_5);
    tcase_add_test(tc, acos_6);
    tcase_add_test(tc, acos_7);
    tcase_add_test(tc, acos_8);
    tcase_add_test(tc, acos_9);
    tcase_add_test(tc, acos_10);
    tcase_add_test(tc, acos_11);
    tcase_add_test(tc, acos_12);
    tcase_add_test(tc, acos_13);
    tcase_add_test(tc, acos_14);
    tcase_add_test(tc, acos_15);
    tcase_add_test(tc, acos_16);
    tcase_add_test(tc, acos_17);
    tcase_add_test(tc, acos_18);
    tcase_add_test(tc, acos_19);
    UNUSED_SHIT(acos_tests);
}
