#ifndef BIT_CONTROL
#define BIT_CONTROL

#include "../s21_decimal.h"

// New version of bit control functions. Macros look a lot cleaner
#define SET_BIT(X, BIT, POS) (X |= (BIT << POS))
#define ADD_BIT(X, POS) ((X) |= (1U << (POS)))

typedef enum Bool { 
    FALSE = 0, 
    TRUE = 1,
} Bool;

int is_bit_set(int num, int index);
void new_set_bit(s21_decimal* num, int bit, int index);
int set_bit(int* num, int index);
int reset_bit(int* num, int index);
Bool place_bit(int* num, int index, Bool bit);

#endif