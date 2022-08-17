#ifndef SRC_S21_SIN_H_
#define SRC_S21_SIN_H_

#include <stdio.h>
#include <math.h>

#define S21_NAN 0.0/0.0
#define S21_PI 3.141592
#define S21_EPSILON 1e-6

enum is_true{
    FALSE,
    TRUE
};

long double s21_sin(const double x);
long double s21_factorial(const int x);

#endif // SRC_S21_SIN_H_
