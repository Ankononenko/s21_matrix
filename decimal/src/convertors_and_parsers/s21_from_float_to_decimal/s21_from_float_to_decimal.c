#include "s21_from_float_to_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int return_value = SUCCESS;
  memset(dst, 0, sizeof(int) * 4);
  if (!isnormal(src) || src > MAX_DECIMAL || src < MIN_DECIMAL) {
    return_value = ERROR;
  } else {
    // The signbit function in C determines whether a floating-point number is negative
    int is_negative = signbit(src);
    long double abs_src = fabsf(src);
    int exponent = get_float_exponent(abs_src);
    
    // Pass the bits to the bits to a string
    char bit_string[128];
    memset(bit_string, 0, 128 * sizeof(char));
    get_bit_string(abs_src, bit_string, exponent);
    set_bits_from_string(bit_string, dst);
    if (is_negative) {
      setSign(dst, is_negative);
    }
    setScale(exponent, dst);
  }
  return return_value;
}

void set_bits_from_string(char* bit_string, s21_decimal *dst) {
  for (size_t index = strlen(bit_string) - 1; index < strlen(bit_string); --index) {
    if (bit_string[index] - '0') {
      ADD_BIT(dst->bits[index / 32], (index % 32));
    }
  }
}

void get_bit_string(long double abs_src, char* bit_string, int exponent) {
  long double max_exp = 28, epsilon = 1e-6;
  abs_src *= powl((long double)10, (long double)(max_exp - exponent));
  for (int index = 0; index > epsilon; ++index) {
    abs_src = floorl(abs_src) / 2;
    if (abs_src - floorl(abs_src) > epsilon) {
      bit_string[index] = '1';
    } else {
      bit_string[index] = '0';
    }
  }
}

int get_float_exponent(long double num) {
  int exponent = 0;
  while (num > 0) {
    num /= 10;
    ++exponent;
  }
  return exponent;
}