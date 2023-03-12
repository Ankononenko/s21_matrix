#ifndef BIT_CONTROL
#define BIT_CONTROL

#include "../s21_decimal.h"

// New version of bit control functions. Macros look a lot cleaner
#define IS_BIT_SET(X, POS) ((X >> POS) & 1U)
#define SET_BIT(X, BIT, POS) (X |= (BIT << POS))
#define ADD_BIT(X, POS) ((X) |= (1U << (POS)))
#define ZERO_BIT(X, POS) (X &= ~(1UL << POS));

typedef enum Bool { 
    FALSE = 0, 
    TRUE = 1,
} Bool;

int is_bit_set(int num, int index);
int get_bit(s21_decimal num, int index);
void new_set_bit(s21_decimal* num, int bit, int index);
int set_bit(int* num, int index);
int reset_bit(int* num, int index);
void set_bit_1(s21_decimal *num, int index);
void set_bit_0(s21_decimal *num, int index);
Bool place_bit(int* num, int index, Bool bit);
void s21_set_bit(int *number, int index, int bit);
int s21_get_bit(int number, int index);

#endif