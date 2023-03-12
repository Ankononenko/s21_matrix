#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UNUSED_SHIT(fucking_unused_shit) \
  do {                                   \
    (void)(fucking_unused_shit);         \
  } while (0)

#define FAILURE 0
#define SUCCESS 1
#define EPSILON 1e-7

enum return_codes { SUCCESS_ENUM, ERROR_ENUM, CALCULATION_ERROR_ENUM };

typedef struct matrix_struct {
  double **matrix;
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
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// Helpers
int is_invalid_matrix(matrix_t *matrix);
int cant_be_calculated_matrix(matrix_t *A, matrix_t *B);
void count(matrix_t *A, matrix_t *B, matrix_t *result, int *row_index,
           int *column_index, char operand);
void get_algebraic_complement(int row, int col, double *res);
void get_cofactor(double **matrix, double **temp, int skip_row, int skip_column,
                  int size);
double get_determinant(double **matrix, int size);

// For testing
void fill_in_the_matrix_array_any(int rows, int columns, double **array,
                                  double (*example_array)[columns]);
// The functions are used for testing. Commented out for cppcheck
// void generate_random_array();
// void print_out_matrix(int rows, int columns, double **result);

#endif  // S21_MATRIX_H