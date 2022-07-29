#ifndef SRC_S21_GREP_H
#define SRC_S21_GREP_H

#define TOTAL_NUM_FLAGS_GREP 7
#define MAX_LENGHT_OF_FLAG_GREP 5
#define TOTAL_NUM_FILENAMES 50
#define MAX_LENGHT_OF_FILENAME 30

#include "../cat/s21_cat.h"

static const char possible_flags_grep[TOTAL_NUM_FLAGS_GREP][MAX_LENGHT_OF_FLAG_GREP] = {
    "-e", "-i", "-v", "-c", "-l", "-n", "NULL"
};

typedef struct Flags_grep {
    int e;
    int i;
    int v;
    int c;
    int l;
    int n;
} Flags_grep;

typedef struct Data_grep {
    // An array to keep all of the flags valid and invalid to sort them out later
    char all_flags_array[TOTAL_NUM_FLAGS_GREP][MAX_LENGHT_OF_FLAG_GREP];
    // And an array for filenames. Valid and invalid. Going to sort them out later
    char all_filenames_array[TOTAL_NUM_FILENAMES][MAX_LENGHT_OF_FILENAME];
    int number_of_files;
} Data_grep;

void initialize_flags_grep(Flags_grep* flags_grep);
void initialize_data_grep(Data_grep* data_grep);

#endif  // SRC_S21_GREP_H