#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int return_code;
  if (A->rows != A->columns) {
    return_code = CALCULATION_ERROR_ENUM;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    int total_num_elem = A->rows * A->columns;
    if (total_num_elem == 1) {
      result->matrix[0][0] = A->matrix[0][0];
    }
    if (total_num_elem == 4) {
      result->matrix[0][0] = A->matrix[1][1];
      result->matrix[0][1] = A->matrix[1][0];
      result->matrix[1][0] = A->matrix[0][1];
      result->matrix[1][1] = A->matrix[0][0];
    }
    if (total_num_elem > 4) {
      int curr_elem_row_i = 0, curr_elem_column_i = 0;
      for (int current_elem = 0; current_elem < total_num_elem; ++current_elem) {
        printf("Current element = %d\n", current_elem + 1);
        remove_row_and_column(A, result, &curr_elem_row_i, &curr_elem_column_i);
        print_out_matrix(3, 3, result->matrix);
        printf("\n");
      }
    }
    return_code = SUCCESS_ENUM;
    }
  return return_code;
}

void remove_row_and_column(matrix_t *A, matrix_t *result, int* curr_elem_row_i, int* curr_elem_column_i) {
  int row_insert_i = 0, column_insert_i = 0;
  for (int row_i = 0; row_i < A->rows; ++row_i) {
    column_insert_i = 0;
    for (int column_i = 0; column_i < A->columns; ++column_i) {
      if (row_i != *curr_elem_row_i && column_i != *curr_elem_column_i) {
        result->matrix[row_insert_i][column_insert_i] = A->matrix[row_i][column_i];
        ++column_insert_i;
      }
    }
    if (row_i != *curr_elem_row_i) {
      ++row_insert_i;
    }
  }
  if (*curr_elem_column_i == A->columns - 1) {
    *curr_elem_column_i = 0;
    ++(*curr_elem_row_i);
  } else {
    ++(*curr_elem_column_i);
  }
}