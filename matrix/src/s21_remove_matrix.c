#include "s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (A->matrix) {
    for (int index = 0; index < A->rows; ++index) {
      free(A->matrix[index]);
    }
    free(A->matrix);
    A->matrix = NULL;
  }
  if (A->columns) {
    A->columns = 0;
  }
  if (A->rows) {
    A->rows = 0;
  }
}