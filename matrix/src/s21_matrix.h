#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define UNUSED_SHIT(fucking_unused_shit) do { (void)(fucking_unused_shit); } while (0)

#define FAILURE 0
#define SUCCESS 1
#define EPSILON 1e-7

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
int s21_mult_number(matrix_t *A, double number, matrix_t *result);

int is_invalid_matrix(matrix_t* matrix);
int cant_be_calculated_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
void count(matrix_t* A, matrix_t* B, matrix_t* result, int* row_index, int* column_index, char operand);

#endif // S21_MATRIX_H