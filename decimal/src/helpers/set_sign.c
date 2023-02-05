#include "helpers.h"
#include "../bit_control/bit_control.h"

#include <assert.h>

/*
bits[3] contains the scale factor and sign, and consists of following parts:

-Bits 0 to 15, the lower word, are unused and must be zero.
-Bits 16 to 23 must contain an exponent between 0 and 28, which indicates the power of 10 to divide the integer number.
-Bits 24 to 30 are unused and must be zero.
-Bit 31 contains the sign; 0 meaning positive, and 1 meaning negative.                                                          <-----
*/

void setSign(s21_decimal* number, int sign) {
    assert((sign == 1 || sign == 0) && "Incorrect value for sign!");

    Bool bool_sign = (sign == 1 ? TRUE : FALSE);

    place_bit(&(number->bits[3]), 31, bool_sign);
}
