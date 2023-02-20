#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <stdio.h>
#include <stdlib.h>

#define UNUSED_SHIT(fucking_unused_shit) do { (void)(fucking_unused_shit); } while (0)

enum return_codes { SUCCESS, ERROR, CALCULATION_ERROR };

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);

#endif // S21_MATRIX_H