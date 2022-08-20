#include "s21_ceil.h"
#include "../common/common.h"
#include "string.h"

long double s21_ceil(double x) {
    if (s21_is_infinity(x))
        return x;

    if (s21_is_nan(x))
        return x;

    if (-__LONG_LONG_MAX__ < x && x < __LONG_LONG_MAX__) {
        if (x > 0.0)
            return (long long int)x + 1ll;
        else
            return (long long int)x;
    } else {
        return x;
    }
}
