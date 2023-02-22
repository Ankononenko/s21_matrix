#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int are_equal = SUCCESS;
  if (A->rows == B->rows && A->columns == B->columns) {
    int row_index = 0, column_index = 0;
    while (row_index < A->rows && are_equal) { 
      while (column_index < A->columns && are_equal) {
        if (A->matrix[row_index][column_index] - B->matrix[row_index][column_index] > EPSILON) {
          are_equal = FAILURE;      
        }
        ++column_index;
      }
      column_index = 0;
      ++row_index;
    }
  } else {
    are_equal = FAILURE;
  }
  return are_equal;
}