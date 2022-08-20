#include "s21_fmod.h"
#include "../s21_floor/s21_floor.h"
#include "../s21_ceil/s21_ceil.h"
#include "../common/common.h"
#include "../s21_types.h"

long double s21_fmod(double x, double y) {
    if (s21_is_infinity(x))
        return s21_NAN;

    if (s21_is_infinity(y))
        return x;


    const long double division = x / y;

    long double division_integer = 1.0L;
    if (division > 0.0L)
        division_integer = s21_floor(division);
    else
        division_integer = s21_ceil(division);

    const long double remainder = x - division_integer * y;

    return remainder;
}
