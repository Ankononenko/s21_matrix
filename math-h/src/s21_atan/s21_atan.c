#include "s21_atan.h"
#include "../common/common.h"
#include "../s21_types.h"

long double s21_atan(double x) {
    if (x > 1.0)
        return s21_PI / 2.0L - s21_atan(1.0 / x);
    if (x < -1.0)
        return -s21_PI / 2.0L - s21_atan(1.0 / x);

    if (s21_are_equal(x, 1.0L, g_epsilon))
        return s21_PI / 4.0L;
    if (s21_are_equal(x, -1.0L, g_epsilon))
        return -s21_PI / 4.0L;

    int iteration = 1;
    long double power = x;
    long double result = power;

    long double element = 1.0L;

    long double sign = 1.0L;
    while (s21_lfabs(element) > g_epsilon) {
        power *= (x * x);
        const long double denominator = 2 * iteration + 1;
        element = power / denominator;
        sign *= -1.0L;

        result += (sign * element);

        iteration += 1;
    }

    return result;
}
