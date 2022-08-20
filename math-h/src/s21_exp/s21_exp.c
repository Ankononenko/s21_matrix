#include "../common/common.h"
#include "s21_exp.h"
#include "../s21_types.h"

static long double s21_fabs(long double x) {
    return x > 0.0L ? x : -x;
}

long double s21_exp(double x) {
    if (s21_is_plus_infinity(x))
        return s21_INF;

    if (x > 100.0)
        return s21_INF;
    if (x < -100.0)
        return 0.0L;

    if (x < 0.0)
        return 1.0L / s21_exp(-x);

    long double result = 0.0L;

    long double element = 1.0L;
    int iteration = 0;

    while (s21_fabs(element) > g_epsilon) {
        const long double power = s21_power_integer_exponent(x, iteration);
        const long double factorial = s21_factorial(iteration);

        element =  power / factorial;

        result += element;

        ++iteration;
    }

    return result;
}
