#include "bit_control.h"

int is_bit_set(int num, int index) {
  return (num & (1 << index)) != 0;
}

void new_set_bit(s21_decimal* num, int bit, int index) {
  (bit == 1) ? (num->bits[index / 32] |= (1 << index % 32)) : (num->bits[index / 32] &= (1 << index % 32));
}

int get_bit(s21_decimal num, int index) {
    return (num.bits[index / 32] >> (index % 32)) & 1;
}

int s21_get_bit(int number, int index) {
    return (number & (1 << index)) != 0; 
}

void s21_set_bit(int *number, int index, int bit) {
    bit == 1 ? (*number |= (1 << index)) : (*number &= ~(1 << index));
}

int set_bit(int* num, int index) {
  (*num) |= (1 << index);
  return *num;
}

int reset_bit (int* num, int index) {
  (*num) = (*num) & ~(1 << index);
  return (*num);
}

void set_bit_1(s21_decimal *num, int index) {
    ADD_BIT(num->bits[index / 32], index % 32);
}
void set_bit_0(s21_decimal *num, int index) {
    ZERO_BIT(num->bits[index / 32], index % 32);
}

Bool place_bit(int* num, int index, Bool bit) {
  if (bit)
    set_bit(num, index);
  else
    reset_bit(num, index);

  return bit;
}