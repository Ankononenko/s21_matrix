#include "helpers.h"
#include "../bit_control/bit_control.h"

#include <assert.h>

/*
bits[3] contains the scale factor and sign, and consists of following parts:

-Bits 0 to 15, the lower word, are unused and must be zero.
-Bits 16 to 23 must contain an exponent between 0 and 28, which indicates the power of 10 to divide the integer number.   <----
-Bits 24 to 30 are unused and must be zero.
-Bit 31 contains the sign; 0 meaning positive, and 1 meaning negative.
*/

/*
    //  0   00000
    //  1   00001
    //  2   00010
    //  3   00011
    //  4   00100
    //  5   00101
    //  6   00110
    //  7   00111
    //  8   01000
    //  9   01001
    // 10   01010
    // 11   01011
    // 12   01100
    // 13   01101
    // 14   01110
    // 15   01111
    // 16   10000
    // 17   10001
    // 18   10010
    // 19   10011
    // 20   10100
    // 21   10101
    // 22   10110
    // 23   10111
    // 24   11000
    // 25   11001
    // 26   11010
    // 27   11011
    // 28   11100
*/

void setScale(int scale, s21_decimal* number) {
    assert(0 <= scale && scale <= 28 && "Scale factor is incorrect!");

    // the first exponent bit is 16
    // the last exponent bit is  23

    for (int bit_index = 16; bit_index <= 23; ++bit_index)
        place_bit(&(number->bits[3]), bit_index, is_bit_set(scale, bit_index - 16));
}
