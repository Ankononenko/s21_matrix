
#include <assert.h>

#include "s21_pow.h"
#include "../s21_log/s21_log.h"
#include "../s21_exp/s21_exp.h"

#include "../common/common.h"
#include "../s21_types.h"

#define UNUSED_SHIT(fucking_unused_shit) do { (void)(fucking_unused_shit); } while (0)

int is_integer(double x) {
    return s21_are_equal(x, (long long int)x, g_epsilon);
}

int is_plus_one(double x) {
    return s21_are_equal(x, 1.0L, g_epsilon);
}

int is_minus_one(double x) {
    return s21_are_equal(x, -1.0L, g_epsilon);
}

int is_one(double x) {
    return is_plus_one(x) || is_minus_one(x);
}


int is_odd(double x) {
    return ((long long int)x) % 2 && is_integer(x);
}
int is_even(double x) {
    return !is_odd(x) && is_integer(x);
}

long double s21_pow(double base, double exponent) {
    if (is_plus_zero(base) && exponent < 0.0 && is_odd(exponent))
        return s21_INF;

    if (is_minus_zero(base) && exponent < 0.0 && is_odd(exponent))
        return -s21_INF;

    if (is_zero(base) && exponent < 0.0 && is_odd(exponent))
        return -s21_INF;

    if (is_zero(base) && exponent < 0.0 && s21_is_minus_infinity(exponent))
        return s21_INF;


    if (is_plus_zero(base) && exponent > 0.0 && is_odd(exponent))
        return +0.0L;

    if (is_minus_zero(base) && exponent > 0.0 && is_odd(exponent))
        return -0.0L;

    if (is_zero(base) && (exponent > 0.0 || is_even(exponent)))
        return +0.0L;


    if (is_minus_one(base) && (s21_is_infinity(exponent)))
        return 1.0L;

    if (is_plus_one(base))
        return 1.0L;

    if (is_zero(exponent))
        return 1.0L;

    if (!s21_is_infinity(base) && base < 0.0 && !s21_is_infinity(exponent) && !is_integer(exponent))
        return s21_NAN;


    if (s21_is_minus_infinity(exponent)) {
        if (-1.0 < base && base < 1.0)
            return s21_INF;
        else if (!is_one(base))
            return +0.0L;
    }
    if (s21_is_plus_infinity(exponent)) {
        if (-1.0 < base && base < 1.0)
            return +0.0L;
        else if (!is_one(base))
            return s21_INF;
    }

    if (s21_is_minus_infinity(base)) {
        if (exponent < 0.0 && is_odd(exponent))
            return -0.0L;
        if (exponent < 0.0 && (!is_integer(exponent) || is_even(exponent)))
            return +0.0L;
        if (exponent > 0.0 && is_odd(exponent))
            return -s21_INF;
        if (exponent > 0.0 && (!is_integer(exponent) || is_even(exponent)))
            return s21_INF;
    }

    if (s21_is_plus_infinity(base)) {
        if (exponent < 0.0)
            return +0.0L;
        if (exponent > 0.0)
            return s21_INF;
    }

    if (is_integer(exponent)) {
        if (exponent > 0.0)
            return s21_power_integer_exponent(base, (long long int)exponent);
        else
            return 1.0L / s21_power_integer_exponent(base, -(long long int)exponent);
    }

    const long double result = s21_exp(exponent * s21_log(base));
    return result;
}
