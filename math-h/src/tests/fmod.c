#include "tests.h"

START_TEST(fmod_1) {
    ck_assert_double_eq(fmod(-1, 1), s21_fmod(-1, 1));
} END_TEST

START_TEST(min_int) {
    ck_assert_double_eq(fmod(INT_MIN, 1), s21_fmod(INT_MIN, 1));
} END_TEST

START_TEST(fmod_3) {
    ck_assert_double_eq(fmod(-INT_MAX, 1), s21_fmod(-INT_MAX, 1));
} END_TEST

START_TEST(fmod_4) {
    ck_assert_double_eq(fmod(20000, 92), s21_fmod(20000, 92));
} END_TEST

START_TEST(fmod_5) {
    ck_assert_double_eq(fmod(82.72, 42.28), s21_fmod(82.72, 42.28));
} END_TEST

START_TEST(fmod_6) {
    ck_assert_double_eq_tol(fmod(2, 0.5), s21_fmod(2, 0.5), 1e-06);
} END_TEST

START_TEST(fmod_7) {
    ck_assert_ldouble_eq(fmod(0.9, 20), s21_fmod(0.9, 20));
} END_TEST

START_TEST(fmod_8) {
    ck_assert_double_eq(fmod(0.9, -20), s21_fmod(0.9, -20));
} END_TEST

START_TEST(hundred_hundred) {
    ck_assert_double_eq(fmod(100, 100), s21_fmod(100, 100));
} END_TEST

START_TEST(hundred_zero) {
    ck_assert_double_nan(s21_fmod(100, 0));
} END_TEST

START_TEST(zero_hundred) {
    ck_assert_double_eq(fmod(0, 100), s21_fmod(0, 100));
} END_TEST

START_TEST(hundred_one) {
    ck_assert_double_eq(fmod(100, 1), s21_fmod(100, 1));
} END_TEST

START_TEST(one_hundred) {
    ck_assert_double_eq(fmod(1, 100), s21_fmod(1, 100));
} END_TEST

START_TEST(five_hundred) {
    ck_assert_double_eq(fmod(13, 501), s21_fmod(13, 501));
} END_TEST

START_TEST(real_int) {
    ck_assert_double_eq(fmod(87.78, 13), s21_fmod(87.78, 13));
} END_TEST

START_TEST(real_real_small) {
    ck_assert_double_eq(fmod(0.02, 0.4), s21_fmod(0.02, 0.4));
} END_TEST

START_TEST(infin) {
    ck_assert_double_eq(fmod(0.02, s21_INF), s21_fmod(0.02, s21_INF));
} END_TEST

/* */
START_TEST(s21_fmod_test_1) {
  ck_assert_ldouble_eq(s21_fmod(2.34, 2.0), fmod(2.34, 2.0));
}
END_TEST

START_TEST(s21_fmod_test_2) {
  ck_assert_ldouble_eq(s21_fmod(-2.34, 2.0), fmod(-2.34, 2.0));
}
END_TEST

START_TEST(s21_fmod_test_3) {
  ck_assert_ldouble_eq(s21_fmod(2.34, -2.0), fmod(2.34, -2.0));
}
END_TEST

START_TEST(s21_fmod_test_4) {
  ck_assert_ldouble_eq(s21_fmod(-2.34, -2.0), fmod(-2.34, -2.0));
}
END_TEST

START_TEST(s21_fmod_test_5) {
  ck_assert_ldouble_eq(s21_fmod(21.21, 3), fmod(21.21, 3));
}
END_TEST

START_TEST(s21_fmod_test_6) {
  ck_assert_ldouble_eq(s21_fmod(3, 21.21), fmod(3, 21.21));
}
END_TEST

START_TEST(s21_fmod_test_7) {
  ck_assert_ldouble_eq(s21_fmod(-21.21, 3), fmod(-21.21, 3));
}
END_TEST

START_TEST(s21_fmod_test_8) {
  ck_assert_ldouble_eq(s21_fmod(3, -21.21), fmod(3, -21.21));
}
END_TEST

START_TEST(s21_fmod_test_9) {
  ck_assert_ldouble_eq(s21_fmod(100500, 9), fmod(100500, 9));
}
END_TEST

START_TEST(s21_fmod_test_10) {
  ck_assert_ldouble_eq(s21_fmod(-100500, -9), fmod(-100500, -9));
}
END_TEST

START_TEST(s21_fmod_test_11) {
  ck_assert_ldouble_eq(s21_fmod(-9, -100500), fmod(-9, -100500));
}
END_TEST

START_TEST(s21_fmod_test_12) {
  ck_assert_ldouble_eq(s21_fmod(-9, -9), fmod(-9, -9));
}
END_TEST

START_TEST(s21_fmod_test_13) {
  ck_assert_ldouble_eq(s21_fmod(10, 5), fmod(10, 5));
}
END_TEST

START_TEST(s21_fmod_test_14) {
  ck_assert_ldouble_nan(s21_fmod(INFINITY, INFINITY));
  ck_assert_ldouble_nan(fmod(INFINITY, INFINITY));
}
END_TEST

START_TEST(s21_fmod_test_15) {
  ck_assert_ldouble_nan(s21_fmod(NAN, NAN));
  ck_assert_ldouble_nan(fmod(NAN, NAN));
}
END_TEST

START_TEST(s21_fmod_test_16) {
  ck_assert_ldouble_nan(s21_fmod(2.45, 0));
}
END_TEST

START_TEST(s21_fmod_test_17) {
  ck_assert_ldouble_nan(s21_fmod(0, 0));
}
END_TEST

START_TEST(s21_fmod_test_18) {
  ck_assert_ldouble_nan(s21_fmod(INFINITY, 0));
}
END_TEST

START_TEST(s21_fmod_test_19) {
  double num = NAN;
  long double orig_res = fmod(num, 2.0), our_res = s21_fmod(num, 2.0);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_fmod_test_20) {
  double num = NAN;
  long double orig_res = fmod(2.0, num), our_res = s21_fmod(2.0, num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_fmod_test_21) {
  ck_assert_ldouble_eq(s21_fmod(2.0, INFINITY), fmod(2.0, INFINITY));
}
END_TEST

START_TEST(s21_fmod_test_22) {
  double num = INFINITY;
  long double orig_res = fmod(num, 2.0), our_res = s21_fmod(num, 2.0);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_fmod_test_23) {
  ck_assert_ldouble_eq(s21_fmod(2.0, INFINITY), fmod(2.0, INFINITY));
}
END_TEST

START_TEST(s21_fmod_test_24) {
  ck_assert_ldouble_eq(s21_fmod(2.0, -INFINITY), fmod(2.0, -INFINITY));
}
END_TEST

START_TEST(s21_fmod_test_25) {
  double num = -INFINITY;
  long double orig_res = fmod(num, 2.0), our_res = s21_fmod(num, 2.0);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_fmod_test_26) {
  ck_assert_ldouble_nan(s21_fmod(s21_INF, s21_INF));
  ck_assert_ldouble_nan(fmod(s21_INF, s21_INF));
}
END_TEST

START_TEST(s21_fmod_test_27) {
  ck_assert_ldouble_eq(s21_fmod(0, 23), fmod(0, 23));
}
END_TEST

void fmod_tests(TCase *tc) {
    tcase_add_test(tc, fmod_1);
    tcase_add_test(tc, min_int);
    tcase_add_test(tc, fmod_3);
    tcase_add_test(tc, fmod_4);
    tcase_add_test(tc, fmod_5);
    tcase_add_test(tc, fmod_6);
    tcase_add_test(tc, fmod_7);
    tcase_add_test(tc, fmod_8);
    tcase_add_test(tc, hundred_hundred);
    tcase_add_test(tc, hundred_zero);
    tcase_add_test(tc, zero_hundred);
    tcase_add_test(tc, hundred_one);
    tcase_add_test(tc, one_hundred);
    tcase_add_test(tc, five_hundred);
    tcase_add_test(tc, real_int);
    tcase_add_test(tc, real_real_small);
    tcase_add_test(tc, infin);
    /* */
    tcase_add_test(tc, s21_fmod_test_1);
    tcase_add_test(tc, s21_fmod_test_2);
    tcase_add_test(tc, s21_fmod_test_3);
    tcase_add_test(tc, s21_fmod_test_4);
    tcase_add_test(tc, s21_fmod_test_5);
    tcase_add_test(tc, s21_fmod_test_6);
    tcase_add_test(tc, s21_fmod_test_7);
    tcase_add_test(tc, s21_fmod_test_8);
    tcase_add_test(tc, s21_fmod_test_9);
    tcase_add_test(tc, s21_fmod_test_10);
    tcase_add_test(tc, s21_fmod_test_11);
    tcase_add_test(tc, s21_fmod_test_12);
    tcase_add_test(tc, s21_fmod_test_13);
    tcase_add_test(tc, s21_fmod_test_14);
    tcase_add_test(tc, s21_fmod_test_15);
    tcase_add_test(tc, s21_fmod_test_16);
    tcase_add_test(tc, s21_fmod_test_17);
    tcase_add_test(tc, s21_fmod_test_18);
    tcase_add_test(tc, s21_fmod_test_19);
    tcase_add_test(tc, s21_fmod_test_20);
    tcase_add_test(tc, s21_fmod_test_21);
    tcase_add_test(tc, s21_fmod_test_22);
    tcase_add_test(tc, s21_fmod_test_23);
    tcase_add_test(tc, s21_fmod_test_24);
    tcase_add_test(tc, s21_fmod_test_25);
    tcase_add_test(tc, s21_fmod_test_26);
    tcase_add_test(tc, s21_fmod_test_27);
    UNUSED_SHIT(fmod_tests);
}
