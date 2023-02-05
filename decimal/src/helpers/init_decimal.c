#include "helpers.h"

void init_decimal(s21_decimal* number) {
    number->bits[0] = 0;
    number->bits[1] = 0;
    number->bits[2] = 0;
    number->bits[3] = 0;
}
