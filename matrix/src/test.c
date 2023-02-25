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

// Compare matrix

START_TEST(test_s21_eq_matrix_1) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    int result = s21_eq_matrix(&A, &B);
    ck_assert_int_eq(result, SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_2) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    double first_example[3][4] = {
      {0.9591071, 0.0943366, 0.1646078, 0.5312853},
      {0.4540530, 0.4396532, 0.0207605, 0.0485195},
      {0.3382748, 0.9805113, 0.1932359, 0.1689479}
    };
    fill_in_the_matrix(&B, first_example);
    int result = s21_eq_matrix(&A, &B);
    ck_assert_int_eq(result, FAILURE);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_3) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    double first_example[3][4] = {
      {0.9591071, 0.0943366, 0.1646078, 0.5312853},
      {0.4540530, 0.4396532, 0.0207605, 0.0485195},
      {0.3382748, 0.9805113, 0.1932359, 0.1689479}
    };
    fill_in_the_matrix(&A, first_example);
    fill_in_the_matrix(&B, first_example);
    int result = s21_eq_matrix(&A, &B);
    ck_assert_int_eq(result, SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_4) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    double first_example[3][4] = {
      {0.9591071, 0.0943366, 0.1646078, 0.5312853},
      {0.4540530, 0.4396532, 0.0207605, 0.0485195},
      {0.3382748, 0.9805113, 0.1932359, 0.1689479}
    };
    double second_example[3][4] = {
      {0.1302556, 0.6424344, 0.8785851, 0.6408750},
      {0.6786694, 0.1082821, 0.9035930, 0.1530762},
      {0.2812518, 0.2559180, 0.9537255, 0.6256213}
    };
    fill_in_the_matrix(&A, first_example);
    fill_in_the_matrix(&B, second_example);
    int result = s21_eq_matrix(&A, &B);
    ck_assert_int_eq(result, FAILURE);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_5) {
    matrix_t A;
    s21_create_matrix(4, 4, &A);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    double first_example[4][4] = {
      {0.9591071, 0.0943366, 0.1646078, 0.5312853},
      {0.4540530, 0.4396532, 0.0207605, 0.0485195},
      {0.3382748, 0.9805113, 0.1932359, 0.1689479},
      {0.3382748, 0.9805113, 0.1932359, 0.1689479}
    };
    double second_example[3][4] = {
      {0.1302556, 0.6424344, 0.8785851, 0.6408750},
      {0.6786694, 0.1082821, 0.9035930, 0.1530762},
      {0.2812518, 0.2559180, 0.9537255, 0.6256213}
    };
    fill_in_the_matrix(&A, first_example);
    fill_in_the_matrix(&B, second_example);
    int result = s21_eq_matrix(&A, &B);
    ck_assert_int_eq(result, FAILURE);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_6) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    double first_example[3][4] = {
      {-0.9591071, -0.0943366, -0.1646078, -0.5312853},
      {-0.4540530, -0.4396532, -0.0207605, -0.0485195},
      {-0.3382748, -0.9805113, -0.1932359, -0.1689479}
    };
    fill_in_the_matrix(&B, first_example);
    int result = s21_eq_matrix(&A, &B);
    ck_assert_int_eq(result, FAILURE);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_7) {
    matrix_t A;
    s21_create_matrix(4, 4, &A);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    double first_example[3][4] = {
      {-0.9591071, -0.0943366, -0.1646078, -0.5312853},
      {-0.4540530, -0.4396532, -0.0207605, -0.0485195},
      {-0.3382748, -0.9805113, -0.1932359, -0.1689479}
    };
    double second_example[3][4] = {
      {0.1302556, 0.6424344, 0.8785851, 0.6408750},
      {0.6786694, 0.1082821, 0.9035930, 0.1530762},
      {0.2812518, 0.2559180, 0.9537255, 0.6256213}
    };
    fill_in_the_matrix(&A, first_example);
    fill_in_the_matrix(&B, second_example);
    int result = s21_eq_matrix(&A, &B);
    ck_assert_int_eq(result, FAILURE);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_8) {
    matrix_t A;
    s21_create_matrix(4, 4, &A);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    double first_example[3][4] = {
      {-0.9591071, -0.0943366, -0.1646078, -0.5312853},
      {-0.4540530, -0.4396532, -0.0207605, -0.0485195},
      {-0.3382748, -0.9805113, -0.1932359, -0.1689479}
    };
    double second_example[3][4] = {
      {-0.1302556, -0.6424344, -0.8785851, -0.6408750},
      {-0.6786694, -0.1082821, -0.9035930, -0.1530762},
      {-0.2812518, -0.2559180, -0.9537255, -0.6256213}
    };
    fill_in_the_matrix(&A, first_example);
    fill_in_the_matrix(&B, second_example);
    int result = s21_eq_matrix(&A, &B);
    ck_assert_int_eq(result, FAILURE);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_9) {
    matrix_t A;
    s21_create_matrix(4, 4, &A);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    double first_example[3][4] = {
      {-0.9591071, 0.0943366, -0.1646078, 0.5312853},
      {-0.4540530, 0.4396532, -0.0207605, 0.0485195},
      {-0.3382748, 0.9805113, -0.1932359, 0.1689479}
    };
    double second_example[3][4] = {
      {0.1302556, -0.6424344, 0.8785851, -0.6408750},
      {0.6786694, -0.1082821, 0.9035930, -0.1530762},
      {0.2812518, -0.2559180, 0.9537255, -0.6256213}
    };
    fill_in_the_matrix(&A, first_example);
    fill_in_the_matrix(&B, second_example);
    int result = s21_eq_matrix(&A, &B);
    ck_assert_int_eq(result, FAILURE);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

// Sum matrix

START_TEST(test_s21_sum_matrix_1) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    matrix_t C;
    s21_create_matrix(3, 4, &C);
    double zero_matrix[3][4] = {
      {0.0, 0.0, 0.0, 0.0},
      {0.0, 0.0, 0.0, 0.0},
      {0.0, 0.0, 0.0, 0.0}
    };
    fill_in_the_matrix(&C, zero_matrix);
    matrix_t D;
    s21_create_matrix(3, 4, &D);
    int return_code_result = s21_sum_matrix(&A, &B, &D);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    int compare_result = s21_eq_matrix(&C, &D);
    ck_assert_int_eq(compare_result, SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_sum_matrix_2) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    double first_example[3][4] = {
      {0.9591071, 0.0943366, 0.1646078, 0.5312853},
      {0.4540530, 0.4396532, 0.0207605, 0.0485195},
      {0.3382748, 0.9805113, 0.1932359, 0.1689479}
    };
    fill_in_the_matrix(&B, first_example);
    matrix_t C;
    s21_create_matrix(3, 4, &C);
    fill_in_the_matrix(&C, first_example);
    matrix_t D;
    s21_create_matrix(3, 4, &D);
    int return_code_result = s21_sum_matrix(&A, &B, &D);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    int compare_result = s21_eq_matrix(&C, &D);
    ck_assert_int_eq(compare_result, SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_sum_matrix_3) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    double first_example[3][4] = {
      {0.9591071, 0.0943366, 0.1646078, 0.5312853},
      {0.4540530, 0.4396532, 0.0207605, 0.0485195},
      {0.3382748, 0.9805113, 0.1932359, 0.1689479}
    };
    fill_in_the_matrix(&A, first_example);
    fill_in_the_matrix(&B, first_example);
    matrix_t C;
    s21_create_matrix(3, 4, &C);
    double expected_output[3][4] = {
      {1.9182142, 0.1886732, 0.3292156, 1.0625706},
      {0.9081060, 0.8793064, 0.0415210, 0.0970389},
      {0.6765496, 1.9610226, 0.3864718, 0.3378958}
    };
    fill_in_the_matrix(&C, expected_output);
    matrix_t D;
    s21_create_matrix(3, 4, &D);
    int return_code_result = s21_sum_matrix(&A, &B, &D);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    int compare_result = s21_eq_matrix(&C, &D);
    ck_assert_int_eq(compare_result, SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_sum_matrix_4) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    double first_example[3][4] = {
      {0.9591071, 0.0943366, 0.1646078, 0.5312853},
      {0.4540530, 0.4396532, 0.0207605, 0.0485195},
      {0.3382748, 0.9805113, 0.1932359, 0.1689479}
    };
    fill_in_the_matrix(&A, first_example);
    double second_example[3][4] = {
      {0.1302556, 0.6424344, 0.8785851, 0.6408750},
      {0.6786694, 0.1082821, 0.9035930, 0.1530762},
      {0.2812518, 0.2559180, 0.9537255, 0.6256213}
    };
    fill_in_the_matrix(&B, second_example);
    matrix_t C;
    s21_create_matrix(3, 4, &C);
    double expected_result[3][4] = {
      {1.0893627, 0.7367710, 1.0431930, 1.1721603},
      {1.1327224, 0.5479353, 0.924353, 0.2015956},
      {0.6195266, 1.2364293, 1.1469614, 0.7945692}
    };
    fill_in_the_matrix(&C, expected_result);
    matrix_t D;
    s21_create_matrix(3, 4, &D);
    int return_code_result = s21_sum_matrix(&A, &B, &D);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    int compare_result = s21_eq_matrix(&C, &D);
    ck_assert_int_eq(compare_result, SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_sum_matrix_5) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    double first_example[3][4] = {
      {111.9591071, 0.0943366, 0.1646078, 0.5312853},
      {0.4540530, -3456789.4396532, 4567890.0207605, 35467899087645678.0485195},
      {0.3382748, -0.9805113, 9090909.1932359, 0.1689479}
    };
    fill_in_the_matrix(&A, first_example);
    double second_example[3][4] = {
      {0.000001, 0.6424344, 0.8785851, -0.6408750},
      {0.00000001, -4567.1082821, 0.9035930, 0.1530762},
      {0.2812518, 0.2559180, 0.9537255, 0.6256213}
    };
    fill_in_the_matrix(&B, second_example);
    matrix_t C;
    s21_create_matrix(3, 4, &C);
    double expected_result[3][4] = {
      {111.9591081, 0.7367710, 1.0431930, -0.1095897},
      {0.4540530, -3461356.547935, 4567890.924353, 35467899087645678.2015957},
      {0.6195266, -0.7245933, 9090910.1469614, 0.7945692}
    };
    fill_in_the_matrix(&C, expected_result);
    matrix_t D;
    s21_create_matrix(3, 4, &D);
    int return_code_result = s21_sum_matrix(&A, &B, &D);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    int compare_result = s21_eq_matrix(&C, &D);
    ck_assert_int_eq(compare_result, SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_sum_matrix_6) {
    matrix_t A;
    s21_create_matrix(2, 4, &A);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    double first_example[2][4] = {
      {111.9591071, 0.0943366, 0.1646078, 0.5312853},
      {0.4540530, -3456789.4396532, 4567890.0207605, 35467899087645678.0485195}
    };
    fill_in_the_matrix(&A, first_example);
    double second_example[3][4] = {
      {0.000001, 0.6424344, 0.8785851, -0.6408750},
      {0.00000001, -4567.1082821, 0.9035930, 0.1530762},
      {0.2812518, 0.2559180, 0.9537255, 0.6256213}
    };
    fill_in_the_matrix(&B, second_example);
    matrix_t D;
    s21_create_matrix(3, 4, &D);
    int return_code_result = s21_sum_matrix(&A, &B, &D);
    ck_assert_int_eq(return_code_result, CALCULATION_ERROR_ENUM);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_sum_matrix_7) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    double first_example[3][4] = {
      {111.9591071, 0.0943366, 0.1646078, 0.5312853},
      {111.9591071, 0.0943366, 0.1646078, 0.5312853},
      {0.4540530, -3456789.4396532, 4567890.0207605, 35467899087645678.0485195}
    };
    fill_in_the_matrix(&A, first_example);
    double second_example[3][4] = {
      {0.000001, 0.6424344, 0.8785851, -0.6408750},
      {0.00000001, -4567.1082821, 0.9035930, 0.1530762},
      {0.2812518, 0.2559180, 0.9537255, 0.6256213}
    };
    fill_in_the_matrix(&B, second_example);
    matrix_t D;
    s21_create_matrix(2, 4, &D);
    int return_code_result = s21_sum_matrix(&A, &B, &D);
    ck_assert_int_eq(return_code_result, CALCULATION_ERROR_ENUM);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_sum_matrix_8) {
    matrix_t A;
    s21_create_matrix(3, 3, &A);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    double second_example[3][4] = {
      {0.000001, 0.6424344, 0.8785851, -0.6408750},
      {0.00000001, -4567.1082821, 0.9035930, 0.1530762},
      {0.2812518, 0.2559180, 0.9537255, 0.6256213}
    };
    fill_in_the_matrix(&B, second_example);
    matrix_t D;
    s21_create_matrix(3, 4, &D);
    int return_code_result = s21_sum_matrix(&A, &B, &D);
    ck_assert_int_eq(return_code_result, CALCULATION_ERROR_ENUM);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_sum_matrix_9) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    double first_example[3][4] = {
      {111.9591071, 0.0943366, 0.1646078, 0.5312853},
      {111.9591071, 0.0943366, 0.1646078, 0.5312853},
      {0.4540530, -3456789.4396532, 4567890.0207605, 35467899087645678.0485195}
    };
    fill_in_the_matrix(&A, first_example);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    double second_example[3][4] = {
      {0.000001, 0.6424344, 0.8785851, -0.6408750},
      {0.00000001, -4567.1082821, 0.9035930, 0.1530762},
      {0.2812518, 0.2559180, 0.9537255, 0.6256213}
    };
    fill_in_the_matrix(&B, second_example);
    matrix_t D;
    s21_create_matrix(3, 6, &D);
    int return_code_result = s21_sum_matrix(&A, &B, &D);
    ck_assert_int_eq(return_code_result, CALCULATION_ERROR_ENUM);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_sum_matrix_10) {
    matrix_t A;
    A.rows = 0;
    A.columns = 0;
    A.matrix = NULL;
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    double second_example[3][4] = {
      {0.000001, 0.6424344, 0.8785851, -0.6408750},
      {0.00000001, -4567.1082821, 0.9035930, 0.1530762},
      {0.2812518, 0.2559180, 0.9537255, 0.6256213}
    };
    fill_in_the_matrix(&B, second_example);
    matrix_t D;
    s21_create_matrix(3, 6, &D);
    int return_code_result = s21_sum_matrix(&A, &B, &D);
    ck_assert_int_eq(return_code_result, ERROR_ENUM);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&D);
}
END_TEST

// Substract matrix

START_TEST(test_s21_sub_matrix_1) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    matrix_t C;
    s21_create_matrix(3, 4, &C);
    double zero_matrix[3][4] = {
      {0.0, 0.0, 0.0, 0.0},
      {0.0, 0.0, 0.0, 0.0},
      {0.0, 0.0, 0.0, 0.0}
    };
    fill_in_the_matrix(&C, zero_matrix);
    matrix_t D;
    s21_create_matrix(3, 4, &D);
    int return_code_result = s21_sub_matrix(&A, &B, &D);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    int compare_result = s21_eq_matrix(&C, &D);
    ck_assert_int_eq(compare_result, SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_sub_matrix_2) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    double first_example[3][4] = {
      {0.9591071, 0.0943366, 0.1646078, 0.5312853},
      {0.4540530, 0.4396532, 0.0207605, 0.0485195},
      {0.3382748, 0.9805113, 0.1932359, 0.1689479}
    };
    fill_in_the_matrix(&B, first_example);
    matrix_t C;
    s21_create_matrix(3, 4, &C);
    double expected_output[3][4] = {
      { -0.959107, -0.094337, -0.164608, -0.531285 },
      { -0.454053, -0.439653, -0.020761, -0.048520 },
      { -0.338275, -0.980511, -0.193236, -0.168948 }
    };
    fill_in_the_matrix(&C, expected_output);
    matrix_t D;
    s21_create_matrix(3, 4, &D);
    int return_code_result = s21_sub_matrix(&A, &B, &D);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    int compare_result = s21_eq_matrix(&C, &D);
    ck_assert_int_eq(compare_result, SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_sub_matrix_3) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    double first_example[3][4] = {
      {0.9591071, 0.0943366, 0.1646078, 0.5312853},
      {0.4540530, 0.4396532, 0.0207605, 0.0485195},
      {0.3382748, 0.9805113, 0.1932359, 0.1689479}
    };
    fill_in_the_matrix(&A, first_example);
    fill_in_the_matrix(&B, first_example);
    matrix_t C;
    s21_create_matrix(3, 4, &C);
    matrix_t D;
    s21_create_matrix(3, 4, &D);
    int return_code_result = s21_sub_matrix(&A, &B, &D);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    int compare_result = s21_eq_matrix(&C, &D);
    ck_assert_int_eq(compare_result, SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_sub_matrix_4) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    double first_example[3][4] = {
      {0.9591071, 0.0943366, 0.1646078, 0.5312853},
      {0.4540530, 0.4396532, 0.0207605, 0.0485195},
      {0.3382748, 0.9805113, 0.1932359, 0.1689479}
    };
    fill_in_the_matrix(&A, first_example);
    double second_example[3][4] = {
      {0.1302556, 0.6424344, 0.8785851, 0.6408750},
      {0.6786694, 0.1082821, 0.9035930, 0.1530762},
      {0.2812518, 0.2559180, 0.9537255, 0.6256213}
    };
    fill_in_the_matrix(&B, second_example);
    matrix_t C;
    s21_create_matrix(3, 4, &C);
    double expected_result[3][4] = {
      {0.828851, -0.548098, -0.713977, -0.109590},
      {-0.224616, 0.331371, -0.882833, -0.104557},
      {0.057023, 0.724593, -0.760490, -0.456673}
    };
    fill_in_the_matrix(&C, expected_result);
    matrix_t D;
    s21_create_matrix(3, 4, &D);
    int return_code_result = s21_sub_matrix(&A, &B, &D);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    int compare_result = s21_eq_matrix(&C, &D);
    ck_assert_int_eq(compare_result, SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_sub_matrix_5) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    double first_example[3][4] = {
      {111.9591071, 0.0943366, 0.1646078, 0.5312853},
      {0.4540530, -3456789.4396532, 4567890.0207605, 35467899087645678.0485195},
      {0.3382748, -0.9805113, 9090909.1932359, 0.1689479}
    };
    fill_in_the_matrix(&A, first_example);
    double second_example[3][4] = {
      {0.000001, 0.6424344, 0.8785851, -0.6408750},
      {0.00000001, -4567.1082821, 0.9035930, 0.1530762},
      {0.2812518, 0.2559180, 0.9537255, 0.6256213}
    };
    fill_in_the_matrix(&B, second_example);
    matrix_t C;
    s21_create_matrix(3, 4, &C);
    double expected_result[3][4] = {
      {111.959106, -0.548098, -0.713977, 1.172160},
      {0.454053, -3452222.331371, 4567889.117167, 35467899087645680.000000},
      {0.057023, -1.236429, 9090908.239510, -0.456673}
    };
    fill_in_the_matrix(&C, expected_result);
    matrix_t D;
    s21_create_matrix(3, 4, &D);
    int return_code_result = s21_sub_matrix(&A, &B, &D);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    int compare_result = s21_eq_matrix(&C, &D);
    ck_assert_int_eq(compare_result, SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_sub_matrix_6) {
    matrix_t A;
    s21_create_matrix(2, 4, &A);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    double first_example[2][4] = {
      {111.9591071, 0.0943366, 0.1646078, 0.5312853},
      {0.4540530, -3456789.4396532, 4567890.0207605, 35467899087645678.0485195}
    };
    fill_in_the_matrix(&A, first_example);
    double second_example[3][4] = {
      {0.000001, 0.6424344, 0.8785851, -0.6408750},
      {0.00000001, -4567.1082821, 0.9035930, 0.1530762},
      {0.2812518, 0.2559180, 0.9537255, 0.6256213}
    };
    fill_in_the_matrix(&B, second_example);
    matrix_t D;
    s21_create_matrix(3, 4, &D);
    int return_code_result = s21_sub_matrix(&A, &B, &D);
    ck_assert_int_eq(return_code_result, CALCULATION_ERROR_ENUM);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_sub_matrix_7) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    double first_example[3][4] = {
      {111.9591071, 0.0943366, 0.1646078, 0.5312853},
      {111.9591071, 0.0943366, 0.1646078, 0.5312853},
      {0.4540530, -3456789.4396532, 4567890.0207605, 35467899087645678.0485195}
    };
    fill_in_the_matrix(&A, first_example);
    double second_example[3][4] = {
      {0.000001, 0.6424344, 0.8785851, -0.6408750},
      {0.00000001, -4567.1082821, 0.9035930, 0.1530762},
      {0.2812518, 0.2559180, 0.9537255, 0.6256213}
    };
    fill_in_the_matrix(&B, second_example);
    matrix_t D;
    s21_create_matrix(2, 4, &D);
    int return_code_result = s21_sub_matrix(&A, &B, &D);
    ck_assert_int_eq(return_code_result, CALCULATION_ERROR_ENUM);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_sub_matrix_8) {
    matrix_t A;
    s21_create_matrix(3, 3, &A);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    double second_example[3][4] = {
      {0.000001, 0.6424344, 0.8785851, -0.6408750},
      {0.00000001, -4567.1082821, 0.9035930, 0.1530762},
      {0.2812518, 0.2559180, 0.9537255, 0.6256213}
    };
    fill_in_the_matrix(&B, second_example);
    matrix_t D;
    s21_create_matrix(3, 4, &D);
    int return_code_result = s21_sub_matrix(&A, &B, &D);
    ck_assert_int_eq(return_code_result, CALCULATION_ERROR_ENUM);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_sub_matrix_9) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    double first_example[3][4] = {
      {111.9591071, 0.0943366, 0.1646078, 0.5312853},
      {111.9591071, 0.0943366, 0.1646078, 0.5312853},
      {0.4540530, -3456789.4396532, 4567890.0207605, 35467899087645678.0485195}
    };
    fill_in_the_matrix(&A, first_example);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    double second_example[3][4] = {
      {0.000001, 0.6424344, 0.8785851, -0.6408750},
      {0.00000001, -4567.1082821, 0.9035930, 0.1530762},
      {0.2812518, 0.2559180, 0.9537255, 0.6256213}
    };
    fill_in_the_matrix(&B, second_example);
    matrix_t D;
    s21_create_matrix(3, 6, &D);
    int return_code_result = s21_sub_matrix(&A, &B, &D);
    ck_assert_int_eq(return_code_result, CALCULATION_ERROR_ENUM);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&D);
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
  s21_create_matrix(3, 4, &third);
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






  /// TEst teststeset 
    printf("Sum failed tests\n");
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    matrix_t B;
    s21_create_matrix(3, 4, &B);
    double t_first_example[3][4] = {
      {111.9591071, 0.0943366, 0.1646078, 0.5312853},
      {0.4540530, -3456789.4396532, 4567890.0207605, 35467899087645678.0485195},
      {0.3382748, -0.9805113, 9090909.1932359, 0.1689479}
    };
    double t_second_example[3][4] = {
      {0.000001, 0.6424344, 0.8785851, -0.6408750},
      {0.00000001, -4567.1082821, 0.9035930, 0.1530762},
      {0.2812518, 0.2559180, 0.9537255, 0.6256213}
    };
    fill_in_the_matrix(&A, t_first_example);
    fill_in_the_matrix(&B, t_second_example);
    matrix_t C;
    s21_create_matrix(3, 4, &C);
    // double t_expected_output[3][4] = {
    //   { -0.959107, -0.094337, -0.164608, -0.531285 },
    //   { -0.454053, -0.439653, -0.020761, -0.048519 },
    //   { -0.338275, -0.980511, -0.193236, -0.168948 }
    // };
    // fill_in_the_matrix(&C, t_expected_output);
    matrix_t D;
    s21_create_matrix(3, 4, &D);
    int result_code_print = s21_sub_matrix(&A, &B, &D);
    printf("result_code_print = %d\n", result_code_print);
    printf("\n\n\nC, expected output:\n");
    print_out_matrix(3, 4, C.matrix);
    printf("End of C:\n");
    printf("D, real output:\n");
    print_out_matrix(3, 4, D.matrix);
    printf("End of D:\n");
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
    s21_remove_matrix(&D);

  // End of etestet

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

  // Compare matrix
  tcase_add_test(tc1_1, test_s21_eq_matrix_1);
  tcase_add_test(tc1_1, test_s21_eq_matrix_2);
  tcase_add_test(tc1_1, test_s21_eq_matrix_3);
  tcase_add_test(tc1_1, test_s21_eq_matrix_4);
  tcase_add_test(tc1_1, test_s21_eq_matrix_5);
  tcase_add_test(tc1_1, test_s21_eq_matrix_6);
  tcase_add_test(tc1_1, test_s21_eq_matrix_7);
  tcase_add_test(tc1_1, test_s21_eq_matrix_8);
  tcase_add_test(tc1_1, test_s21_eq_matrix_9);

  // Sum matrix
  tcase_add_test(tc1_1, test_s21_sum_matrix_1);
  tcase_add_test(tc1_1, test_s21_sum_matrix_2);
  tcase_add_test(tc1_1, test_s21_sum_matrix_3);
  tcase_add_test(tc1_1, test_s21_sum_matrix_4);
  tcase_add_test(tc1_1, test_s21_sum_matrix_5);
  tcase_add_test(tc1_1, test_s21_sum_matrix_6);
  tcase_add_test(tc1_1, test_s21_sum_matrix_7);
  tcase_add_test(tc1_1, test_s21_sum_matrix_8);
  tcase_add_test(tc1_1, test_s21_sum_matrix_9);
  tcase_add_test(tc1_1, test_s21_sum_matrix_10);

  // Substract matrix
  tcase_add_test(tc1_1, test_s21_sub_matrix_1);
  tcase_add_test(tc1_1, test_s21_sub_matrix_2);
  tcase_add_test(tc1_1, test_s21_sub_matrix_3);
  tcase_add_test(tc1_1, test_s21_sub_matrix_4);
  tcase_add_test(tc1_1, test_s21_sub_matrix_5);
  tcase_add_test(tc1_1, test_s21_sub_matrix_6);
  tcase_add_test(tc1_1, test_s21_sub_matrix_7);
  tcase_add_test(tc1_1, test_s21_sub_matrix_8);
  tcase_add_test(tc1_1, test_s21_sub_matrix_9);

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
