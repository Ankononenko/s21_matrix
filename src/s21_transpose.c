#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int return_code = SUCCESS_ENUM;
  if (is_invalid_matrix(A)) {
    return_code = ERROR_ENUM;
  } else {
    int result_rows = A->columns, result_columns = A->rows;
    s21_create_matrix(result_rows, result_columns, result);
    int read_row_i = 0, read_column_i = 0;
    for (int row_index = 0; row_index < result_rows; ++row_index) {
      for (int column_index = 0; column_index < result_columns; ++column_index) {
        result->matrix[row_index][column_index] = A->matrix[read_column_i][read_row_i];
        ++read_column_i;
      }
      ++read_row_i;
      read_column_i = 0;
    }
  }
  return return_code;
}