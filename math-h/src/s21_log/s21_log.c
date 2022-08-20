#include <assert.h>

#include "s21_log.h"
#include "../common/common.h"

#include "../s21_types.h"

int get_integer_exponent(double* x) {
    int result = 0;
    while (*x > 1.0) {
        *x /= 2.0;
        ++result;
    }
    return result;
}

long double s21_log(double x) {
    if (s21_are_equal(x, 1.0, g_epsilon))
        return 0.0L;

    if (s21_is_plus_infinity(x))
        return s21_INF;

    if (s21_is_minus_infinity(x))
        return s21_NAN;

    if (x < 0.0)
        return s21_NAN;

    if (x < 1e-3) {
        long double inversed = 1.0L / x;

        return -1.0L * s21_log(inversed);
    }

    const int exponent = x < 1.0 ? 0 : get_integer_exponent(&x);

    long double result = 0.0L;
    long double element = 1.0L;

    int iteration = 1;
    while (s21_lfabs(element) > g_epsilon) {
        const long double numerator = s21_power_integer_exponent(1 - x, iteration);
        const long double  denominator = iteration;

        element = (numerator / denominator);

        result -= element;
        ++iteration;
    }

    static const long double ln2 = 0.693147180559945309417232121458L;
    result += (exponent * ln2);
    return result;
}
