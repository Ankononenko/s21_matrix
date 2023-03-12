#include "helpers.h"

int get_scale(unsigned int number) {
    int scale = 0;
    number <<= 1;
    number >>= 17;
    scale = (int) number;
    return scale;
}