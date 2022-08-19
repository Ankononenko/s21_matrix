// Copyright 2022 finchren

#include "s21_atan.h"
//#include "s21_set_rad_in_range.c"

int main() {
    printf("s21: Zero atan = %Lf \n", s21_atan(0));
    printf("Original: Zero atan = %f \n", atan(0));

    printf("s21: One atan = %Lf \n", s21_atan(1));
    printf("Original: One atan = %f \n", atan(1));

    printf("s21: -9 atan = %Lf \n", s21_atan(-9));
    printf("Original: -9 atan = %f \n", atan(-9));

    printf("s21: -1 atan = %Lf \n", s21_atan(-1));
    printf("Original: -1 atan = %f \n", atan(-1));

    printf("s21: 13 atan = %Lf \n", s21_atan(13));
    printf("Original: 13 atan = %f \n", atan(13));

    // printf("s21: 100 atan = %Lf \n", s21_atan(100));
    // printf("Original: 100 atan = %f \n", atan(100));
    return 0;
}

long double s21_atan(double x) {
    long double sum = 0.0L;
    if (__builtin_isnan(x) || __builtin_isinf(x)) {
        sum = S21_NAN;
    }
    // Set x in range of 1, if it is bigger or less
    if (x > 1.0) {
        sum = 0.5 * S21_PI - iterate_s21_atan(1.0 / x);
    } else if (x < -S21_EPSILON_7) {
        sum = 0.5 * S21_PI - iterate_s21_atan(-1.0 / x);
    } else {
        sum = iterate_s21_atan(x);
    }
    return sum;
}

long double iterate_s21_atan(double x) {
    // s21_set_rad_in_range(&x);
    // Run the while loop while the atan is bigger than the 1e-6 precision
    long double sum = 0.0L;
    int index = 0, should_run = TRUE;
    while (should_run) {
        double atan = 0.0;
        atan = pow(-1, index) / (1 + 2 * index) * pow(x, 1 + 2 * index);
        sum += atan;
        ++index;
        // fabs() should be replaced by s21 function when completed
        should_run = fabs(atan) > S21_EPSILON;
    }
    return sum;
}
