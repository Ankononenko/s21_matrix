#include "s21_from_int_to_decimal.h"

// int main() {
//   // int one = 1;
//   // printf("one = ");
//   // num_to_binary(one);
//   // int five = 5;
//   // printf("\nfive = ");
//   // num_to_binary(five);
//   // int five_five = 555;
//   // printf("\n555 = ");
//   // num_to_binary(five_five);
//   // int max_int = 2147483647;
//   // printf("\nmax_int = ");
//   // num_to_binary(max_int);

//   return 0;
// }

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int return_value = SUCCESS;
  if (dst) {
    memset(dst, 0, sizeof(int) * 4);
    if (src >= 0) {
      dst->bits[0] = src;
    } else {
      setSign(dst, 1);
      dst->bits[0] = -src;
    }
  } else {
    return_value = ERROR;
  }
  return return_value;
}
