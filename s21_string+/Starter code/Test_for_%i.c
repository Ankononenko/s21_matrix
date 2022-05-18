// Test to see how it works

#include <stdio.h>
#include <string.h>

int main() {
    
    // Octal test MAX INT 
        // const int input_int = 017777777777;
        // const char *format = "%i Hello, World %i";
        // char array_to_output[100];
        // memset(array_to_output, 0, 100);
        // sprintf(array_to_output, format, input_int, input_int, input_int);
        // for (int i = 0; i <= 20; ++i) {
        //     printf("%c", array_to_output[i]);
        // }

    // Octal test MIN INT 
        // const int input_int = -020000000000;
        // const char *format = "%i Hello, World %i";
        // char array_to_output[100];
        // memset(array_to_output, 0, 100);
        // sprintf(array_to_output, format, input_int, input_int, input_int);
        // for (int i = 0; i <= 100; ++i) {
        //     printf("%c", array_to_output[i]);
        // }

    // Hexadecimal test MAX INT 
        // const int input_int = 0x7FFFFFFF;
        // const char *format = "%i Hello, World %i";
        // char array_to_output[100];
        // memset(array_to_output, 0, 100);
        // sprintf(array_to_output, format, input_int, input_int, input_int);
        // for (int i = 0; i <= 100; ++i) {
        //     printf("%c", array_to_output[i]);
        // }

    // Hexadecimal test MIN INT 
        const int input_int = -0x80000000;
        const char *format = "%i Hello, World %i";
        char array_to_output[100];
        memset(array_to_output, 0, 100);
        sprintf(array_to_output, format, input_int, input_int, input_int);
        for (int i = 0; i <= 100; ++i) {
            printf("%c", array_to_output[i]);
        }

    return 0;
}
