#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int return_code;
  if (A->rows != A->columns) {
    return_code = CALCULATION_ERROR_ENUM;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    int total_num_elem = A->rows * A->columns;
    int curr_elem_row_i = 0, curr_elem_column_i = 0;
    for (int current_elem = 0; current_elem < total_num_elem; ++current_elem) {
      printf("Current element = %d", current_elem);
      for (int row_i = 0; row_i < A->rows; ++row_i) {
        for (int column_i = 0; column_i < A->columns; ++column_i) {
          if (row_i != curr_elem_row_i && column_i != curr_elem_column_i) {
            printf("%f ", A->matrix[row_i][column_i]);
          }
        }
        printf("\n");
      }
      printf("row_i = %d, column_i = %d\n", curr_elem_row_i, curr_elem_column_i);
      if (curr_elem_column_i == A->columns - 1) {
        curr_elem_column_i = 0;
        ++curr_elem_row_i;
      } else {
        ++curr_elem_column_i;
      }
    }
    return_code = SUCCESS_ENUM;
  }
  return return_code;
}