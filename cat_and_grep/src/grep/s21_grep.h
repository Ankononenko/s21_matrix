#ifndef SRC_S21_GREP_H
#define SRC_S21_GREP_H

#define TOTAL_NUM_FLAGS_GREP 7
#define MAX_LENGHT_OF_FLAG_GREP 5

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

#endif  // SRC_S21_GREP_H