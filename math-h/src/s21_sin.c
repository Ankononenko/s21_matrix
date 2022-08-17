// Copyright 2022 finchren

#include "s21_sin.h"

int main() {

    return 0;
}

long double s21_sin(double x) {
    long double sum = 0.0;
    if (__builtin_isnan(x) || __builtin_isinf(x)) {
        sum = NAN;
    }
    for (int index = 0; index < 500; ++index) {
        sum += pow(-1, index) * pow(x, 1 + 2 * index) / s21_factorial(1 + 2 * index);
    }
    return sum;
}

long double s21_factorial(double x) {
    
}