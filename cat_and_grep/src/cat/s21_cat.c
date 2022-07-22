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

// For testing. Need to delete that function later
void print_arguments(int argument_counter, char arguments[NMAX][NMAX]) {
    for (int index = 0; index < argument_counter; ++index) {
        printf("Index = %d ----- element of the array = %s\n", index, arguments[index]);
    }
}

// For testing. Should be deleted later:
void test_flags(Flags* flags) {
    if (flags->b == TRUE) {
        printf("-b = TRUE \n");
    } else {
        printf("-b = FALSE \n");
    }
    if (flags->s == TRUE) {
        printf("-s = TRUE \n");
    } else {
        printf("-s = FALSE \n");
    }
    if (flags->n == TRUE) {
        printf("-n = TRUE \n");
    } else {
        printf("-n = FALSE \n");
    }
    if (flags->e == TRUE) {
        printf("-e = TRUE \n");
    } else {
        printf("-e = FALSE \n");
    }
    if (flags->E == TRUE) {
        printf("-E = TRUE \n");
    } else {
        printf("-E = FALSE \n");
    }
    if (flags->T == TRUE) {
        printf("-T = TRUE \n");
    } else {
        printf("-T = FALSE \n");
    }
    if (flags->t == TRUE) {
        printf("-t = TRUE \n");
    } else {
        printf("-t = FALSE \n");
    }
}

int main(int argc, char *argv[]) {
    Flags flags;
    initialize_flags(&flags);
    Data data;
    initialize_data(&data);
    if (check_start_conditions(argc, argv, &data)) {
        pass_flags_to_structure(&flags, &data);
        print_result(&flags, &data);
    } else {
        // Should be replaced with output to stderr
        printf("Fail \n");
    }
    return 0;
}

void print_result(Flags* flags, Data* data) {
    int index = 0;
    FILE *file = fopen(data->all_text_files_array[index], "r");
    while (index != 1) {    
        if (flags->b) {
            handle_b(file);
        }
        ++index;
    }
    fclose(file);
}

void handle_b(FILE* file) {
    char first_character = '\0', second_character = '\0', newline = '\n';
    char temp_array[NMAX];
    int ordinal_number = 1, index = 0;
    second_character = fgetc(file);
    while (second_character != EOF) {
        first_character = second_character;
        second_character = fgetc(file);
        if (first_character == newline && second_character != newline) {
            printf("%6d\t", ordinal_number);
            ++ordinal_number;
            printf("%s\n", temp_array);
            memset(temp_array, '\0', NMAX);
            index = 0;
        } else {
            // Write chars to temp array to print later
            temp_array[index] = first_character;
            ++index;
        }
    }
}

int check_start_conditions(int argc, char *argv[], Data* data) {
    int conditions = FALSE;

    // Condition to check if there are flags and text-files
    // Parse flags() should return TRUE or FALSE if the flags are valid or not
    // And the files exist

    if (argc >= 2 && parse_flags_and_text_files(argc, argv, data)) {
        conditions = TRUE;
    }

    return conditions;
}

void pass_flags_to_structure(Flags* flags, Data* data) {
    int index = 0;
    // Until it is the end of the two-dimensional array, I iterate over it and pass the values to the Flags structure
    // strcmp returns 0 if the values are equal, so I use !(not) to invert the value of zero to true
    while (strcmp(data->all_flags_array[index], "\0")) {
        if (!strcmp(data->all_flags_array[index], "-b") || !strcmp(data->all_flags_array[index], "--number-nonblank")) {
            flags->b = TRUE;
        } else if (!strcmp(data->all_flags_array[index], "-e")) {
            flags->e = TRUE;
        } else if (!strcmp(data->all_flags_array[index], "-E")) {
            flags->E = TRUE;
        } else if (!strcmp(data->all_flags_array[index], "-n") || !strcmp(data->all_flags_array[index], "--number")) {
            flags->n = TRUE;
        } else if (!strcmp(data->all_flags_array[index], "-s") || !strcmp(data->all_flags_array[index], "--squeeze-blank")) {
            flags->s = TRUE;
        } else if (!strcmp(data->all_flags_array[index], "-t")) {
            flags->t = TRUE;
        } else if (!strcmp(data->all_flags_array[index], "-T")) {
            flags->T = TRUE;
        }
        // Here I should work with NULL but I'm not sure how to handle that case
        ++index;
    }
}

int parse_flags_and_text_files(int argc, char *argv[], Data* data) {
    int is_valid_input = FALSE, letter_index = 0;
    // Counters to know when to stop in iterating over the arrays
    int counter_for_flags = 0, counter_for_text_files = 0;
    // Iterate over the argv to sort out flags from files

    for (int element_index = 1; element_index < argc; ++element_index) {
        if (argv[element_index][letter_index] == '-') {
            strcpy(data->all_flags_array[counter_for_flags], argv[element_index]);
            ++counter_for_flags;
        } else {
            strcpy(data->all_text_files_array[counter_for_text_files], argv[element_index]);
            ++counter_for_text_files;
        }
    }

    if (argc == 2 && counter_for_text_files) {
        if (check_if_files_exist(counter_for_text_files, data)) {
            is_valid_input = TRUE;
        }
    } else {
        if (check_if_flags_are_valid(counter_for_flags, data) &&
        check_if_files_exist(counter_for_text_files, data)) {
            is_valid_input = TRUE;
        }
    }

    return is_valid_input;
}

int check_if_files_exist(int number_of_files, Data* data) {
    int files_exist = TRUE, index = 0;
    FILE *file = NULL;

    while (files_exist && index != number_of_files) {
        if (((file = fopen(data->all_text_files_array[index], "r")) == NULL)) {
            files_exist = FALSE;
        } else {
            fclose(file);
            ++index;
        }
    }

    return files_exist;
}

int check_if_flags_are_valid(int counter_for_flags, Data* data) {
    
    int flags_are_valid = FALSE, index_all_flags = 0, number_of_valid_flags = 0;
    
    while (index_all_flags != counter_for_flags) {

        for (int index_possible_flags = 0; index_possible_flags < TOTAL_NUMBER_OF_FLAGS; ++index_possible_flags) {
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

void initialize_flags(Flags* flags) {
    flags->b = FALSE;
    flags->s = FALSE;
    flags->n = FALSE;
    flags->e = FALSE;
    flags->E = FALSE;
    flags->T = FALSE;
    flags->t = FALSE;
}

void initialize_data(Data* data) {
    memset(data->all_flags_array, '\0', NMAX *sizeof(char));
    memset(data->all_text_files_array, '\0', NMAX *sizeof(char));
}