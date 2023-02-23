#include "s21_matrix.h"
#include <stdlib.h>
#include <time.h>

void print_out_matrix(int rows, int columns, double** result);
void fill_in_the_matrix(matrix_t* matrix, double example_array[][4]);
void generate_random_array();

int main(void) {

  matrix_t first;
  printf("Create:\n");
  s21_create_matrix(5, 5, &first);
  printf("rows = %d, columns = %d\n", first.rows, first.columns);
  print_out_matrix(first.rows, first.columns, first.matrix);
  
  printf("Remove:\n");
  s21_remove_matrix(&first);
  print_out_matrix(first.rows, first.columns, first.matrix);

  printf("First compare:\n");
  s21_create_matrix(5, 5, &first);
  printf("rows = %d, columns = %d\n", first.rows, first.columns);
  print_out_matrix(first.rows, first.columns, first.matrix);
  printf("Second compare:\n");
  matrix_t second;
  s21_create_matrix(5, 5, &second);
  printf("rows = %d, columns = %d\n", second.rows, second.columns);
  print_out_matrix(second.rows, second.columns, second.matrix);
  printf("Compare:\n");
  int first_and_second = s21_eq_matrix(&first, &second);
  printf("Compare first and second, equal: %d\n", first_and_second);

  s21_remove_matrix(&first);
  s21_remove_matrix(&second);

  s21_create_matrix(1, 5, &first);
  printf("rows = %d, columns = %d\n", first.rows, first.columns);
  print_out_matrix(first.rows, first.columns, first.matrix);
  printf("Second compare:\n");
  s21_create_matrix(5, 1, &second);
  printf("rows = %d, columns = %d\n", second.rows, second.columns);
  print_out_matrix(second.rows, second.columns, second.matrix);
  printf("Compare:\n");
  first_and_second = s21_eq_matrix(&first, &second);
  printf("Compare first and second, not equal: %d\n", first_and_second);

  s21_remove_matrix(&first);
  s21_remove_matrix(&second);

  printf("Compare the double equal matrix\n");
  s21_create_matrix(3, 4, &first);
  double first_example[3][4] = {
    {0.9591071, 0.0943366, 0.1646078, 0.5312853},
    {0.4540530, 0.4396532, 0.0207605, 0.0485195},
    {0.3382748, 0.9805113, 0.1932359, 0.1689479}
  };
  fill_in_the_matrix(&first, first_example);
  print_out_matrix(first.rows, first.columns, first.matrix);
  s21_create_matrix(3, 4, &second);
  fill_in_the_matrix(&second, first_example);
  print_out_matrix(second.rows, second.columns, second.matrix);
  first_and_second = s21_eq_matrix(&first, &second);
  printf("Compare first and second, equal: %d\n", first_and_second);

  s21_remove_matrix(&first);
  s21_remove_matrix(&second);

  printf("Compare the double not equal matrix\n");
  s21_create_matrix(3, 4, &first);
  double second_example[3][4] = {
    {0.1302556, 0.6424344, 0.8785851, 0.6408750},
    {0.6786694, 0.1082821, 0.9035930, 0.1530762},
    {0.2812518, 0.2559180, 0.9537255, 0.6256213}
  };
  fill_in_the_matrix(&first, first_example);
  print_out_matrix(first.rows, first.columns, first.matrix);
  s21_create_matrix(3, 4, &second);
  fill_in_the_matrix(&second, second_example);
  print_out_matrix(second.rows, second.columns, second.matrix);
  first_and_second = s21_eq_matrix(&first, &second);
  printf("Compare first and second, not equal: %d\n", first_and_second);

  s21_remove_matrix(&first);
  s21_remove_matrix(&second);

  printf("Sum two matrix\n");
  s21_create_matrix(3, 4, &first);
  fill_in_the_matrix(&first, first_example);
  print_out_matrix(first.rows, first.columns, first.matrix);
  s21_create_matrix(3, 4, &second);
  fill_in_the_matrix(&second, second_example);
  print_out_matrix(second.rows, second.columns, second.matrix);
  matrix_t third;
  s21_sum_matrix(&first, &second, &third);
  print_out_matrix(third.rows, third.columns, third.matrix);
  printf("expected_result:\n"
    "1.089362 0.736771 1.043193 1.172160\n"
    "1.132722 0.547935 0.924353 0.201595\n"
    "0.619526 1.236429 1.146961 0.794569\n"
    );
  s21_remove_matrix(&first);
  s21_remove_matrix(&second);
  s21_remove_matrix(&third);

  printf("Substract two matrix\n");
  s21_create_matrix(3, 4, &first);
  fill_in_the_matrix(&first, first_example);
  print_out_matrix(first.rows, first.columns, first.matrix);
  s21_create_matrix(3, 4, &second);
  fill_in_the_matrix(&second, second_example);
  print_out_matrix(second.rows, second.columns, second.matrix);
  s21_sub_matrix(&first, &second, &third);
  print_out_matrix(third.rows, third.columns, third.matrix);
  printf("expected_result:\n"
    "0.828851 -0.548098 -0.713977 -0.109590\n"
    "-0.224616 0.331371 -0.882833 -0.104556\n" 
    "0.057023 0.724593 -0.760489 -0.456673 \n"
    );
  s21_remove_matrix(&first);
  s21_remove_matrix(&second);
  s21_remove_matrix(&third);

  return 0;
}

void print_out_matrix(int rows, int columns, double** result) {
  printf("rows = %d, columns = %d\n", rows, columns);
  for (int index_r = 0; index_r < rows; ++index_r) {
    for (int index_c = 0; index_c < columns; ++index_c) {
      printf("%f ", result[index_r][index_c]);
    }
    printf("\n");
  }
}

void fill_in_the_matrix(matrix_t* matrix, double example_array[][4]) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      matrix->matrix[i][j] = example_array[i][j];
    }
  }
}

void generate_random_array() {
    double data[3][4];
    int i, j;
    srand(time(NULL));  // seed the random number generator

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            data[i][j] = (double)rand() / RAND_MAX;  // generate a random double value between 0 and 1
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
