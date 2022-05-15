#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>

char* s21_itoa(int number, char *buffer, int base);
int s21_sprintf(char *buffer, const char *format, ...);
void c_specifier(char *buffer, int *index, va_list argp);
void d_specifier(char *buffer, int *index, va_list argp);
void choose_return_type(char *buffer, const char *format, int *index, va_list argp);

int main() {
    const int input_int = 2147483648;
    const char *format = "%d%d Hello, World %d%d";

    char s21_buffer[100];
    memset(s21_buffer, 0, 100);
    char buffer[100];
    memset(buffer, 0, 100);

    const int s21_result = s21_sprintf(s21_buffer, format, input_int, input_int, input_int, input_int);
    const int result = sprintf(buffer, format, input_int, input_int, input_int, input_int);
    puts(s21_buffer);
    puts(buffer);
    return 0;
}

char* s21_itoa(int number, char *buffer, int base) {
    int current = 0;
    if (number == 0) {
        buffer[current++] = '0';
        buffer[current] = '\0';
        return buffer;
    }
    int num_digits = 0;
    if (number < 0) {
        ++num_digits;
        buffer[current] = '-';
        ++current;
        number *= -1;
    }
    num_digits += (int)floor(log(number) / log(base)) + 1;
    while (current < num_digits) {
        int base_val = (int) pow(base, num_digits -1 -current);
        int num_val = number / base_val;
        char value = num_val + '0';
        buffer[current] = value;
        ++current;
        number -= base_val * num_val;
    }
    buffer[current] = '\0';
    return buffer;
}

int s21_sprintf(char *buffer, const char *format, ...) {
    va_list argp;
    va_start(argp, format);
    int index = 0, number_of_specifires = 0;
    while (*format != '\0') {
        if (*format == '%') {
            ++number_of_specifires;    
            ++format;
            choose_return_type(buffer, format, &index, argp);
            ++format;
        } else {
            buffer[index] = *format;
            ++index;
            ++format;
        }
    }
    va_end(argp);
    return index;
}

void c_specifier(char *buffer, int *index, va_list argp) {
    buffer[*index] = va_arg(argp, int);
    ++*index;
}

void d_specifier(char *buffer, int *index, va_list argp) {
    char array_for_int[10];
    int int_array_index = 0;
    int index_local = *index;
    s21_itoa(va_arg(argp, int), array_for_int, 10);
    while (array_for_int[int_array_index] != '\0') {
        buffer[*index] = array_for_int[int_array_index];
        ++int_array_index;
        ++*index;
    }
}

void choose_return_type(char *buffer, const char *format, int *index, va_list argp) {
    if ('c' == *format) {
        c_specifier(buffer, index, argp);
    }
    if ('d' == *format) {
        d_specifier(buffer, index, argp);
    }
}
