// Copyright 2022 finchren

/*

You need to develop a cat utility:

- Support of all flags (including GNU versions):

    1	-b (GNU: --number-nonblank)	numbers only non-empty lines
    2	-e implies -v (GNU only: -E the same, but without implying -v) but also display end-of-line characters as $
    3	-n (GNU: --number)	number all output lines
    4	-s (GNU: --squeeze-blank)	squeeze multiple adjacent blank lines
    5	-t implies -v (GNU: -T the same, but without implying -v)	but also display tabs as ^I

- The source, header, and build files must be placed in the src/cat/ directory
- The resulting executable file must be placed in the directory src/cat/ and named s21_cat

*/

#include <stdio.h>

int main(int argc, char *argv[]) {
    
    for (int index = 0; index < argc; ++index) {
        printf("argv[%d] = %s \n", index, argv[index]);
    }

    // char **pointer;
    // for (pointer = argv; *pointer != NULL; ++pointer) {
    //     printf("pointer = %s \n", *pointer);
    // }

    // printf("argc = %d \n", argc);

    return 0;
}