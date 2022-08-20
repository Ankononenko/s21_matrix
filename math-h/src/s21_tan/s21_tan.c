#include "s21_tan.h"
#include "../s21_sin/s21_sin.h"
#include "../s21_cos/s21_cos.h"
#include "../common/common.h"
#include "../s21_types.h"

static void get_back_to_range_to_handle_poles(double* x) {
    while (*x > s21_PI / 2.0L)
        (*x) -= s21_PI;
    while (*x < -s21_PI / 2.0L)
        (*x) += s21_PI;
}

long double s21_tan(double x) {
    if (s21_is_infinity(x) || s21_is_nan(x))
        return s21_NAN;

    get_back_to_range_to_handle_poles(&x);

    if (s21_are_equal(s21_PI / 2.0L, x, 1e-8L))
        return s21_INF;

    if (s21_are_equal(-s21_PI / 2.0L, x, 1e-8L))
        return -s21_INF;

    if (s21_are_equal(x, 0.0, g_epsilon))
        return x;

    return s21_sin(x) / s21_cos(x);
}
