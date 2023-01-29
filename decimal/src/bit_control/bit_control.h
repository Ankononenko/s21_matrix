#ifndef BIT_CONTROL
#define BIT_CONTROL

#include <stdio.h>
#include <stdlib.h>

enum is_true { FALSE, TRUE };

int is_bit_set (int num, int index);
int set_bit (int num, int index);
int reset_bit (int num, int index);

#endif