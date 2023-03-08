#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int return_code;
  if (is_invalid_matrix(A)) {
    return_code = ERROR_ENUM;
  } else if (A->rows != A->columns) {
    return_code = CALCULATION_ERROR_ENUM;
  } else { 
    if (s21_create_matrix(A->rows, A->columns, result)) {
      return_code = ERROR_ENUM;
    } else {
      double det_res = 0.0;
      int det_ret_code = s21_determinant(A, &det_res);
      if (det_ret_code || fabs(det_res) < EPSILON) {
        return_code = CALCULATION_ERROR_ENUM;
      } else {
          matrix_t temp = {0};
          if (s21_calc_complements(A, &temp)) {
            return_code = ERROR_ENUM;
          } else {
            if (s21_transpose(&temp, result)) {
              return_code = ERROR_ENUM;
            } else {
                return_code = SUCCESS_ENUM;
                s21_remove_matrix(&temp);
            }
          }
      }
    }
  }
  return return_code;
}