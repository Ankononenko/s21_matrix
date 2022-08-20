#include <math.h>

#include <assert.h>
#include "s21_sqrt.h"
#include "../common/common.h"
#include "../s21_types.h"

long double s21_sqrt(double x) {
    if (x < 0.0 || s21_is_nan(x))
        return s21_NAN;

    if (s21_is_plus_infinity(x) || is_zero(x))
        return x;

    return s21_root(x, 2, g_epsilon);
}
