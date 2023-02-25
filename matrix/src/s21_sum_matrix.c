#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_code;
  if (!A || !B || !result || A->rows != B->rows || A->rows != result->rows || A->columns != B->columns || A->columns != result->columns) {
      return_code = ERROR_ENUM;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    int row_index = 0, column_index = 0;
    while (row_index < A->rows) { 
      while (column_index < A->columns) {
        result->matrix[row_index][column_index] = A->matrix[row_index][column_index] + B->matrix[row_index][column_index];
        ++column_index;
      }
      column_index = 0;
      ++row_index;
    }
    if (row_index == A->rows) {
      return_code = SUCCESS_ENUM;
    }
  }
  // TODO: Calculation error
  return return_code;
}