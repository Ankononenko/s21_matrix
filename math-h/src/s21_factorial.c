// Copyright 2022 finchren

long double s21_factorial(const int x) {
    long double result = 1.0L;
    for (int index = 1; index <= x; ++index) {
        result *= index;
    }
    return result;
}
