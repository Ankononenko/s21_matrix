#ifndef SRC_S21_SIN_H_
#define SRC_S21_SIN_H_

#include <stdio.h>
// Math should be removed later when the testing is completed
#include <math.h>
#include "s21_factorial.h"

#define S21_NAN 0.0/0.0
#define S21_PI 3.141592
#define S21_EPSILON 1e-6
#define S21_EPSILON_7 1e-7

enum is_true{
    FALSE,
    TRUE
};

long double s21_sin(const double x);

#endif // SRC_S21_SIN_H_
