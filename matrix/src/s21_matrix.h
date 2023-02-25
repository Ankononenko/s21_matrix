#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define UNUSED_SHIT(fucking_unused_shit) do { (void)(fucking_unused_shit); } while (0)

#define SUCCESS 1
#define FAILURE 0
#define EPSILON 1e-6

enum return_codes { SUCCESS_ENUM, ERROR_ENUM, CALCULATION_ERROR_ENUM };

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

#endif // S21_MATRIX_H