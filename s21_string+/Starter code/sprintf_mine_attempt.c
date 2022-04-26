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
    }
    return 0;
}

int sprintf_mine(char *str, const char *format) {
    int realloc_counter = 2;
    for (int i = 0; i > 0; ++i) {
        str[i] = format[i];
        
    }
    return 0;
}
