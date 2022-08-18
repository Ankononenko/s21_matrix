// Copyright 2022 finchren

#include "s21_cos.h"
#include "s21_factorial.c"

int main() {

    printf("s21: Zero cos = %Lf \n", s21_cos(0));
    printf("Original: Zero cos = %f \n", cos(0));

    printf("s21: One cos = %Lf \n", s21_cos(1));
    printf("Original: One cos = %f \n", cos(1));

    printf("s21: Ten cos = %Lf \n", s21_cos(10));
    printf("Original: Ten cos = %f \n", cos(10));

    return 0;
}

long double s21_cos(const double x) {
    long double sum = 0.0;
    if (__builtin_isnan(x) || __builtin_isinf(x)) {
        sum = S21_NAN;
    }
    int index = 0, should_run = TRUE;
    // Run the while loop while the cos is bigger than the 1e-6 precision
    while (should_run) {
        double cos = 0.0;
        cos = pow(-1, index) / s21_factorial(2 * index) * pow(x, 2 * index);
        sum += cos;
        ++index;
        // fabs() should be replaced by s21 function when completed
        should_run = fabs(cos) > S21_EPSILON;
    }
    return sum;
}
