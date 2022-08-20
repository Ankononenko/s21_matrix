#include <assert.h>

#include "../s21_types.h"
#include "common.h"

const long double g_epsilon = 1e-16L;
const int g_accuracy = 6;

const long double s21_SQRT2 = 1.41421356237L;


int is_plus_zero(double x) {
    return x > 0.0 && s21_are_equal(x, 0.0L, g_epsilon);
}

int is_minus_zero(double x) {
    return x < 0.0 && s21_are_equal(x, 0.0L, g_epsilon);
}

int is_zero(double x) {
    return is_plus_zero(x) || is_minus_zero(x);
}

long double s21_lfabs(long double x) {
    return x > 0.0L ? x : -x;
}

int s21_is_plus_infinity(double x) {
    return x == s21_INF;
}

int s21_is_minus_infinity(double x) {
    return x == -s21_INF;
}

int s21_is_infinity(double x) {
    return s21_is_plus_infinity(x) || s21_is_minus_infinity(x);
}

int s21_is_nan(double x) {
    return (float)x != (float)x;
}

long double s21_factorial(int n) {
    if (n < 0)
        return s21_NAN;

    long double result = 1.0L;
    for (int i = 1; i <= n; ++i)
        result *= i;
    return result;
}


int s21_are_equal(long double a, long double b, long double epsilon) {
    assert(epsilon > 0.0L);
    return a > b ? (a - b < epsilon) : (b - a < epsilon);
}

int s21_are_not_equal(long double a, long double b, long double epsilon) {
    return !s21_are_equal(a, b, epsilon);
}

long double s21_power_integer_exponent(long double base, long long int exponent) {
    if (exponent == 0)
        return 1.0L;

    if (exponent % 2)
        return base * s21_power_integer_exponent(base * base, (exponent - 1) / 2);
    else
        return base * s21_power_integer_exponent(base, exponent - 1);
}

static int initial_found(long double approximation, long double power, int exponent) {
    return s21_power_integer_exponent(approximation, exponent) < power &&
           power < s21_power_integer_exponent(approximation + 1, exponent);
}

static long double get_initial_result(long double base, int exponent) {
    long double result = 0.0L;

    long double left = 0.0L;
    long double right = base;

    while (1) {
        const long double middle = left + (right - left) / 2.0L;

        if (initial_found(middle, base, exponent) ||
        s21_are_equal(s21_power_integer_exponent(middle, exponent), base, g_epsilon)) {
            return middle;
        }
        if (s21_power_integer_exponent(middle, exponent) < base)
            left = middle;
        else
            right = middle;
    }

    return result - 1;
}

long double s21_root(long double base, int exponent, long double epsilon) {
    if (s21_are_equal(base, 0.0L, epsilon))
        return 0.0;

    long double result = get_initial_result(base, exponent);
    long double approximation = s21_power_integer_exponent(result, exponent);
    long double increment = 0.5L;
    while (s21_are_not_equal(approximation, base, epsilon)) {
        if (approximation < base)
            result += increment;
        else
            result -= increment;

        increment /= 2.0;

        const long double old_approximation = approximation;
        approximation = s21_power_integer_exponent(result, exponent);

        if (s21_are_equal(approximation, old_approximation, epsilon))
            break;
    }

    return result;
}
