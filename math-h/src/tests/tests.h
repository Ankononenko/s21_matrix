#ifndef SRC_TESTS_TESTS_H_
#define SRC_TESTS_TESTS_H_

#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
#include <check.h>
#include "../s21_math.h"

#include "../s21_types.h"

void abs_tests(TCase *tc);
void pow_tests(TCase *tc);
void sqrt_tests(TCase *tc);
void fabs_tests(TCase *tc);
void fact_tests(TCase *tc);
void exp_tests(TCase *tc);
void sin_tests(TCase *tc);
void cos_tests(TCase *tc);
void tan_tests(TCase *tc);
void log_tests(TCase *tc);
void atan_tests(TCase *tc);
void asin_tests(TCase *tc);
void acos_tests(TCase *tc);
void ceil_tests(TCase *tc);
void floor_tests(TCase *tc);
void fmod_tests(TCase *tc);

#endif  // SRC_TESTS_TESTS_H_
