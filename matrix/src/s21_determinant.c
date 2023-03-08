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
      return_code = SUCCESS_ENUM;
      *result = get_determinant(A->matrix, A->rows);
    }
  }
  return return_code;
}

double get_determinant(double** matrix, int size) {
  double result = 0.0;
  if (size == 1) {
    result = matrix[0][0];
  } else {
    matrix_t temp = {0};
    if (s21_create_matrix(size - 1, size - 1, &temp)) {
      result = ERROR_ENUM;
    } else {
      int sign = 1;
      for (int col_index = 0; col_index < size; ++col_index) {
        get_cofactor(matrix, temp.matrix, 0, col_index, size);
        result += sign * matrix[0][col_index] * get_determinant(temp.matrix, size - 1);
        sign *= -1;
      }
      s21_remove_matrix(&temp);
    }
  }
  return result;
}


void get_cofactor(double** matrix, double** temp, int skip_row, int skip_column, int size) {
  for (int temp_row_i = 0, read_row_i = 0; read_row_i < size; ++read_row_i) {
    if (read_row_i == skip_row) {
      continue;
    }
    int temp_col_i = 0;
    for (int read_col_i = 0; read_col_i < size; ++read_col_i) {
      if (read_col_i == skip_column) {
        continue;
      }
      temp[temp_row_i][temp_col_i] = matrix[read_row_i][read_col_i];
      ++temp_col_i;
    }
    ++temp_row_i;
  }  
}

