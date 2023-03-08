#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int return_code;
  if (is_invalid_matrix(A) || !result) {
    return_code = ERROR_ENUM;
  } else if (A->rows != A->columns) {
    return_code = CALCULATION_ERROR_ENUM;
  } else {
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else {
      
    }
  }
  return return_code;
}

void get_cofactor(double** matrix, double** temp, int skip_row, int skip_column, int size) {
  for (int temp_row_i, read_row_i = 0; read_row_i < size; ++read_row_i) {
    for (int temp_col_i, read_col_i = 0; read_col_i < size; ++read_col_i) {
      if (read_row_i != skip_row && read_col_i != skip_column) {
        temp[read_row_i][temp_col_i] = matrix[read_row_i][read_col_i];
        ++temp_col_i;
        if (temp_col_i == size - 1) {
          temp_col_i = 0;
          ++temp_row_i;
        }
      }
    }
  }  
}