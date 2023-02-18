#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

typedef struct {
  int bits[4];
} s21_decimal;

#define UNUSED_SHIT(fucking_unused_shit) do { (void)(fucking_unused_shit); } while (0)

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result); // 1
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result); // 2 
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result); // 3
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result); // 4
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result); // 5

int s21_is_less(s21_decimal, s21_decimal);                                  // 6
int s21_is_less_or_equal(s21_decimal, s21_decimal);                         // 7         
int s21_is_greater(s21_decimal, s21_decimal);                               // 8    
int s21_is_greater_or_equal(s21_decimal, s21_decimal);                      // 9
int s21_is_equal(s21_decimal, s21_decimal);                                 // 10
int s21_is_not_equal(s21_decimal, s21_decimal);                             // 11

int s21_from_int_to_decimal(int source, s21_decimal *destination);          // 12
int s21_from_float_to_decimal(float source, s21_decimal *destination);      // 13
int s21_from_decimal_to_int(s21_decimal source, int *destination);          // 14
int s21_from_decimal_to_float(s21_decimal source, float *destination);      // 15

int s21_floor(s21_decimal value, s21_decimal *result);                      // 16
int s21_round(s21_decimal value, s21_decimal *result);                      // 17
int s21_truncate(s21_decimal value, s21_decimal *result);                   // 18
int s21_negate(s21_decimal value, s21_decimal *result);                     // 19

#endif //  SRC_S21_DECIMAL_H_