#include "s21_from_decimal_to_int.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
    int sign = s21_get_bit(src.bits[3], 31);

    s21_decimal int_number = {{0, 0, 0, 0}};
    s21_truncate(src, &int_number);
    *dst = (int) src.bits[0];

    *dst *= sign ? -1 : 1;
    return 0;
}