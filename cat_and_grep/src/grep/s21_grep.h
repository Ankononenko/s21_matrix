#ifndef SRC_S21_GREP_H
#define SRC_S21_GREP_H

#include <stdio.h>
#include <string.h>
// Used for tolower function
#include <ctype.h>

#define TOTAL_NUM_FLAGS 7
#define MAX_LENGHT_OF_FLAG 5
#define TOTAL_NUM_FILENAMES 50
#define MAX_LENGHT_OF_FILENAME 30
#define MAX_LENGHT_OF_PATTERN 30
#define MAX_LENGHT_OF_LINE 50

enum true_of_false{
    FALSE,
    TRUE
};

static const char possible_flags[TOTAL_NUM_FLAGS][MAX_LENGHT_OF_FLAG] = {
    "-e", "-i", "-v", "-c", "-l", "-n", "NULL"
};

typedef struct Flags {
    int e;
    int i;
    int v;
    int c;
    int l;
    int n;
} Flags;

typedef struct Data {
    // An array to keep all of the flags valid and invalid to sort them out later
    char all_flags_array[TOTAL_NUM_FLAGS][MAX_LENGHT_OF_FLAG];
    // And an array for filenames. Valid and invalid. Going to sort them out later
    char all_filenames_array[TOTAL_NUM_FILENAMES][MAX_LENGHT_OF_FILENAME];
    // Array to store the patterns
    char pattern_array[MAX_LENGHT_OF_PATTERN];
    // Array to hold the current line
    char line_array[MAX_LENGHT_OF_LINE];
    int number_of_files;
    int want_to_print_line;
    char newline;
} Data;

void initialize_flags(Flags* flags);
void initialize_data(Data* data);
int check_start_conditions(const int argc, char *argv[], Data* data);
int parse_flags_patterns_filenames(char *argv[], Data* data);
void parse_flags(char *argv[], Data* data, int* counter_for_flags, int* element_index);
void parse_pattern(Data* data, char *argv[], int* element_index);
void parse_filenames(Data* data, char *argv[], int* element_index);
int check_if_flags_are_valid(const int counter_for_flags, Data const* data);
int check_if_files_exist(const int filename_index, Data const* data);
void pass_flags_to_structure(Flags* flags, Data const* data);
void print_result(Flags const* flags, Data* data);
int parse_line(FILE *file, Data* data);
void handle_e(Data* data);
void handle_l(Data* data);

#endif  // SRC_S21_GREP_H