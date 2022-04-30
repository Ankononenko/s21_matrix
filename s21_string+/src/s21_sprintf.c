// Copyright 2022 finchren
/*
Task - Implement the sprintf function from the stdio.h library
+ 1. Write the results to a character string buffer
2. Formatting support:
    a. Specifiers: c, d, i, f, s, u, %
    b. Flags: -, +, (space)
    c. Width description: (number)
    d. Precision description: .(number)
    e. Length description: h, l
3. Memory test
4. Test
5. Cpplint test
6. Implement the function in the s21_string.h library
*/

#include <stdio.h>
#include <stdlib.h>

int sprintf_mine(char *str, const char *format);

int main() {
    char *pointer_str_array;
    pointer_str_array = (char*)malloc(1*sizeof(char));
    if (pointer_str_array == NULL) {
        printf("Memory could not be allocated");
    } else {
        sprintf_mine(pointer_str_array, "Hello world");
        puts(pointer_str_array);
    }
    free(pointer_str_array);
    pointer_str_array = NULL;
    return 0;
}

int sprintf_mine(char *str, const char *format) {
    int realloc_counter = 2;
    for (int i = 0; i > -1; ++i) {
        if (format[i] != '\0') {
            str[i] = format[i];
            str = (char*)realloc(str, (realloc_counter)*sizeof(char));
            ++realloc_counter;
        } else {
            break;
        }
    }
    return 0;
}
