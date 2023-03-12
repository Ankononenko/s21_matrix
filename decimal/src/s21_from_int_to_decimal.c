#include "s21_from_int_to_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int return_value = SUCCESS;
  if (dst) {
    memset(dst, 0, sizeof(unsigned int) * 4);
    if (src >= 0) {
      dst->bits[0] = src;
    } else {
      setSign(dst, 1);
      dst->bits[0] = -src;
    }
  } else {
    return_value = ERROR;
  }
  return return_value;
}
