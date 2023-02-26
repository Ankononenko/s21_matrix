#include "s21_matrix.h"

int is_invalid_matrix(matrix_t* matrix) {
  return (matrix == NULL || matrix->matrix == NULL || matrix->rows < 1 || matrix->columns < 1);
}

int cant_be_calculated_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  return (A->rows != B->rows || A->rows != result->rows || A->columns != B->columns || A->columns != result->columns);
}

void count(matrix_t* A, matrix_t* B, matrix_t* result, int* row_index, int* column_index, char operand) {
  while (*row_index < A->rows) { 
    while (*column_index < A->columns) {
      if (operand == '+') {
        result->matrix[*row_index][*column_index] = A->matrix[*row_index][*column_index] + B->matrix[*row_index][*column_index];
      }
      if (operand == '-') {
        result->matrix[*row_index][*column_index] = A->matrix[*row_index][*column_index] - B->matrix[*row_index][*column_index];
      }
      ++(*column_index);
    }
    *column_index = 0;
    ++(*row_index);
  }
}