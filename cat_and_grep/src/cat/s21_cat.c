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

void print_arguments(int argument_counter, char arguments[NMAX][NMAX]) {
    for (int index = 0; index < argument_counter; ++index) {
        printf("%d ----- %s\n", index, arguments[index]);
    }
}

int main(int argc, char *argv[]) {
    Flags flags;
    initialize_flags(&flags);
    if (check_start_conditions(argc, argv)) {
        printf("Success");
    } else {
        printf("Fail");
    }
    return 0;
}

int check_start_conditions(int argc, char *argv[]) {
// int check_start_conditions(int argc, char **argv) {
    int conditions = FALSE;
    // Condition to check if theree are flags and a text-file
    // Parse flags() should return TRUE or FALSE if the flags are valid or they are not valid
    // Here also should be a check if file exists 
    if (argc >= 2 && parse_flags_and_text_files(argc, argv)) {
    // if (argc >= 2 && parse_flags_and_text_files(argc, (char**)argv)) {
        conditions = TRUE;
    }
    return conditions;
}

int parse_flags_and_text_files(int argc, char *argv[]) {
// int parse_flags_and_text_files(int argc, char **argv) {
    int is_valid_input = FALSE, letter_index = 0;
    // Create an array for all the flags - valid and invalid to sort them out later
    char all_flags_array[NMAX][NMAX];
    // And an array for text-file names - valid and invalid to sort later
    char all_text_files_array[NMAX][NMAX];
    // Here we have two-dimensional array first loop is going to iterate over elements of array
    // Counters to know when to stop in iterating over the arrays
    int counter_for_flags = 0, counter_for_text_files = 0;
    for (int element_index = 1; element_index < argc; ++element_index) {
        if (argv[element_index][letter_index] == '-') {
            strcpy(all_flags_array[counter_for_flags], argv[element_index]);
            // strcpy((char*)all_flags_array[counter_for_flags], argv[element_index]);
            ++counter_for_flags;
        } else {
            strcpy(all_text_files_array[counter_for_text_files], argv[element_index]);
            // strcpy((char*)all_text_files_array[counter_for_text_files], argv[element_index]);
            ++counter_for_text_files;
        }
    }
    if (argc == 2) {
        if (check_if_files_exist(counter_for_text_files, all_text_files_array)) {
        // if (check_if_files_exist(counter_for_text_files, (char**)all_text_files_array)) {
            is_valid_input = TRUE;
        }
    } else {
        if (check_if_flags_are_valid(counter_for_flags, all_flags_array) &&
        check_if_files_exist(counter_for_text_files, all_text_files_array)) {
        // if (check_if_flags_are_valid(counter_for_flags, (char**)all_flags_array) /*&&
        // check_if_files_exist(counter_for_text_files, (char**)all_text_files_array)*/) {
            is_valid_input = TRUE;
        }
    }
    return is_valid_input;
}

int check_if_files_exist(int number_of_files, char filenames[NMAX][NMAX]) {
// int check_if_files_exist(int number_of_files, char** filenames) {
    int files_exist = TRUE, index = 0;
    FILE *file = NULL;
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

int get_length(const char* string) {
    if (!string)
        return 0;
    int length = 0;
    while(string[length] != '\0') 
        ++length;
    return length;
}

int are_not_equal(const char* string1, const char* string2) {
    // while ((string1 != NULL) && (string2 != NULL) && (*string1 != '\0') && (*string2 != '\0') && (*string1 == *string2))
    const int length1 = get_length(string1);
    const int length2 = get_length(string2);

    int result = FALSE;
    if (length1 != length2)
        result = TRUE;

    if (result == FALSE) {
        for (int index = 0; index < length1; ++index) {
            if (string1[index] != string2[index]) {
                result = TRUE;
                break;
            }
        }
    }

    return result;
}
int are_equal(const char* string1, const char* string2) {
    return !are_not_equal(string1, string2);
}
int is_in_possible_flags(const char *current_flag) {
    int result = FALSE;
    for (int index_flag = 0; index_flag < TOTAL_NUMBER_OF_FLAGS; ++index_flag) {
        if (are_equal(current_flag, possible_flags[index_flag])) {
            result = TRUE;
            break;
        }
    }
    return result;
}

int check_if_flags_are_valid(int counter_for_flags, char all_flags_array[NMAX][NMAX]) {
// int check_if_flags_are_valid(int counter_for_flags, char** all_flags_array) {
    int flags_are_valid = TRUE, index = 0;
    while (flags_are_valid == TRUE && index != counter_for_flags) {
        flags_are_valid = is_in_possible_flags(all_flags_array[index]);
        // flags_are_valid = is_in_possible_flags((char*)all_flags_array[index]);
        ++index;
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
