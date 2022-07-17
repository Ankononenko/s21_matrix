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

#include "s21_cat.h"

int main(int argc, char *argv[]) {
    Flags flags;
    initialize_flags(&flags);
    check_start_conditions(argc, argv);
    return 0;
}

int check_start_conditions(int argc, char *argv[]) {
    int conditions = FALSE;
    // Condition to catch the case when only text-file is given without flags
    if (argc == 2 && argv[1][0] != '-') {
        conditions = TRUE;
    }
    // Condition to check if theree are flags and a text-file
    // Parse flags() should return TRUE or FALSE if the flags are valid or they are not valid
    // Here also should be a check if file exists 
    if (argc > 2 && parse_flags_and_text_files(argc, argv)) {
        conditions = TRUE;
    }
    return conditions;
}

int parse_flags_and_text_files(int argc, char *argv[]) {
    int is_valid_input = FALSE;
    // Here we have two-dimensional array first loop is going to iterate over elements of array
    for (int element_index = 1; element_index < argc; ++element_index) {
        // And the second is going to iterate over the element itself
        int letter_index = 0;
        // Create an array for all the flags - valid and invalid to sort them out later
        char all_flags_array[NMAX][NMAX];
        // And an array for text-file names - valid and invalid to sort later
        char all_text_files_array[NMAX][NMAX];
        // Counters to know when to stop in iterating over the arrays
        int counter_for_flags = 0, counter_for_text_files = 0;
        while (argv[element_index][letter_index] != '\0') {
            if (argv[element_index][letter_index] == '-') {
                strcpy(all_flags_array[counter_for_flags], argv[element_index]);
                ++counter_for_flags;
            } else {
                strcpy(all_text_files_array[counter_for_flags], argv[element_index]);
                ++counter_for_text_files;
            }
        }
        if (check_if_flags_are_valid(counter_for_flags, all_flags_array &&
            check_if_files_exist(counter_for_text_files, all_text_files_array))) {
            is_valid_input = TRUE;
        }
    }
    return is_valid_input;
}

int check_if_files_exist(int number_of_files, char filenames[NMAX][NMAX]) {
    int files_exist = TRUE, index = 0;
    FILE *file;
    while (files_exist && index != number_of_files) {
        printf("all_text_files[index] = %s \n", filenames[index]);
        if (((file = fopen(filenames[index], "r")) == NULL)) {
            files_exist = FALSE;
        } else {
            fclose(file);
            ++index;
        }
    }
    return files_exist;
}

int check_if_flags_are_valid(int counter_for_flags, char all_flags_array[NMAX][NMAX]) {
    int flags_are_valid = TRUE;
    while (flags_are_valid == TRUE) {
        for (int index_all_flags = 0; index_all_flags <= counter_for_flags; ++index_all_flags) {
            for (int index_possible_flags = 0; index_possible_flags < NUMBER_OF_FLAG_VALUES; ++index_possible_flags) {
                if (strcmp(all_flags_array[index_all_flags], possible_flags[index_possible_flags]) != 0) {
                    flags_are_valid = FALSE;
                }
            }
        }
    }
    return flags_are_valid;
}

void initialize_flags(Flags* flags) {
    flags->b = FALSE;
    flags->s = FALSE;
    flags->n = FALSE;
    flags->e = FALSE;
    flags->E = FALSE;
    flags->T = FALSE;
    flags->t = FALSE;
}
