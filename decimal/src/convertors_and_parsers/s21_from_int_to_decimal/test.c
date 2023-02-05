#include "test.h"

int main() {
  
  s21_decimal nums;
  init_decimal(&nums);
  int success_counter = 0, number_of_tests = 6;

  int one = 1;
  if (!s21_from_int_to_decimal(one, &nums)) {
    ++success_counter;
  }
  visualise_bits(nums, one);
  
  int zero = 0;
  if (!s21_from_int_to_decimal(zero, &nums)) {
    ++success_counter;
  }
  visualise_bits(nums, zero);
  
  int two_five_five = 255;
  if (!s21_from_int_to_decimal(two_five_five, &nums)) {
    ++success_counter;
  }
  visualise_bits(nums, two_five_five);
  
  int min_int = -2147483648;
  if (!s21_from_int_to_decimal(min_int, &nums)) {
    ++success_counter;
  }
  visualise_bits(nums, min_int);
  
  int max_int = 2147483647;
  if (!s21_from_int_to_decimal(max_int, &nums)) {
    ++success_counter;
  }
  visualise_bits(nums, max_int);
  
  int minus_two_five_five = -255;
  if (!s21_from_int_to_decimal(minus_two_five_five, &nums)) {
    ++success_counter;
  }
  visualise_bits(nums, minus_two_five_five);

  if (success_counter == number_of_tests) {
    printf("All tests passed!\n%d out of %d", success_counter, number_of_tests);
  } else {
    printf("Tests failed\n%d out of %d", success_counter, number_of_tests);
  }
  return 0;
}

void visualise_bits (s21_decimal dst, int number) {
  printf("Printing out the decimal bits of %d number:\n", number);
  for (int element_index = 0; element_index < 4; ++element_index) {
    printf("%d bit: ", element_index);
    for (int bit_index = 0; bit_index < 32; ++bit_index) {
      printf("%d ", is_bit_set(dst.bits[element_index], bit_index));
    }
    printf("\n");
  }
}