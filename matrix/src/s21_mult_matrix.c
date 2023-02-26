#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_code;
  if (is_invalid_matrix(A) || is_invalid_matrix(B)) {
      return_code = ERROR_ENUM;
  } else if (A->columns != B->rows) {
      return_code = CALCULATION_ERROR_ENUM;
  } else {
      int result_rows = A->rows, result_columns = B->columns;
      s21_create_matrix(result_rows, result_columns, result);
      int current_sum = 0;
      for (int read_row_i = 0; read_row_i < result_rows; ++read_row_i) {
        for (int read_column_i = 0; read_column_i < result_columns; ++read_column_i) {
          for (int sum_row_i = 0; sum_row_i < A->columns; ++sum_row_i) {
            current_sum += A->matrix[read_row_i][sum_row_i] * B->matrix[sum_row_i][read_column_i];
          }
          result->matrix[read_row_i][read_column_i] = current_sum;
          current_sum = 0;
        }
      }
      return_code = SUCCESS_ENUM;
  }
  return return_code;
}