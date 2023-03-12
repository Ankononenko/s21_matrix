#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int return_code = SUCCESS_ENUM;
  if (is_invalid_matrix(A)) {
    return_code = ERROR_ENUM;
  } else if (A->rows != A->columns) {
    return_code = CALCULATION_ERROR_ENUM;
  } else {
    if (s21_create_matrix(A->rows, A->columns, result)) {
      return_code = ERROR_ENUM;
    } else {
      double det_res = 0.0;
      s21_determinant(A, &det_res);
      if (fabs(det_res) < EPSILON) {
        return_code = CALCULATION_ERROR_ENUM;
      } else {
        matrix_t temp_first = {0};
        matrix_t temp_second = {0};
        s21_calc_complements(A, &temp_first);
        s21_transpose(&temp_first, &temp_second);
        s21_mult_number(&temp_second, 1.0 / det_res, result);
        s21_remove_matrix(&temp_first);
        s21_remove_matrix(&temp_second);
      }
    }
  }
  return return_code;
}