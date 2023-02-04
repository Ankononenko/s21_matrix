#include "bit_control.h"

int is_bit_set(int num, int index) {
  return (num & (1 << index)) != 0;
}

int set_bit(int* num, int index) {
  (*num) |= (1 << index);
  return *num;
}

int reset_bit (int* num, int index) {
  (*num) = (*num) & ~(1 << index);
  return (*num);
}

Bool place_bit(int* num, int index, Bool bit) {
  if (bit)
    set_bit(num, index);
  else
    reset_bit(num, index);

  return bit;
}
