#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int return_code;
  if (rows && columns && result) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double**)calloc(rows, sizeof(double));
    for (int column_index = 0; column_index < rows; ++column_index) {
      result->matrix[column_index] = (double*)calloc(columns, sizeof(double));
    }
    if (!result->matrix) {
      printf("Memory allocation failed\n");
      return_code = ERROR_ENUM;
    }
    return_code = SUCCESS_ENUM;
  } else {
    return_code = ERROR_ENUM;
  }
  return return_code;
}