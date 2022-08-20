#include "s21_acos.h"
#include "../s21_asin/s21_asin.h"
#include "../s21_types.h"

long double s21_acos(double x) {
    return s21_PI / 2.0L - s21_asin(x);
}
