#include "s21_from_float_to_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int return_value = SUCCESS;
  memset(dst, 0, sizeof(int) * 4);
  if (!isnormal(src) || src > MAX_DECIMAL || src < MIN_DECIMAL) {
    return_value = ERROR;
  } else {
    // Get exponent
    // Check if negative or not
    // Pass bits
    // Set sign
  }
  return return_value;
}
