// Copyright 2022 finchren

#include "s21_sin.h"

int main() {
    printf("s21: Zero sin = %Lf \n", s21_sin(0));
    printf("Original: Zero sin = %f \n", sin(0));

    printf("s21: One sin = %Lf \n", s21_sin(1));
    printf("Original: One sin = %f \n", sin(1));

    printf("s21: Ten sin = %Lf \n", s21_sin(10));
    printf("Original: Ten sin = %f \n", sin(10));

    return 0;
}

long double s21_sin(const double x) {
    long double sum = 0.0;
    if (__builtin_isnan(x) || __builtin_isinf(x)) {
        sum = S21_NAN;
    }
    int index = 0, should_run = TRUE;
    // Run the while loop while the sin is bigger than the 1e-6 precision
    while (should_run) {
        double sin = 0.0;
        sin = pow(-1, index) / s21_factorial(1 + 2 * index) * pow(x, 1 + 2 * index);
        sum += sin;
        ++index;
        should_run = fabs(sin) > S21_EPSILON;
    }
    return sum;
}

// Unsigned long double to be able to work with the maximum needed numbers
// Until the epsilon for the precision is reached
long double s21_factorial(const int x) {
    long double result = 1.0L;
    for (int index = 1; index <= x; ++index) {
        result *= index;
    }
    return result;
}