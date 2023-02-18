#ifndef SRC_HEPLERS_HELPERS_H_
#define SRC_HEPLERS_HELPERS_H_

#include "../s21_decimal.h"

void init_decimal(s21_decimal* number);
void setScale(int scale, s21_decimal* number);
void setSign(s21_decimal* number, int sign);
int get_scale(unsigned int number);

#endif  //  SRC_HEPLERS_HELPERS_H_