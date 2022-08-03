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
    if (check_start_conditions(argc, argv, &flags, &data)) {
        pass_flags_to_structure(&flags, &data);
        print_result(&flags, &data);
    } else {
        print_error_message(&data, "Flags were not valid");
    }
    return 0;
}

void print_result(Flags const* flags, Data* data) {
    const int number_of_files = data->number_of_files;
    // If -f then index_for_files++ else index_for_files = 0 
    // So I don't open the file with patterns
    int index_for_files = 0;
    index_for_files = flags->f ? 1 : 0;
    // If file with patterns doesn't exist, even if "-s" error is thrown and grep doesn't run
    int should_run = FALSE;
    if (flags->f) {
        should_run = check_if_files_exist(0, data);
    }
    if (should_run) {
        for (index_for_files; index_for_files < number_of_files; ++index_for_files) {
            if (check_if_files_exist(index_for_files, data)) {
                FILE *file = fopen(data->all_filenames_array[index_for_files], "r");
                handle_flags(file, flags, data, index_for_files);
            } else {
                print_error_message(data, "File doesn't exist");
            }
        }
    } else {
        print_error_message(data, "Pattern file doesn't exist");
    }
}

void handle_flags(FILE *file, Flags const* flags, Data* data, const int index_for_files) {
    while (parse_line(file, data)) {
    // Here I pass a boolean value of print_line, change it to TRUE of FALSE
    // Based on the current flags that are in power and print or not to print the line in the end
    if (flags->e) {
        handle_e(data);
    }
    if (flags->i) {
        handle_i(data);
    }
    if (flags->v) {
        handle_v(data);
    }
    // Print the line in the end if it was found
    if (data->line_should_be_printed) {
        // Don't print if -c and count the lines to be printed
        if (flags->c) {
            handle_c(data);
        } else {
            filenames_should_be_printed(data);
            if (flags->h) {
                handle_h(&data->filename_should_be_printed);
            }
            if (data->filename_should_be_printed && !flags->l) {
                print_filename(index_for_files, data, data->colon);
            }
            if (flags->n) {
                handle_n(data->number_of_the_line);
            }
            if (!flags->l) {
                print_line(data);
                data->line_should_be_printed = FALSE;
            }
        }
    }
    }
    if (flags->c) {
        filenames_should_be_printed(data);
        if (data->filename_should_be_printed && !flags->l) {
            print_filename(index_for_files, data, data->colon);
        }
        print_number_of_matching_lines(data);
    }
    if (flags->l) {
        handle_l(index_for_files, data);
    }
    reset_num_values(data);
}
// Should use handle_e function as it already uses regex and can take regular expressions
// int handle_f(FILE* file, Data const* data) {
//     int does_file_exist = FALSE;
//     if (check_if_files_exist(0,data)) {
//         does_file_exist = TRUE;
//         while (parse_line(file, data)) {
//             handle_e(data);
//         }
//     }
//     return does_file_exist;
// }

// TODO: Probably should remove the function for flags
// Library grep doesn't ignore incorrect flags
void print_error_message(Data const* data, char* error_message) {
    if (!data->error_message_should_be_printed) {
        fprintf(stderr, "%s\n", error_message);
    }
}

void handle_s(int* error_message_should_be_printed) {
    *error_message_should_be_printed = !*error_message_should_be_printed;
}

void handle_h(int* filenames_should_be_printed) {
    *filenames_should_be_printed = !*filenames_should_be_printed;
}

void reset_num_values(Data* data) {
    data->number_of_the_line = 0;
    data->number_of_matching_lines = 0;
}

void reset_line_values(Data* data) {
    memset(data->line_array, 0, MAX_LENGHT_OF_LINE * sizeof(char));
    memset(data->line_array_copy, 0, MAX_LENGHT_OF_LINE * sizeof(char));
}

void print_number_of_the_line(const int line_number) {
    printf("%d:", line_number);
}

void handle_n(const int line_number) {
    print_number_of_the_line(line_number);
}

void handle_l(const int index_for_files, Data const* data) {
    if (data->pattern_found_in_the_file) {
        print_filename(index_for_files, data, data->newline);
    }
}

void print_line(Data const* data) {
    printf("%s", data->line_array);
}

void filenames_should_be_printed(Data* data) {
    data->filename_should_be_printed = data->number_of_files > 1 ? TRUE : FALSE;
}

void print_filename(const int index_for_files, Data const* data, char custom_char) {
    printf("%s%c", data->all_filenames_array[index_for_files], custom_char);
}

void print_number_of_matching_lines(Data const* data) {
    printf("%d\n", data->number_of_matching_lines);
}

void handle_c(Data* data) {
    if (data->line_should_be_printed) {
        ++data->number_of_matching_lines;
        data->line_should_be_printed = FALSE;
    }
}

void handle_v(Data* data) {
    data->line_should_be_printed = !compare_strings(data);
}

void handle_i(Data* data) {
    int line_lenght = 0, pattern_lenght = 0;
    line_lenght = strlen(data->line_array);
    pattern_lenght = strlen(data->pattern_array);
    // Erase the array before I use it again
    memset(data->line_array_copy, 0, MAX_LENGHT_OF_LINE * sizeof(char));
    for (int index = 0; index <= line_lenght; ++ index) {
        data->line_array_copy[index] = tolower(data->line_array[index]);
    }
    for (int index = 0; index <= pattern_lenght; ++ index) {
        data->pattern_array[index] = tolower(data->pattern_array[index]);
    }
    data->line_should_be_printed = compare_strings(data);
}

void handle_e(Data* data) {
    data->line_should_be_printed = compare_strings(data);
}

int compare_strings(Data* data) {
    int are_equal = FALSE;
    regex_t reegex;
    int compare_result = regcomp(&reegex, data->pattern_array, 0);
    compare_result = regexec(&reegex, data->line_array_copy, 0, NULL, 0);
    if (!compare_result) {
        are_equal = TRUE;
        if (!data->pattern_found_in_the_file) {
            data->pattern_found_in_the_file = TRUE;
        }
    }
    regfree(&reegex);
    return are_equal;
}

int parse_line(FILE *file, Data* data) {
    // Erase the line before I write the array again
    reset_line_values(data);
    ++data->number_of_the_line;
    int can_be_parsed = TRUE, going_to_be_printed = FALSE, index = 0, current_character = 0;
    while (can_be_parsed && current_character != EOF) {
        current_character = fgetc(file);
        if (current_character == EOF || current_character == data->newline) {
            can_be_parsed = FALSE;
            if (current_character == data->newline) {
                data->line_array[index] = current_character;
                ++index;
            }
        } else {
            data->line_array[index] = current_character;
            ++index;
        }
    }
    if (index) {
        going_to_be_printed = TRUE;
    }
    // Copy regular line to copy. Copy is going to be compared as it changes when flags are applied
    // Regular array gets printed as it is the condition
    memcpy(data->line_array_copy, data->line_array, index);
    return going_to_be_printed;
}

int check_start_conditions(const int argc, char *argv[], Flags* flags, Data* data) {
    int conditions = FALSE;
    // Condition to check if there are flags and text-files
    // Parse flags() should return TRUE or FALSE if the flags are valid or not
    // And the files exist
    if (argc >= 4 && parse_flags_patterns_filenames(argv, flags, data)) {
        conditions = TRUE;
    }
    return conditions;
}

int parse_flags_patterns_filenames(char *argv[], Flags* flags, Data* data) {
    int is_valid_input = FALSE;
    // Counters to know when to stop in iterating over the arrays
    int counter_for_flags = 0;
    // Iterate over the argv to sort out flags, pattern and filenames
    int element_index = 1;
    parse_flags(argv, flags, data, &counter_for_flags, &element_index);
    // When first index of argv element != '-' read the first pattern (for -e -f) and then the rest may be continuation of flags and the filenames
    // Write to the array of patters only if the pattern wasn't written previously
    if (data->pattern_array[0] == 0) {
        parse_pattern(data, argv, &element_index);
    }
    // Parse flags in case of -e pattern -c filename
    parse_flags(argv, flags, data, &counter_for_flags, &element_index);
    // Parse filenames to the array of filenames
    parse_filenames(flags, data, argv, &element_index);
    if (check_if_flags_are_valid(counter_for_flags, flags, data)) {
            is_valid_input = TRUE;
    }
    // Parse the patterns from the filename here for -f flag
    // Flags->f value is set in the parse flags function prior to this call
    if (flags->f) {
        parse_patterns_handle_f(flags, data);
    }
    return is_valid_input;
}

void parse_patterns_handle_f(Flags const* flags, Data* data) {
    FILE *file = NULL;
    int first_file = 0;
    if ((file = fopen(data->all_filenames_array[first_file], "r")) == NULL) {
        // Probably excessive print error message. I already perform this check in print result
        // Should test this later
        print_error_message(data, "Pattern file doesn't exist");
    } else {
        char temp_pattern_array[MAX_LENGHT_OF_PATTERN];
        memset(temp_pattern_array, 0, MAX_LENGHT_OF_PATTERN * sizeof(char));
        int char_index = 0, pattern_array_index = 0, current_character = 0;
        pattern_array_index = flags->e ? 1 : 0;
        while (current_character != EOF) {
            current_character = fgetc(file);
            if (current_character != data->newline) {
                temp_pattern_array[char_index] = current_character;
                ++char_index;
            }
            if (current_character == data->newline) {
                strcpy(data->pattern_array[pattern_array_index], temp_pattern_array);
                char_index = 0;
                ++pattern_array_index;
            }
        }
    }
    fclose(file);
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
        } else if (!strcmp(data->all_flags_array[index], "-h")) {
            flags->h = TRUE;
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

int check_if_flags_are_valid(const int counter_for_flags, Flags* flags, Data* data) {
    int flags_are_valid = FALSE, index_all_flags = 0, number_of_valid_flags = 0;
    while (index_all_flags != counter_for_flags) {
        for (int index_possible_flags = 0;
        index_possible_flags < TOTAL_NUM_FLAGS; ++index_possible_flags) {
            // If flag == '-s', don't display errors
            if (!strcmp(data->all_flags_array[index_all_flags], "-s")) {
                flags->s = TRUE;
                handle_s(&data->error_message_should_be_printed);
            }
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

void parse_pattern(Data* data, char *argv[], int* element_index) {
    strcpy(data->pattern_array[data->pattern_index], argv[*element_index]);
    ++data->pattern_index;
    ++*element_index;
}

void parse_flags(char *argv[], Flags* flags, Data* data, int* counter_for_flags, int* element_index) {
    int letter_index = 0, is_previous_e_flag = FALSE;
    // TODO: For -enslh input changes the while condition. It can be a passed character or
    // You can use || condition. '-' or one of the possible flags in a row, without anything else
    while (argv[*element_index][letter_index] == '-') {
        // When flag is -e and the pattern starts with '-', it should be read to the pattern array
        if (!strcmp(argv[*element_index], "-e")) {
            is_previous_e_flag = TRUE;
            flags->e = TRUE;
        }
        if (!strcmp(argv[*element_index], "-f")) {
            flags->f = TRUE;
        }
        strcpy(data->all_flags_array[*counter_for_flags], argv[*element_index]);
        ++*counter_for_flags;
        ++*element_index;
        // The pattern is being copied to the array of patterns in case the previous flag was -e
        if (is_previous_e_flag) {
            parse_pattern(data, argv, element_index);
            is_previous_e_flag = FALSE;
        }
    }
}

void parse_filenames(Flags* flags, Data* data, char *argv[], int* element_index) {
    while (argv[*element_index]) {
        // TODO: If -f parse with filename to the array of the flags 
        if (flags->f) {

        }
        strcpy(data->all_filenames_array[data->number_of_files], argv[*element_index]);
        ++data->number_of_files;
        ++*element_index;
    }
}

void initialize_data(Data* data) {
    memset(data->all_flags_array, 0, TOTAL_NUM_FLAGS * sizeof(char));
    memset(data->all_filenames_array, 0, TOTAL_NUM_FILENAMES * sizeof(char));
    memset(data->pattern_array, 0, MAX_NUM_OF_PATTERNS * sizeof(char));
    data->pattern_index = 0;
    memset(data->line_array, 0, MAX_LENGHT_OF_LINE * sizeof(char));
    memset(data->line_array_copy, 0, MAX_LENGHT_OF_LINE * sizeof(char));
    data->number_of_files = 0;
    data->number_of_the_line = 0;
    data->newline = '\n';
    data->colon = ':';
    data->line_should_be_printed = FALSE;
    data->filename_should_be_printed = FALSE;
    data->number_of_matching_lines = 0;
    data->pattern_found_in_the_file = FALSE;
}

void initialize_flags(Flags* flags) {
    flags->e = FALSE;
    flags->i = FALSE;
    flags->v = FALSE;
    flags->c = FALSE;
    flags->l = FALSE;
    flags->n = FALSE;
    flags->h = FALSE;
    flags->s = FALSE;
}
