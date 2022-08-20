#ifndef SRC_COMMON_COMMON_H_
#define SRC_COMMON_COMMON_H_

extern const long double g_epsilon;


int is_plus_zero(double x);
int is_minus_zero(double x);
int is_zero(double x);
long double s21_lfabs(long double x);
int s21_is_plus_infinity(double x);
int s21_is_minus_infinity(double x);
int s21_is_infinity(double x);
long double s21_factorial(int n);
int s21_is_nan(double x);
int s21_are_equal(long double a, long double b, long double epsilon);
int s21_are_not_equal(long double a, long double b, long double epsilon);
long double s21_power_integer_exponent(long double base, long long int exponent);
long double s21_root(long double base, int exponent, long double epsilon);


extern const long double s21_SQRT2;


#endif  //  SRC_COMMON_COMMON_H_
