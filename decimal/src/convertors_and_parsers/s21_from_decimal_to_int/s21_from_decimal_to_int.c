#include "s21_from_decimal_to_int.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int return_value = SUCCESS;
  if (dst) {
    *dst = src.bits[0];
    if (is_bit_set(src.bits[3], 31)) {
      *dst *= -1;
    }
  } else {
    return_value = ERROR;
  }
  return return_value;
}
