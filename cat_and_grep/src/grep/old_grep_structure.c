#include "s21_grep.h"
// TODO: grep pattern file
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
