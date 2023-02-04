#include "bit_control.h"
#include "test.h"

int main(void) {
  test_is_bit_set();
  test_set_bit();
  test_reset_bit();
  return EXIT_SUCCESS;
}

void test_reset_bit() {
  int reset_bit_passed_tests = 0, reset_bit_total_tests = 0, reset_bit_failed_tests = 0;

  int reset_bit_test_1 = 1;
  reset_bit(&reset_bit_test_1, 0);
  printf("1. First bit of 1 set = %d\n", reset_bit_test_1);
  if (reset_bit_test_1 == 0) {
    printf("Passed\n");
    ++reset_bit_passed_tests;
    ++reset_bit_total_tests;
  } else {
    printf("Failed\n");
    ++reset_bit_failed_tests;
    ++reset_bit_total_tests;
  }

  int reset_bit_test_2 = 1;
  reset_bit(&reset_bit_test_2, 2);
  printf("2. Second bit of 1 set = %d\n", reset_bit_test_2); 
  if (reset_bit_test_2 == 1) {
    printf("Passed\n");
    ++reset_bit_passed_tests;
    ++reset_bit_total_tests;
  } else {
    printf("Failed\n");
    ++reset_bit_failed_tests;
    ++reset_bit_total_tests;
  }

  int reset_bit_test_3 = 7;
  reset_bit(&reset_bit_test_3, 0);
  printf("3. 3 bit of 7 set = %d\n", reset_bit_test_3); 
  if (reset_bit_test_3 == 6) {
    printf("Passed\n");
    ++reset_bit_passed_tests;
    ++reset_bit_total_tests;
  } else {
    printf("Failed\n");
    ++reset_bit_failed_tests;
    ++reset_bit_total_tests;
  }

  int reset_bit_test_4 = 7;
  reset_bit(&reset_bit_test_4, 2);
  printf("4. 7 bit of 1 set = %d\n", reset_bit_test_4); 
  if (reset_bit_test_4 == 3) {
    printf("Passed\n");
    ++reset_bit_passed_tests;
    ++reset_bit_total_tests;
  } else {
    printf("Failed\n");
    ++reset_bit_failed_tests;
    ++reset_bit_total_tests;
  }

  int reset_bit_test_5 = 7;
  reset_bit(&reset_bit_test_5, 31);
  printf("5. 31 bit of 1 set = %d\nn", reset_bit_test_5); 
  if (reset_bit_test_5 == 7) {
    printf("Passed\n");
    ++reset_bit_passed_tests;
    ++reset_bit_total_tests;
  } else {
    printf("Failed\n");
    ++reset_bit_failed_tests;
    ++reset_bit_total_tests;
  }

  int reset_bit_test_6 = -2147483648;
  reset_bit(&reset_bit_test_6, 31);
  printf("6. 30 bit of -2147483648 set = %d\n", reset_bit_test_6); 
  if (reset_bit_test_6 == 0) {
    printf("Passed\n");
    ++reset_bit_passed_tests;
    ++reset_bit_total_tests;
  } else {
    printf("Failed\n");
    ++reset_bit_failed_tests;
    ++reset_bit_total_tests;
  }

  int reset_bit_test_7 = -2147483648;
  reset_bit(&reset_bit_test_7, 0);
  printf("7. 0 bit of -2147483648 set = %d\n", reset_bit_test_7); 
  if (reset_bit_test_7 == -2147483648) {
    printf("Passed\n");
    ++reset_bit_passed_tests;
    ++reset_bit_total_tests;
  } else {
    printf("Failed\n");
    ++reset_bit_failed_tests;
    ++reset_bit_total_tests;
  }

  int reset_bit_test_8 = -2147483648;
  reset_bit(&reset_bit_test_8, 15);
  printf("8. 15 bit of -2147483648 set = %d\n", reset_bit_test_8); 
  if (reset_bit_test_8 == -2147483648) {
    printf("Passed\n");
    ++reset_bit_passed_tests;
    ++reset_bit_total_tests;
  } else {
    printf("Failed\n");
    ++reset_bit_failed_tests;
    ++reset_bit_total_tests;
  }

  int reset_bit_test_9 = 2147483647;
  reset_bit(&reset_bit_test_9, 1);
  printf("9. 1 bit of 2147483647 set = %d\n", reset_bit_test_9); 
  if (reset_bit_test_9 == 2147483645) {
    printf("Passed\n");
    ++reset_bit_passed_tests;
    ++reset_bit_total_tests;
  } else {
    printf("Failed\n");
    ++reset_bit_failed_tests;
    ++reset_bit_total_tests;
  }

  int reset_bit_test_10 = 2147483647;
  reset_bit(&reset_bit_test_10, 15);
  printf("10. 15 bit of 2147483647 set = %d\n", reset_bit_test_10); 
  if (reset_bit_test_10 == 2147450879) {
    printf("Passed\n");
    ++reset_bit_passed_tests;
    ++reset_bit_total_tests;
  } else {
    printf("Failed\n");
    ++reset_bit_failed_tests;
    ++reset_bit_total_tests;
  }

  int reset_bit_test_11 = 2147483647;
  reset_bit(&reset_bit_test_11, 30);
  printf("11. 31 bit of 1 set = %d\n", reset_bit_test_11); 
  if (reset_bit_test_11 == 1073741823) {
    printf("Passed\n");
    ++reset_bit_passed_tests;
    ++reset_bit_total_tests;
  } else {
    printf("Failed\n");
    ++reset_bit_failed_tests;
    ++reset_bit_total_tests;
  }

  int reset_bit_test_12 = 0;
  reset_bit(&reset_bit_test_12, 0);
  printf("12. 0 bit of 0 set = %d\n", reset_bit_test_12); 
  if (reset_bit_test_12 == 0) {
    printf("Passed\n");
    ++reset_bit_passed_tests;
    ++reset_bit_total_tests;
  } else {
    printf("Failed\n");
    ++reset_bit_failed_tests;
    ++reset_bit_total_tests;
  }

  printf("\nreset_bit function tests completed\n"
         "Total num test = %d, passed tests = %d, failed tests = %d\n\n",
         reset_bit_total_tests, reset_bit_passed_tests, reset_bit_failed_tests);  
}

void test_set_bit() {
  int set_bit_passed_tests = 0, set_bit_total_tests = 0, set_bit_failed_tests = 0;

  int set_bit_test_1 = 1;
  set_bit(&set_bit_test_1, 1);
  printf("1. First bit of 1 set = %d\n", set_bit_test_1);
  if (set_bit_test_1 == 3) {
    printf("Passed\n");
    ++set_bit_passed_tests;
    ++set_bit_total_tests;
  } else {
    printf("Failed\n");
    ++set_bit_failed_tests;
    ++set_bit_total_tests;
  }

  int set_bit_test_2 = 1;
  set_bit(&set_bit_test_2, 2);
  printf("2. Second bit of 1 set = %d\n", set_bit_test_2); 
  if (set_bit_test_2 == 5) {
    printf("Passed\n");
    ++set_bit_passed_tests;
    ++set_bit_total_tests;
  } else {
    printf("Failed\n");
    ++set_bit_failed_tests;
    ++set_bit_total_tests;
  }

  int set_bit_test_3 = 7;
  set_bit(&set_bit_test_3, 3);
  printf("3. 3 bit of 7 set = %d\n", set_bit_test_3); 
  if (set_bit_test_3 == 15) {
    printf("Passed\n");
    ++set_bit_passed_tests;
    ++set_bit_total_tests;
  } else {
    printf("Failed\n");
    ++set_bit_failed_tests;
    ++set_bit_total_tests;
  }

  int set_bit_test_4 = 7;
  set_bit(&set_bit_test_4, 7);
  printf("4. 7 bit of 1 set = %d\n", set_bit_test_4); 
  if (set_bit_test_4 == 135) {
    printf("Passed\n");
    ++set_bit_passed_tests;
    ++set_bit_total_tests;
  } else {
    printf("Failed\n");
    ++set_bit_failed_tests;
    ++set_bit_total_tests;
  }

  int set_bit_test_5 = 7;
  set_bit(&set_bit_test_5, 31);
  printf("5. 31 bit of 1 set = %d\nn", set_bit_test_5); 
  if (set_bit_test_5 == -2147483641) {
    printf("Passed\n");
    ++set_bit_passed_tests;
    ++set_bit_total_tests;
  } else {
    printf("Failed\n");
    ++set_bit_failed_tests;
    ++set_bit_total_tests;
  }

  int set_bit_test_6 = -2147483648;
  set_bit(&set_bit_test_6, 30);
  printf("6. 30 bit of -2147483648 set = %d\n", set_bit_test_6); 
  if (set_bit_test_6 == -1073741824) {
    printf("Passed\n");
    ++set_bit_passed_tests;
    ++set_bit_total_tests;
  } else {
    printf("Failed\n");
    ++set_bit_failed_tests;
    ++set_bit_total_tests;
  }

  int set_bit_test_7 = -2147483648;
  set_bit(&set_bit_test_7, 0);
  printf("7. 0 bit of -2147483648 set = %d\n", set_bit_test_7); 
  if (set_bit_test_7 == -2147483647) {
    printf("Passed\n");
    ++set_bit_passed_tests;
    ++set_bit_total_tests;
  } else {
    printf("Failed\n");
    ++set_bit_failed_tests;
    ++set_bit_total_tests;
  }

  int set_bit_test_8 = -2147483648;
  set_bit(&set_bit_test_8, 15);
  printf("8. 15 bit of -2147483648 set = %d\n", set_bit_test_8); 
  if (set_bit_test_8 == -2147450880) {
    printf("Passed\n");
    ++set_bit_passed_tests;
    ++set_bit_total_tests;
  } else {
    printf("Failed\n");
    ++set_bit_failed_tests;
    ++set_bit_total_tests;
  }

  int set_bit_test_9 = 2147483647;
  set_bit(&set_bit_test_9, 1);
  printf("9. 1 bit of 2147483647 set = %d\n", set_bit_test_9); 
  if (set_bit_test_9 == 2147483647) {
    printf("Passed\n");
    ++set_bit_passed_tests;
    ++set_bit_total_tests;
  } else {
    printf("Failed\n");
    ++set_bit_failed_tests;
    ++set_bit_total_tests;
  }

  int set_bit_test_10 = 2147483647;
  set_bit(&set_bit_test_10, 15);
  printf("10. 15 bit of 2147483647 set = %d\n", set_bit_test_10); 
  if (set_bit_test_9 == 2147483647) {
    printf("Passed\n");
    ++set_bit_passed_tests;
    ++set_bit_total_tests;
  } else {
    printf("Failed\n");
    ++set_bit_failed_tests;
    ++set_bit_total_tests;
  }

  int set_bit_test_11 = 2147483647;
  set_bit(&set_bit_test_11, 31);
  printf("11. 31 bit of 1 set = %d\n", set_bit_test_11); 
  if (set_bit_test_11 == -1) {
    printf("Passed\n");
    ++set_bit_passed_tests;
    ++set_bit_total_tests;
  } else {
    printf("Failed\n");
    ++set_bit_failed_tests;
    ++set_bit_total_tests;
  }

  int set_bit_test_12 = 0;
  set_bit(&set_bit_test_12, 0);
  printf("12. 0 bit of 0 set = %d\n", set_bit_test_12); 
  if (set_bit_test_12 == 1) {
    printf("Passed\n");
    ++set_bit_passed_tests;
    ++set_bit_total_tests;
  } else {
    printf("Failed\n");
    ++set_bit_failed_tests;
    ++set_bit_total_tests;
  }

  printf("\nset_bit function tests completed\n"
         "Total num test = %d, passed tests = %d, failed tests = %d\n\n",
         set_bit_total_tests, set_bit_passed_tests, set_bit_failed_tests);  
}

void test_is_bit_set() {
  int is_bit_set_passed_tests = 0, is_bit_set_total_tests = 0, is_bit_set_failed_tests = 0;

  int is_bit_set_test_1 = is_bit_set(1, 0);
  printf("1. Is the first bit of 1 set? %d\n", is_bit_set_test_1);
  if (is_bit_set_test_1) {
    printf("Passed\n");
    ++is_bit_set_passed_tests;
    ++is_bit_set_total_tests;
  } else {
    printf("Failed\n");
    ++is_bit_set_failed_tests;
    ++is_bit_set_total_tests;
  }

  int is_bit_set_test_2 = is_bit_set(1, 1);
  printf("2. Is the second bit of 1 set? %d\n", is_bit_set_test_2); 
  if (!is_bit_set_test_2) {
    printf("Passed\n");
    ++is_bit_set_passed_tests;
    ++is_bit_set_total_tests;
  } else {
    printf("Failed\n");
    ++is_bit_set_failed_tests;
    ++is_bit_set_total_tests;
  }

  int is_bit_set_test_3 = is_bit_set(7, 0);
  printf("3. Is the first bit of 7 set? %d\n", is_bit_set_test_3); 
  if (is_bit_set_test_3) {
    printf("Passed\n");
    ++is_bit_set_passed_tests;
    ++is_bit_set_total_tests;
  } else {
    printf("Failed\n");
    ++is_bit_set_failed_tests;
    ++is_bit_set_total_tests;
  }

  int is_bit_set_test_4 = is_bit_set(7, 1);
  printf("4. Is the second bit of 7 set? %d\n", is_bit_set_test_4); 
  if (is_bit_set_test_4) {
    printf("Passed\n");
    ++is_bit_set_passed_tests;
    ++is_bit_set_total_tests;
  } else {
    printf("Failed\n");
    ++is_bit_set_failed_tests;
    ++is_bit_set_total_tests;
  }

  int is_bit_set_test_5 = is_bit_set(7, 7);
  printf("5. Is the seventh bit of 7 set? %d\n", is_bit_set_test_5); 
  if (!is_bit_set_test_5) {
    printf("Passed\n");
    ++is_bit_set_passed_tests;
    ++is_bit_set_total_tests;
  } else {
    printf("Failed\n");
    ++is_bit_set_failed_tests;
    ++is_bit_set_total_tests;
  }

  int is_bit_set_test_6 = is_bit_set(-2147483648, 31);
  printf("6. Is the 31 bit of -2147483648 set? %d\n", is_bit_set_test_6); 
  if (is_bit_set_test_6) {
    printf("Passed\n");
    ++is_bit_set_passed_tests;
    ++is_bit_set_total_tests;
  } else {
    printf("Failed\n");
    ++is_bit_set_failed_tests;
    ++is_bit_set_total_tests;
  }

  int is_bit_set_test_7 = is_bit_set(-2147483648, 0);
  printf("7. Is the 0 bit of -2147483648 set? %d\n", is_bit_set_test_7); 
  if (!is_bit_set_test_7) {
    printf("Passed\n");
    ++is_bit_set_passed_tests;
    ++is_bit_set_total_tests;
  } else {
    printf("Failed\n");
    ++is_bit_set_failed_tests;
    ++is_bit_set_total_tests;
  }

  int is_bit_set_test_8 = is_bit_set(-2147483648, 15);
  printf("8. Is the 15 bit of -2147483648 set? %d\n", is_bit_set_test_8); 
  if (!is_bit_set_test_8) {
    printf("Passed\n");
    ++is_bit_set_passed_tests;
    ++is_bit_set_total_tests;
  } else {
    printf("Failed\n");
    ++is_bit_set_failed_tests;
    ++is_bit_set_total_tests;
  }

  int is_bit_set_test_9 = is_bit_set(2147483647, 1);
  printf("9. Is the 1 bit of 2147483647 set? %d\n", is_bit_set_test_9); 
  if (is_bit_set_test_9) {
    printf("Passed\n");
    ++is_bit_set_passed_tests;
    ++is_bit_set_total_tests;
  } else {
    printf("Failed\n");
    ++is_bit_set_failed_tests;
    ++is_bit_set_total_tests;
  }

  int is_bit_set_test_10 = is_bit_set(2147483647, 15);
  printf("10. Is the 15 bit of 2147483647 set? %d\n", is_bit_set_test_10); 
  if (is_bit_set_test_9) {
    printf("Passed\n");
    ++is_bit_set_passed_tests;
    ++is_bit_set_total_tests;
  } else {
    printf("Failed\n");
    ++is_bit_set_failed_tests;
    ++is_bit_set_total_tests;
  }

  int is_bit_set_test_11 = is_bit_set(2147483647, 30);
  printf("11. Is the 30 bit of 2147483647 set? %d\n", is_bit_set_test_11); 
  if (is_bit_set_test_11) {
    printf("Passed\n");
    ++is_bit_set_passed_tests;
    ++is_bit_set_total_tests;
  } else {
    printf("Failed\n");
    ++is_bit_set_failed_tests;
    ++is_bit_set_total_tests;
  }

  int is_bit_set_test_12 = is_bit_set(0, 0);
  printf("12. Is the 0 bit of 0 set? %d\n", is_bit_set_test_12); 
  if (!is_bit_set_test_12) {
    printf("Passed\n");
    ++is_bit_set_passed_tests;
    ++is_bit_set_total_tests;
  } else {
    printf("Failed\n");
    ++is_bit_set_failed_tests;
    ++is_bit_set_total_tests;
  }

  printf("\nis_bit_set function tests completed\n"
         "Total num test = %d, passed tests = %d, failed tests = %d\n\n",
         is_bit_set_total_tests, is_bit_set_passed_tests, is_bit_set_failed_tests);
}
