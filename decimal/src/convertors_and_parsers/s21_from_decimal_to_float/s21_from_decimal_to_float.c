#include "s21_from_decimal_to_float.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  
  int return_value = SUCCESS;
  int sign = get_sign(src);

  if (!dst) {
    return_value = ERROR;
  } else {

    int exponent = get_exponent(src);
    long double temp = 0;

    for (int index = 0; index < 96; ++index) {
      temp += pow(2, index) * get_bit(src, index);
    }

    while (exponent) {
      temp /= 10.0;
      --exponent;
    }

    if (sign) {
      temp *= -1.0;
    }

    *dst = temp;

  }
  return return_value;
}

int get_exponent(s21_decimal decimal) {
    int exponent = 0;

    int exponent_bit_start = 16;
    int exponent_bit_end = 23;

    for (int index_i = exponent_bit_start, index_j = 0; index_i <= exponent_bit_end; index_i++, index_j++) {
        if (IS_BIT_SET(decimal.bits[3], index_i))
            ADD_BIT(exponent, index_j);
    }

    return exponent;
}

int get_sign(s21_decimal decimal) {
    return IS_BIT_SET(decimal.bits[3], 31);
}