#include "s21_decimal.h"
#include <string.h>
#include "helpers/helpers.h"
#include "bit_control/bit_control.h"

unsigned int s21_divide_by_10(s21_decimal *number);
int s21_get_highest_bit(s21_decimal number);
int s21_get_bit_new(s21_decimal number, int bit_position);
void s21_shift_left(s21_decimal *number, int number_of_shifts);

int s21_truncate(s21_decimal value, s21_decimal *result) {
    int value_scale = get_scale(value.bits[3]);
    int value_sign = s21_get_bit(value.bits[3], 31);

    for (int i = 0; i < value_scale; i++) {
        s21_divide_by_10(&value);
    }

    *result = value;
    s21_set_bit(&result->bits[3], 31, value_sign);
    setScale(0, result);
    return 0;
}

unsigned int s21_divide_by_10(s21_decimal *number) {
    int buffer = 0;
    int last_bit_position = 0;
    int scale_of_number = get_scale(number->bits[3]);
    s21_decimal result = {{0, 0, 0, 0}};

    last_bit_position = s21_get_highest_bit(*number);

    for (int i = 0; i < last_bit_position + 2; i++) {
        if (buffer >= 10) {
           
            s21_shift_left(&result, 1);
            s21_set_bit(&result.bits[0], 0, 1);

            buffer = buffer - 10u;

            int new_bit = s21_get_bit_new(*number, last_bit_position - i);
            buffer = buffer << 1;
            s21_set_bit(&buffer, 0, new_bit);
        } else {

            s21_shift_left(&result, 1);
            s21_set_bit(&result.bits[0], 0, 0);

            int new_bit = s21_get_bit_new(*number, last_bit_position - i);
            buffer = buffer << 1;
            s21_set_bit(&buffer, 0, new_bit);
        }
    }

    buffer = buffer >> 1;
    *number = result;
    setScale(scale_of_number, number);

    return buffer;
}

int s21_get_highest_bit(s21_decimal number) {
    int bit_position = -1;

    for (int i = 0; i < 96 && bit_position == -1; i++) {
        if (s21_get_bit_new(number, (95 - i)) == 1) {
            bit_position = (95 - i);
        }
    }

    return bit_position;
}

int s21_get_bit_new(s21_decimal number, int bit_position) {
    int bit_number = bit_position / 32;
    bit_position = bit_position % 32;
    int bit = (int) ((number.bits[bit_number] >> bit_position) & 1u);

    return bit;
}

void s21_shift_left(s21_decimal *number, int number_of_shifts) {
    for (int i = 0; i < number_of_shifts; i++) {
        int low_last_bit = s21_get_bit(number->bits[0], 31);
        int mid_last_bit = s21_get_bit(number->bits[1], 31);

        number->bits[0] <<= 1;
        number->bits[1] <<= 1;
        number->bits[2] <<= 1;

        s21_set_bit(&number->bits[1], 0, low_last_bit);
        s21_set_bit(&number->bits[2], 0, mid_last_bit);
    }
}