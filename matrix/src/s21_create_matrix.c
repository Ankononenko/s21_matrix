#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int return_code = SUCCESS_ENUM;
  result->rows = rows;
  result->columns = columns;
  if (rows > 0 && columns > 0) {
    result->matrix = (double**)calloc(rows, sizeof(double*));
    if (!result->matrix) {
      printf("Memory allocation failed\n");
      return_code = ERROR_ENUM;
    }
    for (int row_index = 0; row_index < rows; ++row_index) {
      result->matrix[row_index] = (double*)calloc(columns, sizeof(double));
      if (!result->matrix[row_index]) {
          return_code = ERROR_ENUM;
          for (int row_index_clean = 0; row_index_clean < row_index; row_index_clean++) {
            free(result->matrix[row_index_clean]);
          }
          free(result->matrix);
          break;
      }
    }
  } else {
    result->matrix = NULL;
    return_code = ERROR_ENUM;
  }
  return return_code;
}