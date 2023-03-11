#include "s21_matrix.h"

int is_invalid_matrix(matrix_t* matrix) {
  return (matrix == NULL || matrix->matrix == NULL || matrix->rows < 1 || matrix->columns < 1);
}

int cant_be_calculated_matrix(matrix_t* A, matrix_t* B) {
  return (A->rows != B->rows || A->columns != B->columns);
}

void count(matrix_t* A, matrix_t* B, matrix_t* result, int* row_index, int* column_index, char operand) {
  while (*row_index < A->rows) { 
    while (*column_index < A->columns) {
      if (operand == '+') {
        result->matrix[*row_index][*column_index] = A->matrix[*row_index][*column_index] + B->matrix[*row_index][*column_index];
      }
      if (operand == '-') {
        result->matrix[*row_index][*column_index] = A->matrix[*row_index][*column_index] - B->matrix[*row_index][*column_index];
      }
      ++(*column_index);
    }
    *column_index = 0;
    ++(*row_index);
  }
}

void get_algebraic_complement(int row, int col, double* res) {
  *res *= pow(-1.0, row + col + 2);
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

void generate_random_array() {
    double data[3][4];
    int i, j;
    // Seed the random number generator
    srand(time(NULL));

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            // Generate a random double value between 0 and 1
            data[i][j] = (double)rand() / RAND_MAX;
        }
    }

    printf("double data[3][4] = {\n");
    for (i = 0; i < 3; i++) {
        printf("  {");
        for (j = 0; j < 4; j++) {
            printf("%.7f", data[i][j]);
            if (j < 3) {
                printf(", ");
            }
        }
        printf("}");
        if (i < 2) {
            printf(",");
        }
        printf("\n");
    }
    printf("};\n");
}

void print_out_matrix(int rows, int columns, double** result) {
  printf("rows = %d, columns = %d\n", rows, columns);
  for (int index_r = 0; index_r < rows; ++index_r) {
    for (int index_c = 0; index_c < columns; ++index_c) {
      printf("%.6f ", result[index_r][index_c]);
    }
    printf("\n");
  }
}

void fill_in_the_matrix_array_any(int rows, int columns, double** array, double (*example_array)[columns]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      array[i][j] = (*example_array)[i * columns + j];
    }
  }
}