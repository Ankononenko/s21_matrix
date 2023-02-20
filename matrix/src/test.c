#include "s21_matrix.h"
#include <stdlib.h>

void print_out_matrix(int rows, int columns, double** result);

int main(void) {
  matrix_t first;
  s21_create_matrix(5, 5, &first);
  printf("rows = %d, columns = %d\n", first.rows, first.columns);
  print_out_matrix(first.rows, first.columns, first.matrix);
  free(first.matrix);
  return 0;
}

void print_out_matrix(int rows, int columns, double** result) {
  for (int index_r = 0; index_r < rows; ++index_r) {
    for (int index_c = 0; index_c < columns; ++index_c) {
      printf("%f ", result[index_r][index_c]);
    }
    printf("\n");
  }
}