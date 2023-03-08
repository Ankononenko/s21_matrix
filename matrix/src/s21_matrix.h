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
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);

int is_invalid_matrix(matrix_t* matrix);
int cant_be_calculated_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
void count(matrix_t* A, matrix_t* B, matrix_t* result, int* row_index, int* column_index, char operand);
void remove_row_and_column(matrix_t *A, matrix_t *result, int* curr_elem_row_i, int* curr_elem_column_i);
void add_extra_rows(matrix_t* resized_temp);
void temp_to_resized(matrix_t* resized_temp, matrix_t* temp);
int count_sum_sub_diagonal(matrix_t* resized_temp, int start_row);
void get_algebraic_complement(int row, int col, int* res);
void get_cofactor(double** matrix, double** temp, int skip_row, int skip_column, int size);

// TODO: Used for testing. Remove later!!!
void print_out_matrix(int rows, int columns, double** result);

#endif // S21_MATRIX_H