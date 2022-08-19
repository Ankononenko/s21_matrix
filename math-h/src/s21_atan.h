#ifndef SRC_S21_ATAN_H_
#define SRC_S21_ATAN_H_

#include "s21_sin.h"

long double s21_atan(double x);
void s21_set_rad_in_range(double* x);
long double iterate_s21_atan(double x);

#endif // SRC_S21_ATAN_H_