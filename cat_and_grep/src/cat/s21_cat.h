#ifndef SRC_S21_CAT_H_
#define SRC_S21_CAT_H_

#include <stdio.h>
#include <string.h>

#define TOTAL_NUMBER_OF_FLAGS 11
#define MAX_LENGTH_OF_FLAG 18
#define NMAX 20

enum true_of_false{
    FALSE,
    TRUE
};

static const char possible_flags[TOTAL_NUMBER_OF_FLAGS][MAX_LENGTH_OF_FLAG] = {
    "-b", "--number-nonblank", "-e", "-E",
    "-n", "--number", "-s", "--squeeze-blank", "-t", "-T", "NULL"
};

typedef struct Flags {
    int b;
    int s;
    int n;
    int e;
    int E;
    int T;
    int t;
} Flags;

// int check_start_conditions(int argc, char *argv[]);
int check_start_conditions(int argc, char** argv);
void initialize_flags(Flags* flags);
// int parse_flags_and_text_files(int argc, char *argv[]);
int parse_flags_and_text_files(int argc, char** argv);
// int check_if_flags_are_valid(int counter_for_flags, char all_flags_array[NMAX][NMAX]);
int check_if_flags_are_valid(int counter_for_flags, char** all_flags_array);
// int check_if_files_exist(int number_of_files, char filenames[NMAX][NMAX]);
int check_if_files_exist(int number_of_files, char** filenames);

#endif  // SRC_S21_CAT_H_