#include "s21_asin.h"
#include "../common/common.h"
#include "../s21_types.h"

long double s21_asin(double x) {
    if (s21_lfabs(x) > 1.0L)
        return s21_NAN;

    if (s21_are_equal(x, 1.0L, g_epsilon))
        return s21_PI / 2.0L;
    if (s21_are_equal(x, -1.0L, g_epsilon))
        return -s21_PI / 2.0L;

    long double result = 0.0L;

    long double element = 1.0L;
    int iteration = 0;

    while (s21_lfabs(element) > g_epsilon) {
        const long double numerator = s21_factorial(2 * iteration);
        const long double four_power = s21_power_integer_exponent(4.0L, iteration);
        const long double factorial = s21_factorial(iteration);
        const long double multiplier = 2 * iteration + 1;

        const long double power = s21_power_integer_exponent(x, 2 * iteration + 1);

        element = (numerator / (four_power * factorial * factorial * multiplier)) * power;

        result += element;

        ++iteration;
    }

    return result;
}
