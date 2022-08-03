#ifndef SRC_S21_GREP_H
#define SRC_S21_GREP_H

#include <stdio.h>
#include <string.h>
// Used for tolower function
#include <ctype.h>
#include <regex.h>

#define TOTAL_NUM_FLAGS 10
#define MAX_LENGHT_OF_FLAG 5
#define TOTAL_NUM_FILENAMES 50
#define MAX_LENGHT_OF_FILENAME 100
#define MAX_NUM_OF_PATTERNS 50
#define MAX_LENGHT_OF_PATTERN 30
#define MAX_LENGHT_OF_LINE 500

enum true_of_false{
    FALSE,
    TRUE
};
// TODO: NULL flag implementation
static const char possible_flags[TOTAL_NUM_FLAGS][MAX_LENGHT_OF_FLAG] = {
    "-e", "-i", "-v", "-c", "-l", "-n", "-h", "-s", "-f", "NULL"
};

typedef struct Flags {
    int e;  // Pattern
    int i;  // Ignore uppercase and lowercase
    int v;  // Inverted match
    int c;  // Output count of matching lines only
    int l;  // Output matching files only
    int n;  // Precede each matching line with a line number
    int h;  // Output matching lines without preceding them by file names
    int s;  // Suppress error messages about nonexistent or unreadable files
    int f;  // Take regexes from a file
//    int o;  // Output the matched parts of a matching line
} Flags;

typedef struct Data {
    // An array to keep all of the flags valid and invalid to sort them out later
    char all_flags_array[TOTAL_NUM_FLAGS][MAX_LENGHT_OF_FLAG];
    // And an array for filenames. Valid and invalid. Going to sort them out later
    char all_filenames_array[TOTAL_NUM_FILENAMES][MAX_LENGHT_OF_FILENAME];
    // Array to store patterns for -e and -f 
    char pattern_array[MAX_LENGHT_OF_PATTERN][MAX_NUM_OF_PATTERNS];
    int pattern_index;
    // Array to hold the current line
    char line_array[MAX_LENGHT_OF_LINE];
    // Copy is going to be compared as it changes when flags are applied
    char line_array_copy[MAX_LENGHT_OF_LINE];
    int number_of_files;
    int line_should_be_printed;
    int filename_should_be_printed;
    int error_message_should_be_printed;
    int number_of_matching_lines;
    int number_of_matched_files;
    int number_of_the_line;
    int pattern_found_in_the_file;
    char newline, colon;
} Data;

void initialize_flags(Flags* flags);
void initialize_data(Data* data);
int check_start_conditions(const int argc, char *argv[], Flags* flags, Data* data);
int parse_flags_patterns_filenames(char *argv[], Flags* flags, Data* data);
void parse_flags(char *argv[], Flags* flags, Data* data, int* counter_for_flags, int* element_index);
void parse_pattern(Data* data, char *argv[], int* element_index);
void parse_filenames(Flags* flags, Data* data, char *argv[], int* element_index);
int check_if_flags_are_valid(const int counter_for_flags, Flags* flags, Data* data);
int check_if_files_exist(const int filename_index, Data const* data);
void pass_flags_to_structure(Flags* flags, Data const* data);
void print_result(Flags const* flags, Data* data);
void handle_flags(FILE *file, Flags const* flags, Data* data, const int index_for_files);
int parse_line(FILE *file, Data* data);
int compare_strings(Data* data);
void filenames_should_be_printed(Data* data);
void print_filename(const int index_for_files, Data const* data, char custom_char);
void print_number_of_matching_lines(Data const* data);
void print_line(Data const* data);
void print_number_of_the_line(const int line_number);
void print_error_message(Data const* data, char* error_message);
void reset_num_values(Data* data);
void reset_line_values(Data* data);
void handle_e(Data* data);
void handle_i(Data* data);
void handle_v(Data* data);
void handle_c(Data* data);
void handle_l(const int index_for_files, Data const* data);
void handle_n(const int line_number);
void handle_h(int* filenames_should_be_printed);
void handle_s(int* error_message_should_be_printed);
// int handle_f(FILE* file, Data const*data);
void parse_patterns_handle_f(Flags const* flags, Data* data);

#endif  // SRC_S21_GREP_H