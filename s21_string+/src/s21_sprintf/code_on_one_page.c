// #include <stdio.h>
// #include <stdlib.h>
// #include <stdarg.h>
// #include <math.h>
// #include <assert.h>

// int s21_sprintf(char *buffer,  char *format, ...);
// void choose_return_type(char *buffer,  char **format, int *index, va_list argp);
// void c_specifier(char *buffer, int *index, va_list argp);
// void percent_specifier(char *buffer, int *index,  char format);
// void right_justify_flag(char *buffer,  char **format, int *index, va_list argp);
// int check_if_the_end(char *format);

// enum is_true_or_false{
//     FALSE,
//     TRUE
// };

// int s21_atoi(char **format) {
//     int result = 0, index = 0;
//     char temp_array_of_numbers[12] = {'\0'};
//     while (**format <= '9' && **format >= '0') {
//         temp_array_of_numbers[index] = **format;
//         ++index;
//         ++*format;
//     }
//     int temp_index = index, char_int_step = 48;
//     for (int i = 0; i < index; ++i) {
//         result += (temp_array_of_numbers[i] - char_int_step) * pow(10, temp_index - 1);
//         --temp_index;
//     }
//     return result;
// }

// int main() {
//     // Always assign a '\0' value to the array, to not print garbage
//     char buffer[500] = {'\0'};
//     //  int input_int = 42;
//     char input_char = 's';
//     // char *format = "%4c Hello, %4c World %4c";
//     char *format = "%4c Hello, %4c World %4c";
//     //   s Hello,    s World    s";
//     s21_sprintf(buffer, format, input_char, input_char, input_char);
//     puts(buffer);
//     return 0;
// }

// int s21_sprintf(char *buffer,  char *format, ...) {
//     va_list argp;
//     va_start(argp, format);
//     int index = 0;
//     while (*format != '\0') {
//         if (*format == '%') {
//             ++format;
//             choose_return_type(buffer, &format, &index, argp);
//             // Added ++format; here to increase the value of format after choose return type works. This is needed for the flags to work properly
//             ++format;
//         } else {
//             buffer[index] = *format;
//             // Mistake shows up here when I exit the c_format function, format gets reset from " Hello, %4c World %4c" to "4c" Hello, %4c World %4c"
//             // assert(buffer[index] != 'c' && "wrong assignement");
//             ++index;
//             ++format;
//         }
//     }
//     va_end(argp);
//     return index;
// }

// void choose_return_type(char *buffer,  char **format, int *index, va_list argp) {
//     if ('c' == **format) {
//         c_specifier(buffer, index, argp);
//     } else if ('0' <= **format && '9' >= **format) {
//         right_justify_flag(buffer, format, index, argp);
//     } else {
//         percent_specifier(buffer, index, **format);
//     }
// }

// void c_specifier(char *buffer, int *index, va_list argp) {
//     buffer[*index] = va_arg(argp, int);
//     assert(buffer[*index] != 'c' && "wrong assignement");
//     ++*index;
// }

// void percent_specifier(char *buffer, int *index,  char format) {
//     buffer[*index] = format;
//     ++*index;
// }

// void right_justify_flag(char *buffer,  char **format, int *index, va_list argp) {
//     if (check_if_the_end(*format)) {
//         return;
//     }
//     int number_of_spaces = 0;
//     assert('0' <= **format && **format <= '9' && "Format should be numeric!\n");
//     number_of_spaces = s21_atoi(format);
//     for (int i = 0; i < number_of_spaces - 2; ++i) {
//         buffer[*index] = ' ';
//         ++*index;
//     }

//     assert(!('0' <= **format && **format <= '9') && "Format should not be numeric!\n");
//     if ('c' == **format) {
//         c_specifier(buffer, index, argp);
//     }
//     // choose_return_type(buffer, format, index, argp);
// }

// int check_if_the_end(char *format) {
//     int is_end = TRUE;
//     char *temp_format = format;
//     while(*temp_format != '\0') {
//         if (*temp_format < '0' || *temp_format > '9') {
//             is_end = FALSE;
//             break;
//         }
//         ++temp_format;
//     }
//     return is_end;
// }

// Test push test