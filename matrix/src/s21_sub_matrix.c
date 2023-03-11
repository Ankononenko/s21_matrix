#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_code = SUCCESS_ENUM;
  if (is_invalid_matrix(A) || is_invalid_matrix(B)) {
    return_code = ERROR_ENUM;
  } else if (cant_be_calculated_matrix(A, B)) {
    return_code = CALCULATION_ERROR_ENUM;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    int row_index = 0, column_index = 0;
    count(A, B, result, &row_index, &column_index, '-');
  }
  return return_code;
}