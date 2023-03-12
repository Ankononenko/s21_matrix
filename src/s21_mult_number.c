#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int return_code = SUCCESS_ENUM;
  if (is_invalid_matrix(A)) {
    return_code = ERROR_ENUM;
  } else {
    if (s21_create_matrix(A->rows, A->columns, result) == SUCCESS_ENUM) {
      int row_index = 0, column_index = 0;
      while (row_index < A->rows) {
        while (column_index < A->columns) {
          result->matrix[row_index][column_index] = A->matrix[row_index][column_index] * number;
          ++(column_index);
        }
        column_index = 0;
        ++(row_index);
      }
    } else {
      return_code = ERROR_ENUM;
    }
  }
  return return_code;
}