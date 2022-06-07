#ifndef S21_ITOA_H
#define S21_ITOA_H

#include <stdio.h>
#include <math.h>

char* s21_itoa(int number, char *buffer, int base, int *number_of_digits_Out);
char* s21_itoa_unsigned(unsigned int number, char *buffer, int base, int *number_of_digits_Out);

#endif