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
    if (total_num_elem >= 9) {
      matrix_t temp;
      s21_create_matrix(A->rows, A->columns, &temp);
      matrix_t resized_temp;
      if (total_num_elem == 9) {
        s21_create_matrix(A->rows - 1, A->columns - 1, &resized_temp);
      } else {
        s21_create_matrix(A->rows - 1, A->columns + 1, &resized_temp);
      }
      int curr_elem_row_i = 0, curr_elem_column_i = 0;
      int sum = 0, sub = 0, res = 0;
      int insert_row_i = 0, insert_col_i = 0;
      for (int current_elem = 0; current_elem < total_num_elem; ++current_elem) {
        remove_row_and_column(A, &temp, &curr_elem_row_i, &curr_elem_column_i);
        temp_to_resized(&resized_temp, &temp);
        if (total_num_elem == 9) {
          sub = count_sum_sub_diagonal(&resized_temp, temp.rows - 2);
        } else {
          add_extra_rows(&resized_temp);
          sub = count_sum_sub_diagonal(&resized_temp, resized_temp.rows - 1);
        }
        sum = count_sum_sub_diagonal(&resized_temp, 0);
        res = sum - sub;
        get_algebraic_complement(insert_row_i + 1, insert_col_i + 1, &res);
        result->matrix[insert_row_i][insert_col_i] = res;
        if (insert_col_i == result->columns - 1) {
          ++insert_row_i;
          insert_col_i = -1;
        }
        ++insert_col_i;
      }
      s21_remove_matrix(&temp);
      s21_remove_matrix(&resized_temp);
    }
    return_code = SUCCESS_ENUM;
    }
  return return_code;
}

void get_algebraic_complement(int row, int col, int* res) {
  *res *= pow(-1.0, row + col);
}

int count_sum_sub_diagonal(matrix_t* resized_temp, int start_row) {
  int sum = 0, mult = 0, outer_col_i = 0, row_i = start_row;
  for (int row_repetitions = 0; row_repetitions < resized_temp->rows; ++row_repetitions) {
    row_i = start_row;
    for (int col_i = outer_col_i; col_i < outer_col_i + resized_temp->rows; ++col_i) {
      if (col_i == outer_col_i) {
        mult = resized_temp->matrix[row_i][col_i];
      } else {
        mult *= resized_temp->matrix[row_i][col_i];
      }
      if (!start_row) {
        ++row_i;
      } else {
        --row_i;
      }
    }
    ++outer_col_i;
    sum += mult;
  }
  return sum;
}

void temp_to_resized(matrix_t* resized_temp, matrix_t* temp) {
  for  (int row_index = 0; row_index < resized_temp->rows; ++row_index) {
    for  (int column_index = 0; column_index < temp->rows; ++column_index) {
      resized_temp->matrix[row_index][column_index] = temp->matrix[row_index][column_index];
    }
  }
}

void add_extra_rows(matrix_t* resized_temp) {
  int insert_row_i = 0, insert_column_i = resized_temp->rows;
  for (int read_row_i = 0; read_row_i < resized_temp->rows; ++read_row_i) {
    insert_column_i = resized_temp->rows;
    for (int read_column_i = 0; read_column_i < resized_temp->columns / 2; ++read_column_i) {
      resized_temp->matrix[insert_row_i][insert_column_i] = resized_temp->matrix[read_row_i][read_column_i];
      ++insert_column_i;
    }
    ++insert_row_i;
  }
}

void remove_row_and_column(matrix_t *A, matrix_t *temp, int* curr_elem_row_i, int* curr_elem_column_i) {
  int row_insert_i = 0, column_insert_i = 0;
  for (int row_i = 0; row_i < A->rows; ++row_i) {
    column_insert_i = 0;
    for (int column_i = 0; column_i < A->columns; ++column_i) {
      if (row_i != *curr_elem_row_i && column_i != *curr_elem_column_i) {
        temp->matrix[row_insert_i][column_insert_i] = A->matrix[row_i][column_i];
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