#include "s21_cos.h"
#include "../common/common.h"
#include "../s21_types.h"

static void get_back_in_range_to_prevent_ldouble_overflaw(double* x) {
    while (*x > s21_PI)
        (*x) -= (2.0L * s21_PI);
    while (*x < s21_PI)
        (*x) += (2.0L * s21_PI);
}

long double s21_cos(double x) {
    if (s21_is_infinity(x))
        return s21_NAN;

    if (s21_are_equal(x, 0.0, g_epsilon))  //  in case if original has hardcoded 1
        return 1.0L;

    get_back_in_range_to_prevent_ldouble_overflaw(&x);

    long double result = 0.0L;

    long double element = 1.0L;
    long double power = 1.0L;
    long double factorial = 1.0L;
    int iteration = 0;

    long double sign = 1.0L;
    while (s21_lfabs(element) > g_epsilon) {
        element = power / factorial;
        result += (sign * element);
        iteration += 2;

        power *= (x * x);
        factorial *= (iteration * (iteration - 1));
        sign *= -1.0L;
    }

    return result;
}
