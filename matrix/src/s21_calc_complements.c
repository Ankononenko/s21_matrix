#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int return_code;
  if (is_invalid_matrix(A)) {
    return_code = ERROR_ENUM;
  } else if (A->rows != A->columns) {
    return_code = CALCULATION_ERROR_ENUM;
  } else { 
    return_code = SUCCESS_ENUM;
    if (s21_create_matrix(A->rows, A->columns, result)) {
      return_code = ERROR_ENUM;
    } else {
      if (A->rows == 1) {
        result->matrix[0][0] = A->matrix[0][0];
      } else if (A->rows == 2) {
          result->matrix[0][0] = A->matrix[1][1];
          result->matrix[0][1] = -A->matrix[1][0];
          result->matrix[1][0] = -A->matrix[0][1];
          result->matrix[1][1] = A->matrix[0][0];
      } else {
          matrix_t temp = {0};
          double temp_res = 0.0;
          s21_create_matrix(A->rows, A->columns, &temp);
            for (int row_i = 0; row_i < A->rows; ++row_i) {
              for (int col_i = 0; col_i < A->columns; ++col_i) {
                get_cofactor(A->matrix, temp.matrix, row_i, col_i, A->rows);
                temp_res = get_determinant(temp.matrix, A->rows - 1);
                get_algebraic_complement(row_i, col_i, &temp_res);
                result->matrix[row_i][col_i] = temp_res;
              }
            }
          s21_remove_matrix(&temp);                                
      }
    }
  }
  return return_code;
}