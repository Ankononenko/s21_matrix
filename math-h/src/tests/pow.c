#include "tests.h"

START_TEST(mpow_1) {
    ck_assert_double_eq(pow(-1, 1), s21_pow(-1, 1));
} END_TEST

START_TEST(min_int) {
    ck_assert_double_eq_tol(pow(INT_MIN, 1), s21_pow(INT_MIN, 1), 1e-06);
} END_TEST

START_TEST(mpow_3) {
    ck_assert_double_eq_tol(pow(-INT_MAX, 1), s21_pow(-INT_MAX, 1), 1e-06);
} END_TEST

START_TEST(mpow_4) {
    ck_assert_double_eq(pow(2, 2), s21_pow(2, 2));
} END_TEST

START_TEST(mpow_5) {
    ck_assert_double_eq_tol(pow(2.2, 2.2), s21_pow(2.2, 2.2), 1e-06);
} END_TEST

START_TEST(mpow_6) {
    ck_assert_double_eq_tol(pow(2, 0.5), s21_pow(2, 0.5), 1e-06);
} END_TEST

START_TEST(mpow_7) {
    ck_assert_ldouble_eq_tol(pow(0.9, 20), s21_pow(0.9, 20), 1e-06);
} END_TEST

START_TEST(mpow_8) {
    ck_assert_double_eq(pow(0.9, -20), s21_pow(0.9, -20));
} END_TEST

START_TEST(hundred_hundred) {
    ck_assert_double_eq(pow(100, 100), s21_pow(100, 100));
} END_TEST

START_TEST(hundred_zero) {
    ck_assert_double_eq(pow(100, 0), s21_pow(100, 0));
} END_TEST

START_TEST(zero_hundred) {
    ck_assert_double_eq(pow(0, 100), s21_pow(0, 100));
} END_TEST

START_TEST(hundred_one) {
    ck_assert_double_eq(pow(100, 1), s21_pow(100, 1));
} END_TEST

START_TEST(one_hundred) {
    ck_assert_double_eq(pow(1, 100), s21_pow(1, 100));
} END_TEST

START_TEST(five_hundred) {
    ck_assert_double_eq(pow(13, 501), s21_pow(13, 501));
} END_TEST

START_TEST(real_int) {
    ck_assert_double_eq_tol(pow(87.78, 13), s21_pow(87.78, 13), 1e-06);
} END_TEST

START_TEST(real_real_small) {
    ck_assert_double_eq_tol(pow(0.02, 0.4), s21_pow(0.02, 0.4), 1e-06);
} END_TEST

START_TEST(negative_real) {
  ck_assert_double_nan(s21_pow(-10, 9.1));
} END_TEST

/* */
START_TEST(pow_1) {
  double num = 456.789;
  double ex = 1.1;
  long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  int suc = 0;
  ck_assert_float_eq(our_res, orig_res);
  if ((fabsl(orig_res - our_res) <= 1e-06)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_2) {
  ck_assert_int_eq(s21_pow(s21_INF, 1.1), pow(s21_INF, 1.1));
}
END_TEST

START_TEST(pow_3) {
  long double orig_res = pow(NAN, 1.1), our_res = s21_pow(NAN, 1.1);
  int suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_4) {
  double num = NAN;
  double ex = NAN;
  long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  int suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_5) {
  double num = 0.001;
  double ex = NAN;
  long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  int suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_6) {
  ck_assert_double_eq(pow(s21_INF, s21_INF), s21_pow(s21_INF, s21_INF));
}
END_TEST

START_TEST(pow_8) {
  long double base = -16.161435;
  long double exp = 9.;
  ck_assert_float_eq_tol(s21_pow(-16.161435, 9.), pow(base, exp), 1e-06);
}
END_TEST

START_TEST(pow_9) {
  ck_assert_double_nan(s21_pow(-10.1261, -0.72));
  ck_assert_double_nan(pow(-10.1261, -0.72));
}
END_TEST

START_TEST(pow_10) {
  long double base = +0;
  long double exp = -0.33;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_12) {
  long double base = -0;
  long double exp = -0.33;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_13) {
  ck_assert_ldouble_eq_tol(s21_pow(-0, s21_INF), pow(-0, s21_INF), 1e-06);
}
END_TEST

START_TEST(pow_14) {
  long double base = +0;
  long double exp = 123;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-06);
}
END_TEST

START_TEST(pow_15) {
  long double base = -0;
  long double exp = 123;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-06);
}
END_TEST

START_TEST(pow_16) {
  long double base = -0;
  long double exp = s21_INF;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-06);
}
END_TEST

START_TEST(pow_17) {
    ck_assert_ldouble_infinite(s21_pow(-s21_INF, s21_INF));
}
END_TEST

START_TEST(pow_18) {
  long double base = -1;
  long double exp = s21_NAN;
  ck_assert_double_nan(pow(base, exp));
  ck_assert_double_nan(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_19) {
  ck_assert_ldouble_eq_tol(s21_pow(NAN, 0), pow(NAN, 0), 1e-06);
}
END_TEST

START_TEST(pow_20) {
  long double base = -123;
  long double exp = s21_NAN;
  ck_assert_double_nan(s21_pow(base, exp));
  ck_assert_double_nan(pow(base, exp));
}
END_TEST

START_TEST(pow_21) {
  ck_assert_ldouble_infinite(pow(0.5591951, -s21_INF));
  ck_assert_ldouble_infinite(s21_pow(0.5591951, -s21_INF));
}
END_TEST

START_TEST(pow_22) {
  long double base = 1.5591951;
  long double exp = -s21_INF;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-06);
}
END_TEST

START_TEST(pow_23) {
  long double base = 0.5591951;
  long double exp = s21_INF;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-06);
}
END_TEST

START_TEST(pow_24) {
  long double base = 1.5591951;
  long double exp = s21_INF;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_25) {
  long double base = -s21_INF;
  long double exp = -193491;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-06);
}
END_TEST

START_TEST(pow_26) {
  long double base = -s21_INF;
  long double exp = -142;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-06);
}
END_TEST

START_TEST(pow_27) {
  long double base = -s21_INF;
  long double exp = 141;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_28) {
  long double base = -s21_INF;
  long double exp = 142;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_29) {
  long double base = s21_INF;
  long double exp = -1;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-06);
}
END_TEST

START_TEST(pow_30) {
  long double base = s21_INF;
  long double exp = 1;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_31) {
  ck_assert_ldouble_eq_tol(s21_pow(0.0, 0.0), pow(0.0, 0.0), 1e-06);
}
END_TEST

START_TEST(pow_32) {
  ck_assert_ldouble_eq_tol(s21_pow(-1, 4), pow(-1, 4), 1e-06);
}
END_TEST

START_TEST(pow_33) {
  ck_assert_ldouble_eq_tol(s21_pow(2, 18), pow(2, 18), 1e-06);
}
END_TEST

START_TEST(pow_34) {
  ck_assert_ldouble_eq_tol(s21_pow(2.1, 11), pow(2.1, 11), 1e-06);
}
END_TEST

START_TEST(pow_35) {
  ck_assert_ldouble_eq_tol(s21_pow(1.23456e-7, 2.21), pow(1.23456e-7, 2.21),
                           1e-06);
}
END_TEST

START_TEST(pow_36) {
  ck_assert_ldouble_eq_tol(s21_pow(2.1234567, -2), pow(2.1234567, -2), 1e-06);
}
END_TEST

START_TEST(pow_37) {
  ck_assert_ldouble_eq_tol(s21_pow(2.1234567, -2), pow(2.1234567, -2), 1e-06);
}
END_TEST

START_TEST(pow_38) {
  long double orig_res = pow(2.1234567e-7, -2.45e4),
              our_res = s21_pow(2.1234567e-7, -2.45e4);
  int suc = 0;
  if (isinf(our_res) && isinf(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_39) {
  ck_assert_ldouble_eq_tol(s21_pow(9.99999999e3, 9.95e-4),
                           pow(9.99999999e3, 9.95e-4), 1e-06);
}
END_TEST

START_TEST(pow_40) {
  ck_assert_ldouble_infinite(s21_pow(+0, -12));
}
END_TEST

START_TEST(pow_41) {
  ck_assert_ldouble_infinite(s21_pow(-0, -12));
}
END_TEST

START_TEST(pow_42) {
  ck_assert_ldouble_eq_tol(s21_pow(-0, 0), pow(-0, 0), 1e-06);
}
END_TEST

START_TEST(pow_43) {
  ck_assert_double_nan(s21_pow(+0, s21_NAN));
  ck_assert_double_nan(pow(+0, s21_NAN));
}
END_TEST

START_TEST(pow_44) {
  ck_assert_ldouble_eq_tol(s21_pow(+0, 2.456), pow(+0, 2.456), 1e-06);
}
END_TEST

START_TEST(pow_45) {
  ck_assert_ldouble_infinite(s21_pow(+0, -s21_INF));
  ck_assert_ldouble_infinite(pow(+0, -s21_INF));
}
END_TEST

START_TEST(pow_46) {
  ck_assert_ldouble_eq_tol(s21_pow(+0, 56), pow(+0, 56), 1e-06);
}
END_TEST

START_TEST(pow_47) {
  ck_assert_ldouble_eq_tol(s21_pow(-0, 56), pow(-0, 56), 1e-06);
}
END_TEST

START_TEST(pow_48) {
  ck_assert_ldouble_eq_tol(s21_pow(-0, 56.345), pow(-0, 56.345), 1e-06);
}
END_TEST

START_TEST(pow_49) {
  ck_assert_ldouble_eq_tol(s21_pow(-1, s21_INF), pow(-1, s21_INF), 1e-06);
}
END_TEST

START_TEST(pow_50) {
  ck_assert_ldouble_eq_tol(s21_pow(-1, s21_INF), pow(-1, s21_INF), 1e-06);
}
END_TEST

START_TEST(pow_51) {
  ck_assert_ldouble_eq_tol(s21_pow(+1, s21_NAN), pow(+1, s21_NAN), 1e-06);
}
END_TEST

START_TEST(pow_52) {
  ck_assert_ldouble_eq_tol(s21_pow(4567, -0), pow(4567, -0), 1e-06);
}
END_TEST

START_TEST(pow_53) {
  ck_assert_ldouble_eq_tol(s21_pow(34567, 0), pow(34567, 0), 1e-06);
}
END_TEST

START_TEST(pow_54) {
  ck_assert_ldouble_eq_tol(s21_pow(s21_NAN, -0), pow(s21_NAN, -0), 1e-06);
}
END_TEST

START_TEST(pow_55) {
  ck_assert_ldouble_eq_tol(s21_pow(s21_NAN, 0), pow(s21_NAN, 0), 1e-06);
}
END_TEST

START_TEST(pow_56) {
  ck_assert_double_nan(s21_pow(s21_NAN, s21_NAN));
  ck_assert_double_nan(pow(s21_NAN, s21_NAN));
}
END_TEST

START_TEST(pow_57) {
  ck_assert_ldouble_infinite(s21_pow(s21_INF, s21_INF));
  ck_assert_ldouble_infinite(pow(s21_INF, s21_INF));
}
END_TEST

START_TEST(pow_58) {
  ck_assert_ldouble_eq_tol(s21_pow(-s21_INF, -s21_INF), pow(-s21_INF, -s21_INF), 1e-06);
}
END_TEST

START_TEST(pow_59) {
  ck_assert_ldouble_infinite(s21_pow(-s21_INF, s21_INF));
  ck_assert_ldouble_infinite(pow(-s21_INF, s21_INF));
}
END_TEST

START_TEST(pow_60) {
  double exp = 0;
  double res1 = 0;
  long double res2 = 0;

  for (exp = 0.0; exp > -1000; exp -= 0.1) {
    res1 = pow(s21_INF, exp);
    res2 = s21_pow(s21_INF, exp);
  }
  ck_assert_ldouble_eq_tol(res1, res2, 1e-06);
}
END_TEST

START_TEST(pow_61) {
  double base = 0;
  double res1 = 0;
  long double res2 = 0;

  for (base = 0.0; base < 10; base += 0.1) {
    res1 = pow(base, s21_INF);
    res2 = s21_pow(base, s21_INF);
  }
  ck_assert_ldouble_infinite(res1);
  ck_assert_ldouble_infinite(res2);
}
END_TEST

START_TEST(pow_62) {
  double base = 0;
  double res1 = 0;
  long double res2 = 0;

  for (base = 0.0; base > -10; base -= 0.1) {
    res1 = pow(base, s21_INF);
    res2 = s21_pow(base, s21_INF);
  }
  ck_assert_ldouble_infinite(res1);
  ck_assert_ldouble_infinite(res2);
}
END_TEST

START_TEST(pow_63) {
  long double base = 0;
  long double res1 = 0;
  long double res2 = 0;

  for (base = 0.0; base < 10; base += 0.1) {
    res1 = pow(base, -s21_INF);
    res2 = s21_pow(base, -s21_INF);
  }
  ck_assert_ldouble_eq_tol(res1, res2, 1e-06);
}
END_TEST

START_TEST(pow_64) {
  long double base = 0;
  long double res1 = 0;
  long double res2 = 0;

  for (base = 0.0; base > -10; base -= 0.1) {
    res1 = pow(base, -s21_INF);
    res2 = s21_pow(base, -s21_INF);
  }
  ck_assert_ldouble_eq_tol(res1, res2, 1e-06);
}
END_TEST

START_TEST(pow_65) {
  double exp = 0;
  double res1 = 0;
  long double res2 = 0;

  for (exp = 0.0; exp > -10; exp -= 0.1) {
    if (fmod(exp, 2) != 0) {
      res1 = pow(-s21_INF, exp);
      res2 = s21_pow(-s21_INF, exp);
    }
  }
  ck_assert_ldouble_eq_tol(res1, res2, 1e-06);
}
END_TEST

START_TEST(pow_66) {
  double exp = 0;
  double res1 = 0;
  long double res2 = 0;

  for (exp = 0.0; exp > -10; exp -= 0.1) {
    if (fmod(exp, 2) == 0) {
      res1 = pow(-s21_INF, exp);
      res2 = s21_pow(-s21_INF, exp);
    }
  }
  ck_assert_ldouble_eq_tol(res1, res2, 1e-06);
}
END_TEST

START_TEST(pow_67) {
  double exp = 0;
  double res1 = 0;
  long double res2 = 0;

  for (exp = 0.0; exp < 10; exp += 0.1) {
    if (fmod(exp, 2) != 0) {
      res1 = pow(-s21_INF, exp);
      res2 = s21_pow(-s21_INF, exp);
    }
  }
  ck_assert_ldouble_infinite(res1);
  ck_assert_ldouble_infinite(res2);
}
END_TEST

START_TEST(pow_68) {
  double exp = 0;
  double res1 = 0;
  long double res2 = 0;

  for (exp = 0.0; exp < 10; exp += 0.1) {
    if (fmod(exp, 2) == 0) {
      res1 = pow(-s21_INF, exp);
      res2 = s21_pow(-s21_INF, exp);
    }
  }
  ck_assert_ldouble_eq_tol(res2, res1, 1e-06);
}
END_TEST

START_TEST(pow_69) {
  long double exp = 3;
  ck_assert_ldouble_eq_tol(s21_pow(-3, exp), pow(-3, exp), 1e-06);
}
END_TEST

START_TEST(pow_70) {
  long double exp = -3;
  ck_assert_ldouble_eq_tol(s21_pow(-3, exp), pow(-3, exp), 1e-06);
}
END_TEST

START_TEST(pow_71) {
  long double exp = -3;
  ck_assert_ldouble_eq_tol(s21_pow(3, exp), pow(3, exp), 1e-06);
}
END_TEST

START_TEST(pow_72) {
  long double exp = 3;
  ck_assert_ldouble_eq_tol(s21_pow(3, exp), pow(3, exp), 1e-06);
}
END_TEST

START_TEST(pow_73) {
  long double base = -0;
  long double exp = s21_INF;
  long double res = pow(base, exp);
  long double res1 = s21_pow(base, exp);
  ck_assert_ldouble_eq_tol(res, res1, 1e-06);
}
END_TEST

START_TEST(pow_74) {
  long double exp = 0;
  long double base = -0;
  long double res = 0;
  long double res1 = 0;
  for (exp = 0.0; exp < 10; exp += 0.1) {
    if (fmod(exp, 2) != 0) {
      res = pow(base, exp);
      res1 = s21_pow(base, exp);
    }
  }
  ck_assert_ldouble_eq_tol(res, res1, 1e-06);
}
END_TEST

void pow_tests(TCase *tc) {
    tcase_add_test(tc, mpow_1);
    tcase_add_test(tc, min_int);
    tcase_add_test(tc, mpow_3);
    tcase_add_test(tc, mpow_4);
    tcase_add_test(tc, mpow_5);
    tcase_add_test(tc, mpow_6);
    tcase_add_test(tc, mpow_7);
    tcase_add_test(tc, mpow_8);
    tcase_add_test(tc, hundred_hundred);
    tcase_add_test(tc, hundred_zero);
    tcase_add_test(tc, zero_hundred);
    tcase_add_test(tc, hundred_one);
    tcase_add_test(tc, one_hundred);
    tcase_add_test(tc, five_hundred);
    tcase_add_test(tc, real_int);
    tcase_add_test(tc, real_real_small);
    tcase_add_test(tc, negative_real);
    /* */
    tcase_add_test(tc, pow_1);
    tcase_add_test(tc, pow_2);
    tcase_add_test(tc, pow_3);
    tcase_add_test(tc, pow_4);
    tcase_add_test(tc, pow_5);
    tcase_add_test(tc, pow_6);
    tcase_add_test(tc, pow_8);
    tcase_add_test(tc, pow_9);
    tcase_add_test(tc, pow_10);
    tcase_add_test(tc, pow_12);
    tcase_add_test(tc, pow_13);
    tcase_add_test(tc, pow_14);
    tcase_add_test(tc, pow_15);
    tcase_add_test(tc, pow_16);
    tcase_add_test(tc, pow_17);
    tcase_add_test(tc, pow_18);
    tcase_add_test(tc, pow_19);
    tcase_add_test(tc, pow_20);
    tcase_add_test(tc, pow_21);
    tcase_add_test(tc, pow_22);
    tcase_add_test(tc, pow_23);
    tcase_add_test(tc, pow_24);
    tcase_add_test(tc, pow_25);
    tcase_add_test(tc, pow_26);
    tcase_add_test(tc, pow_27);
    tcase_add_test(tc, pow_28);
    tcase_add_test(tc, pow_29);
    tcase_add_test(tc, pow_30);
    tcase_add_test(tc, pow_31);
    tcase_add_test(tc, pow_32);
    tcase_add_test(tc, pow_33);
    tcase_add_test(tc, pow_34);
    tcase_add_test(tc, pow_35);
    tcase_add_test(tc, pow_36);
    tcase_add_test(tc, pow_37);
    tcase_add_test(tc, pow_38);
    tcase_add_test(tc, pow_39);
    tcase_add_test(tc, pow_40);
    tcase_add_test(tc, pow_41);
    tcase_add_test(tc, pow_42);
    tcase_add_test(tc, pow_43);
    tcase_add_test(tc, pow_44);
    tcase_add_test(tc, pow_45);
    tcase_add_test(tc, pow_46);
    tcase_add_test(tc, pow_47);
    tcase_add_test(tc, pow_48);
    tcase_add_test(tc, pow_49);
    tcase_add_test(tc, pow_50);
    tcase_add_test(tc, pow_51);
    tcase_add_test(tc, pow_52);
    tcase_add_test(tc, pow_53);
    tcase_add_test(tc, pow_54);
    tcase_add_test(tc, pow_55);
    tcase_add_test(tc, pow_56);
    tcase_add_test(tc, pow_57);
    tcase_add_test(tc, pow_58);
    tcase_add_test(tc, pow_59);
    tcase_add_test(tc, pow_60);
    tcase_add_test(tc, pow_61);
    tcase_add_test(tc, pow_62);
    tcase_add_test(tc, pow_63);
    tcase_add_test(tc, pow_64);
    tcase_add_test(tc, pow_65);
    tcase_add_test(tc, pow_66);
    tcase_add_test(tc, pow_67);
    tcase_add_test(tc, pow_68);
    tcase_add_test(tc, pow_69);
    tcase_add_test(tc, pow_70);
    tcase_add_test(tc, pow_71);
    tcase_add_test(tc, pow_72);
    tcase_add_test(tc, pow_73);
    tcase_add_test(tc, pow_74);
}
