// Copyright 2022 finchren
/*

You need to develop the grep utility:

Support of the following flags: -e, -i, -v, -c, -l, -n
Only pcre or regex libraries can be used for regular expressions
The source, header and make files must be placed in the src/grep/ directory
The resulting executable file must be placed in the directory src/grep/ and named s21_grep

*/

#include "s21_grep.h"

int main() {
    Flags_grep flags_grep = {0};
    initialize_flags_grep(&flags_grep);
    Data_grep data_grep = {0};
    initialize_data_grep(&data_grep);
    return 0;
}

void initialize_data_grep(Data_grep* data_grep) {
    memset(data_grep->all_flags_array, 0, TOTAL_NUM_FLAGS_GREP * sizeof(char));
    memset(data_grep->all_filenames_array, 0, TOTAL_NUM_FILENAMES * sizeof(char));
    data_grep->number_of_files = 0;   
}

void initialize_flags_grep(Flags_grep* flags_grep) {
    flags_grep->e = FALSE;
    flags_grep->i = FALSE;
    flags_grep->v = FALSE;
    flags_grep->c = FALSE;
    flags_grep->l = FALSE;
    flags_grep->n = FALSE;
}
