#ifndef S21_FROM_FLOAT_TO_DECIMAL
#define S21_FROM_FLOAT_TO_DECIMAL

#define MAX_DECIMAL 79228162514264337593543950335.0F
#define MIN_DECIMAL -79228162514264337593543950335.0F

#include "../../bit_control/bit_control.h"
#include "../../helpers/helpers.h"
#include "string.h"
#include <math.h>

enum return_value { SUCCESS, ERROR };

int get_float_exponent(long double num);
void get_bit_string(long double abs_src, char* bit_string, int exponent);
void set_bits_from_string(char* bit_string, s21_decimal *dst);

#endif