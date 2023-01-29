#include "bit_control.h"

int is_bit_set (int num, int index) {
  return (num & (1 << index)) != 0;
}

int set_bit (int num, int index) {
  return num | (1 << index);
}

int reset_bit (int num, int index) {
  return num & ~(1 << index);
}