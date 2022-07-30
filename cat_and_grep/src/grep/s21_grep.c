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
        pass_flags_to_structure(&flags, &data);
        print_result(/* &flags, */ &data);
    } else {
        fprintf(stderr, "Flags were not valid \n");
    }
    return 0;
}

void print_result(/*Flags const* flags, */ Data* data) {
    for (int index_for_files = 0; index_for_files < data->number_of_files; ++index_for_files) {
        if (check_if_files_exist(index_for_files, data)) {
            FILE *file = fopen(data->all_filenames_array[index_for_files], "r");
            while (parse_line(file, data)) {
                int index = 0;
                while (data->line_array[index] != '\0') {
                    printf("%c", data->line_array[index]);
                    ++index;
                }
                printf("\n");
            }
            printf("EOF \n");
        } else {
            // Error message when a file doesn't exist
            fprintf(stderr, "File doesn't exist \n");
        }
    }
}

int parse_line(FILE *file, Data* data) {
    int can_be_parsed = TRUE, index = 0, current_character = fgetc(file);
    while (current_character != data->newline) {
        data->line_array[index] = current_character;
        ++index;
        current_character = fgetc(file);
        if (current_character == EOF) {
            can_be_parsed = FALSE;
        }
    }
    return can_be_parsed;
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

int parse_flags_patters_filenames(char *argv[], Data* data) {
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

void pass_flags_to_structure(Flags* flags, Data const* data) {
    int index = 0;
    // Until it is the end of the two-dimensional array,
    // I iterate over it and pass the values to the Flags structure
    // strcmp returns 0 if the values are equal, so I use !(not) to invert the value of zero to true
    while (strcmp(data->all_flags_array[index], "\0")) {
        if (!strcmp(data->all_flags_array[index], "-e")) {
            flags->e = TRUE;
        } else if (!strcmp(data->all_flags_array[index], "-i")) {
            flags->i = TRUE;
        } else if (!strcmp(data->all_flags_array[index], "-v")) {
            flags->v = TRUE;
        } else if (!strcmp(data->all_flags_array[index], "-c")) {
            flags->c = TRUE;
        } else if (!strcmp(data->all_flags_array[index], "-l")) {
            flags->l = TRUE;
        } else if (!strcmp(data->all_flags_array[index], "-n")) {
            flags->n = TRUE;
        }
        ++index;
    }
}

int check_if_files_exist(const int filename_index, Data const* data) {
    int files_exist = TRUE;
    FILE *file = NULL;
    if ((file = fopen(data->all_filenames_array[filename_index], "r")) == NULL) {
        files_exist = FALSE;
    } else {
        fclose(file);
    }
    return files_exist;
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
    memset(data->line_array, 0, MAX_LENGHT_OF_LINE * sizeof(char));
    data->number_of_files = 0;
    data->newline = '\n';
}

void initialize_flags(Flags* flags) {
    flags->e = FALSE;
    flags->i = FALSE;
    flags->v = FALSE;
    flags->c = FALSE;
    flags->l = FALSE;
    flags->n = FALSE;
}
