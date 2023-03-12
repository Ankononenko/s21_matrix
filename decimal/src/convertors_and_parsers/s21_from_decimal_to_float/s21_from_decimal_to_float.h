#ifndef S21_FROM_DECIMAL_TO_FLOAT
#define S21_FROM_DECIMAL_TO_FLOAT

#define MAX_DECIMAL 79228162514264337593543950335.0F
#define MIN_DECIMAL -79228162514264337593543950335.0F

#include "../../bit_control/bit_control.h"
#include "../../helpers/helpers.h"
#include "../../s21_decimal.h"
#include <string.h>
#include <math.h>
#include "../../helpers/helpers.h"

enum return_value { SUCCESS, ERROR };

int get_exponent(s21_decimal decimal);
int get_sign(s21_decimal decimal);

#endif