#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int return_code;
  if (A->rows != A->columns) {
    return_code = CALCULATION_ERROR_ENUM;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    
    return_code = SUCCESS_ENUM;
  }
  return return_code;
}