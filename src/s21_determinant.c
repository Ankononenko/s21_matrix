#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int return_code = SUCCESS_ENUM;
  if (is_invalid_matrix(A) || !result) {
    return_code = ERROR_ENUM;
  } else if (A->rows != A->columns) {
    return_code = CALCULATION_ERROR_ENUM;
  } else {
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else {
      *result = get_determinant(A->matrix, A->rows);
    }
  }
  return return_code;
}