#include "s21_matrix.h"
#include <stdlib.h>
#include <time.h>
#include <check.h>

void print_out_matrix(int rows, int columns, double** result);
void fill_in_the_matrix(matrix_t* matrix, double example_array[][4]);
void generate_random_array();

// Create matrix
START_TEST(test_s21_create_matrix_1) {
    matrix_t A;
    int result = s21_create_matrix(1, 1, &A);
    ck_assert_int_eq(A.rows, 1);
    ck_assert_int_eq(A.columns, 1);
    ck_assert_int_eq(result, SUCCESS_ENUM);
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_create_matrix_2) {
    matrix_t A;
    int result = s21_create_matrix(5, 42, &A);
    ck_assert_int_eq(A.rows, 5);
    ck_assert_int_eq(A.columns, 42);
    ck_assert_int_eq(result, SUCCESS_ENUM);
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_create_matrix_3) {
    matrix_t A;
    int result = s21_create_matrix(666, 666, &A);
    ck_assert_int_eq(A.rows, 666);
    ck_assert_int_eq(A.columns, 666);
    ck_assert_int_eq(result, SUCCESS_ENUM);
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_create_matrix_4) {
    matrix_t A;
    int result = s21_create_matrix(0, 0, &A);
    ck_assert_int_eq(result, ERROR_ENUM);
}
END_TEST

START_TEST(test_s21_create_matrix_5) {
    matrix_t A;
    int result = s21_create_matrix(0, 1, &A);
    ck_assert_int_eq(result, ERROR_ENUM);
}
END_TEST

START_TEST(test_s21_create_matrix_6) {
    matrix_t A;
    int result = s21_create_matrix(1, 0, &A);
    ck_assert_int_eq(result, ERROR_ENUM);
}
END_TEST

// Remove matrix
START_TEST(test_s21_remove_matrix_1) {
    matrix_t A;
    s21_create_matrix(5, 42, &A);
    s21_remove_matrix(&A);
    int result_rows = A.rows;
    int result_columns = A.columns;
    void* ptr_after = A.matrix;
    ck_assert_int_eq(result_rows, 0);
    ck_assert_int_eq(result_columns, 0);
    ck_assert_int_eq((intmax_t)ptr_after, (intmax_t)NULL);
}
END_TEST

START_TEST(test_s21_remove_matrix_2) {
    matrix_t A;
    s21_create_matrix(666, 666, &A);
    s21_remove_matrix(&A);
    int result_rows = A.rows;
    int result_columns = A.columns;
    void* ptr_after = A.matrix;
    ck_assert_int_eq(result_rows, 0);
    ck_assert_int_eq(result_columns, 0);
    ck_assert_int_eq((intmax_t)ptr_after, (intmax_t)NULL);
}
END_TEST

START_TEST(test_s21_remove_matrix_3) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    double first_example[3][4] = {
      {0.9591071, 0.0943366, 0.1646078, 0.5312853},
      {0.4540530, 0.4396532, 0.0207605, 0.0485195},
      {0.3382748, 0.9805113, 0.1932359, 0.1689479}
    };
    fill_in_the_matrix(&A, first_example);
    s21_remove_matrix(&A);
    int result_rows = A.rows;
    int result_columns = A.columns;
    void* ptr_after = A.matrix;
    ck_assert_int_eq(result_rows, 0);
    ck_assert_int_eq(result_columns, 0);
    ck_assert_int_eq((intmax_t)ptr_after, (intmax_t)NULL);
}
END_TEST

int main(void) {

  matrix_t first;
  printf("Create:\n");
  s21_create_matrix(5, 5, &first);
  printf("rows = %d, columns = %d\n", first.rows, first.columns);
  print_out_matrix(first.rows, first.columns, first.matrix);

  printf("End of the test\n\n\n");

  printf("Remove:\n");
  s21_remove_matrix(&first);
  print_out_matrix(first.rows, first.columns, first.matrix);

  printf("End of the test\n\n\n");

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

  printf("End of the test\n\n\n");

  printf("Second compare not equal test:\n");
  s21_create_matrix(1, 5, &first);
  printf("rows = %d, columns = %d\n", first.rows, first.columns);
  print_out_matrix(first.rows, first.columns, first.matrix);
  s21_create_matrix(5, 1, &second);
  printf("rows = %d, columns = %d\n", second.rows, second.columns);
  print_out_matrix(second.rows, second.columns, second.matrix);
  printf("Compare:\n");
  first_and_second = s21_eq_matrix(&first, &second);
  printf("Compare first and second, not equal: %d\n", first_and_second);

  s21_remove_matrix(&first);
  s21_remove_matrix(&second);

  printf("End of the test\n\n\n");

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

  printf("End of the test\n\n\n");

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

  printf("End of the test\n\n\n");

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

  printf("End of the test\n\n\n");

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

  printf("End of the test\n\n\n");

  Suite *s1 = suite_create("s21_matrix: ");
  TCase *tc1_1 = tcase_create("s21_matrix: ");
  SRunner *sr = srunner_create(s1);
  int result;
  suite_add_tcase(s1, tc1_1);

  // Create_matrix
  tcase_add_test(tc1_1, test_s21_create_matrix_1);
  tcase_add_test(tc1_1, test_s21_create_matrix_2);
  tcase_add_test(tc1_1, test_s21_create_matrix_3);
  tcase_add_test(tc1_1, test_s21_create_matrix_4);
  tcase_add_test(tc1_1, test_s21_create_matrix_5);
  tcase_add_test(tc1_1, test_s21_create_matrix_6);

  // Remove matrix
  tcase_add_test(tc1_1, test_s21_remove_matrix_1);
  tcase_add_test(tc1_1, test_s21_remove_matrix_2);
  tcase_add_test(tc1_1, test_s21_remove_matrix_3);

  srunner_run_all(sr, CK_ENV);
  result = srunner_ntests_failed(sr);
  srunner_free(sr);
  return result == 0 ? 0 : 1;
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
