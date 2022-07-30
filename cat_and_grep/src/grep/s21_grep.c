// Copyright 2022 finchren
/*

You need to develop the grep utility:

Support of the following flags: -e, -i, -v, -c, -l, -n
Only pcre or regex libraries can be used for regular expressions
The source, header and make files must be placed in the src/grep/ directory
The resulting executable file must be placed in the directory src/grep/ and named s21_grep

*/

#include "s21_grep.h"

int main(int argc, char *argv[]) {
    Flags flags = {0};
    initialize_flags(&flags);
    Data data = {0};
    initialize_data(&data);
    if (check_start_conditions(argc, argv, &data)) {
        printf("Success");
    } else {
        fprintf(stderr, "Flags were not valid \n");
    }
    return 0;
}

int check_start_conditions(const int argc, char *argv[], Data* data) {
    int conditions = FALSE;
    // Condition to check if there are flags and text-files
    // Parse flags() should return TRUE or FALSE if the flags are valid or not
    // And the files exist
    if (argc >= 4 && parse_flags_patters_filenames(/*argc, */argv, data)) {
        conditions = TRUE;
    }
    return conditions;
}

int parse_flags_patters_filenames(/*const int argc, */char *argv[], Data* data) {
    int is_valid_input = FALSE;
    // Counters to know when to stop in iterating over the arrays
    int counter_for_flags = 0;
    // Iterate over the argv to sort out flags, pattern and filenames
    int element_index = 1;
    parse_flags(argv, data, &counter_for_flags, &element_index);
    // When first index of argv element != '-' read the first pattern (for -e -f) and then the rest may be continuation of flags and the filenames
    strcpy(data->patters_array, argv[element_index]);
    ++element_index;
    // Parse flags in case of -e pattern -c filename
    parse_flags(argv, data, &counter_for_flags, &element_index);
    while (argv[element_index]) {
        strcpy(data->all_filenames_array[data->number_of_files], argv[element_index]);
        ++data->number_of_files;
        ++element_index;
    }
    if (check_if_flags_are_valid(counter_for_flags, data)) {
            is_valid_input = TRUE;
    }
    return is_valid_input;
}

int check_if_flags_are_valid(const int counter_for_flags, Data const* data) {
    int flags_are_valid = FALSE, index_all_flags = 0, number_of_valid_flags = 0;
    while (index_all_flags != counter_for_flags) {
        for (int index_possible_flags = 0;
        index_possible_flags < TOTAL_NUM_FLAGS; ++index_possible_flags) {
            if (!strcmp(data->all_flags_array[index_all_flags], possible_flags[index_possible_flags])) {
                ++number_of_valid_flags;
            }
        }
        ++index_all_flags;
    }
    if (counter_for_flags == number_of_valid_flags) {
        flags_are_valid = TRUE;
    }
    return flags_are_valid;
}

void parse_flags(char *argv[], Data* data, int* counter_for_flags, int* element_index) {
    int letter_index = 0;
    while (argv[*element_index][letter_index] == '-') {
        strcpy(data->all_flags_array[*counter_for_flags], argv[*element_index]);
        ++*counter_for_flags;
        ++*element_index;
    }
}

void initialize_data(Data* data) {
    memset(data->all_flags_array, 0, TOTAL_NUM_FLAGS * sizeof(char));
    memset(data->all_filenames_array, 0, TOTAL_NUM_FILENAMES * sizeof(char));
    memset(data->patters_array, 0, MAX_LENGHT_OF_PATTERN * sizeof(char));
    data->number_of_files = 0;   
}

void initialize_flags(Flags* flags) {
    flags->e = FALSE;
    flags->i = FALSE;
    flags->v = FALSE;
    flags->c = FALSE;
    flags->l = FALSE;
    flags->n = FALSE;
}
