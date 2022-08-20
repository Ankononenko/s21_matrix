#include "s21_floor.h"
#include "../common/common.h"

long double s21_floor(double x) {
        if (s21_is_infinity(x))
        return x;

    if (s21_is_nan(x))
        return x;

    if (-__LONG_LONG_MAX__ < x && x < __LONG_LONG_MAX__) {
        if (x < 0.0) {
            if (s21_are_not_equal((long long int)x, x, g_epsilon))
                return (long long int)x - 1ll;
            else
                return (long long int)x;
        } else {
            return (long long int)x;
        }
    } else {
        return x;
    }
    return x;
}
