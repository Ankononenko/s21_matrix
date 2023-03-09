#include "s21_matrix.h"
#include <stdlib.h>
#include <time.h>
#include <check.h>

// void print_out_matrix(int rows, int columns, double** result);
void fill_in_the_matrix(matrix_t* matrix, double example_array[][4]);
void fill_in_the_matrix_array_any(int rows, int columns, double** array, double (*example_array)[columns]);
void fill_in_the_matrix_five(matrix_t* matrix, double example_array[][5]);
void fill_in_the_matrix_array(int rows, int columns, double** array, double example_array[][4]);
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
      {0.959107, 0.094336, 0.164607, 0.531285},
      {0.454053, 0.439653, 0.020760, 0.048519},
      {0.338274, 0.980511, 0.193235, 0.168947}
    };
    fill_in_the_matrix(&A, first_example);
    fill_in_the_matrix(&B, first_example);
    matrix_t C;
    s21_create_matrix(3, 4, &C);
    double expected_output[3][4] = {
      {1.918214, 0.188672, 0.329214, 1.062570},
      {0.908106, 0.879306, 0.041520, 0.097038},
      {0.676548, 1.961022, 0.386470, 0.337894}
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
      {0.959107, 0.094336, 0.164607, 0.531285},
      {0.454053, 0.439653, 0.020760, 0.048519},
      {0.338274, 0.980511, 0.193235, 0.168947}
    };
    fill_in_the_matrix(&A, first_example);
    double second_example[3][4] = {
      {0.130255, 0.642434, 0.878585, 0.640875},
      {0.678669, 0.108282, 0.903593, 0.153076},
      {0.281251, 0.255918, 0.953725, 0.625621}
    };
    fill_in_the_matrix(&B, second_example);
    matrix_t C;
    s21_create_matrix(3, 4, &C);
    double expected_result[3][4] = {
      {1.089362, 0.736770, 1.043192, 1.172160},
      {1.132722, 0.547935, 0.924353, 0.201595},
      {0.619525, 1.236429, 1.146960, 0.794568}
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
      {111.959107, 0.094336, 0.164607, 0.531285},
      {0.454053, -3456789.439653, 4567890.020760, 35467899087645678.048519},
      {0.338274, -0.980511, 9090909.193235, 0.168947}
    };
    fill_in_the_matrix(&A, first_example);
    double second_example[3][4] = {
      {0.000001, 0.642434, 0.878585, -0.640875},
      {0.000000, -4567.108282, 0.903593, 0.153076},
      {0.281251, 0.255918, 0.953725, 0.625621}
    };
    fill_in_the_matrix(&B, second_example);
    matrix_t C;
    s21_create_matrix(3, 4, &C);
    double expected_result[3][4] = {
      {111.959108, 0.736770, 1.043192, -0.109590},
      {0.454053, -3461356.547935, 4567890.924353, 35467899087645680.000000},
      {0.619525, -0.724593, 9090910.146960, 0.794568}
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
      {0.959107, 0.094336, 0.164607, 0.531285},
      {0.454053, 0.439653, 0.020760, 0.048519},
      {0.338274, 0.980511, 0.193235, 0.168947}
    };
    fill_in_the_matrix(&B, first_example);
    matrix_t C;
    s21_create_matrix(3, 4, &C);
    double expected_output[3][4] = {
      {-0.959107, -0.094336, -0.164607, -0.531285},
      {-0.454053, -0.439653, -0.020760, -0.048519},
      {-0.338274, -0.980511, -0.193235, -0.168947}
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
      {0.959107, 0.094336, 0.164607, 0.531285},
      {0.454053, 0.439653, 0.020760, 0.048519},
      {0.338274, 0.980511, 0.193235, 0.168947}
    };
    fill_in_the_matrix(&A, first_example);
    double second_example[3][4] = {
      {0.130255, 0.642434, 0.878585, 0.640875},
      {0.678669, 0.108282, 0.903593, 0.153076},
      {0.281251, 0.255918, 0.953725, 0.625621}
    };
    fill_in_the_matrix(&B, second_example);
    matrix_t C;
    s21_create_matrix(3, 4, &C);
    double expected_result[3][4] = {
      {0.828852, -0.548098, -0.713978, -0.109590},
      {-0.224616, 0.331371, -0.882833, -0.104557},
      {0.057023, 0.724593, -0.760490, -0.456674}
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
      {111.959107, 0.094336, 0.164607, 0.531285},
      {0.454053, -3456789.439653, 4567890.020760, 35467899087645678.048519},
      {0.338274, -0.980511, 9090909.193235, 0.168947}
    };
    fill_in_the_matrix(&A, first_example);
    double second_example[3][4] = {
      {0.000001, 0.642434, 0.878585, -0.640875},
      {0.000000, -4567.108282, 0.903593, 0.153076},
      {0.281251, 0.255918, 0.953725, 0.625621}
    };
    fill_in_the_matrix(&B, second_example);
    matrix_t C;
    s21_create_matrix(3, 4, &C);
    double expected_result[3][4] = {
      {111.959106, -0.548098, -0.713978, 1.172160},
      {0.454053, -3452222.331371, 4567889.117167, 35467899087645680.000000},
      {0.057023, -1.236429, 9090908.239510, -0.456674}
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

START_TEST(test_s21_sub_matrix_10) {
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
    int return_code_result = s21_sub_matrix(&A, &B, &D);
    ck_assert_int_eq(return_code_result, ERROR_ENUM);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&D);
}
END_TEST

// Multily by number

START_TEST(test_s21_mult_number_1) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    double first_example[3][4] = {
      {0.959107, 0.094336, 0.164607, 0.531285},
      {0.454053, 0.439653, 0.020760, 0.048519},
      {0.338274, 0.980511, 0.193235, 0.168947}
    };
    fill_in_the_matrix(&A, first_example);
    matrix_t C;
    s21_create_matrix(3, 4, &C);
    double expected_result[3][4] = {
      {1.918214, 0.188672, 0.329214, 1.062570},
      {0.908106, 0.879306, 0.041520, 0.097038},
      {0.676548, 1.961022, 0.386470, 0.337894}
    };
    fill_in_the_matrix(&C, expected_result);
    matrix_t D;
    s21_create_matrix(3, 4, &D);
    int return_code_result = s21_mult_number(&A, 2.0, &D);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    int compare_result = s21_eq_matrix(&C, &D);
    ck_assert_int_eq(compare_result, SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_mult_number_2) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    double first_example[3][4] = {
      {0.000001, 2.0, 0.164607, 0.531285},
      {0.454053, 0.439653, 0.020760, 0.048519},
      {0.338274, 0.980511, 5678909876.193235, 0.168947}
    };
    fill_in_the_matrix(&A, first_example);
    matrix_t C;
    s21_create_matrix(3, 4, &C);
    double expected_result[3][4] = {
      {0.000099, 198.000000, 16.296093, 52.597215},
      {44.951247, 43.525647, 2.055240, 4.803381},
      {33.489126, 97.070589, 562212077743.130249, 16.725753}
    };
    fill_in_the_matrix(&C, expected_result);
    matrix_t D;
    s21_create_matrix(3, 4, &D);
    int return_code_result = s21_mult_number(&A, 99.0, &D);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    int compare_result = s21_eq_matrix(&C, &D);
    ck_assert_int_eq(compare_result, SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_mult_number_3) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    double first_example[3][4] = {
      {0.000001, 2.0, 0.164607, 0.531285},
      {0.454053, 0.439653, 0.020760, 0.048519},
      {0.338274, 0.980511, 5678909876.193235, 0.168947}
    };
    fill_in_the_matrix(&A, first_example);
    matrix_t C;
    s21_create_matrix(3, 4, &C);
    double expected_result[3][4] = {
      {0.000000, 0.000000, 0.000000, 0.000000},
      {0.000000, 0.000000, 0.000000, 0.000000},
      {0.000000, 0.000000, 0.000000, 0.000000}
    };
    fill_in_the_matrix(&C, expected_result);
    matrix_t D;
    s21_create_matrix(3, 4, &D);
    int return_code_result = s21_mult_number(&A, 0.0, &D);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    int compare_result = s21_eq_matrix(&C, &D);
    ck_assert_int_eq(compare_result, SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_mult_number_4) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    double first_example[3][4] = {
      {-0.000001, -2.0, -0.164607, -0.531285},
      {-0.454053, -0.439653, -0.020760, -0.048519},
      {-0.338274, -0.980511, -5678909876.193235, -0.168947}
    };
    fill_in_the_matrix(&A, first_example);
    matrix_t C;
    s21_create_matrix(3, 4, &C);
    double expected_result[3][4] = {
      {-0.000042, -84.000000, -6.913494, -22.313970},
      {-19.070226, -18.465426, -0.871920, -2.037798},
      {-14.207508, -41.181462, -238514214800.115875, -7.095774}
    };
    fill_in_the_matrix(&C, expected_result);
    matrix_t D;
    s21_create_matrix(3, 4, &D);
    int return_code_result = s21_mult_number(&A, 42.0, &D);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    int compare_result = s21_eq_matrix(&C, &D);
    ck_assert_int_eq(compare_result, SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_mult_number_5) {
    matrix_t A;
    s21_create_matrix(0, 4, &A);
    matrix_t D;
    s21_create_matrix(3, 4, &D);
    int return_code_result = s21_mult_number(&A, 42.0, &D);
    ck_assert_int_eq(return_code_result, ERROR_ENUM);
    s21_remove_matrix(&A);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_mult_number_6) {
    matrix_t A;
    s21_create_matrix(4, 3, &A);
    matrix_t D;
    s21_create_matrix(42, 4, &D);
    int return_code_result = s21_mult_number(&A, 42.0, &D);
    ck_assert_int_eq(return_code_result, CALCULATION_ERROR_ENUM);
    s21_remove_matrix(&A);
    s21_remove_matrix(&D);
}
END_TEST

// Multiply by matrix

START_TEST(test_s21_mult_matrix_1) {
    matrix_t A;
    s21_create_matrix(2, 3, &A);

    A.matrix[0][0] = 1.0;
    A.matrix[0][1] = 2.0;
    A.matrix[0][2] = 3.0;

    A.matrix[1][0] = 1.0;
    A.matrix[1][1] = 2.0;
    A.matrix[1][2] = 3.0;

    matrix_t B;
    s21_create_matrix(3, 2, &B);
    
    B.matrix[0][0] = 1.0;
    B.matrix[0][1] = 2.0;
    
    B.matrix[1][0] = 1.0;
    B.matrix[1][1] = 2.0;

    B.matrix[2][0] = 1.0;
    B.matrix[2][1] = 2.0;

    matrix_t C;
    s21_create_matrix(2, 2, &C);

    C.matrix[0][0] = 6.0;
    C.matrix[0][1] = 12.0;
    
    C.matrix[1][0] = 6.0;
    C.matrix[1][1] = 12.0;

    matrix_t D;
    s21_create_matrix(2, 2, &D);
    int return_code_result = s21_mult_matrix(&A, &B, &D);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    int compare_result = s21_eq_matrix(&C, &D);
    ck_assert_int_eq(compare_result, SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_mult_matrix_2) {
    matrix_t A;
    s21_create_matrix(0, 3, &A);

    matrix_t B;
    s21_create_matrix(3, 2, &B);
    
    B.matrix[0][0] = 1.0;
    B.matrix[0][1] = 2.0;
    
    B.matrix[1][0] = 1.0;
    B.matrix[1][1] = 2.0;

    B.matrix[2][0] = 1.0;
    B.matrix[2][1] = 2.0;

    matrix_t D;
    s21_create_matrix(2, 2, &D);
    int return_code_result = s21_mult_matrix(&A, &B, &D);
    ck_assert_int_eq(return_code_result, ERROR_ENUM);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_mult_matrix_3) {
    matrix_t A;
    s21_create_matrix(2, 2, &A);

    A.matrix[0][0] = 1.0;
    A.matrix[0][1] = 2.0;

    A.matrix[1][0] = 1.0;
    A.matrix[1][1] = 2.0;

    matrix_t B;
    s21_create_matrix(3, 2, &B);
    
    B.matrix[0][0] = 1.0;
    B.matrix[0][1] = 2.0;
    
    B.matrix[1][0] = 1.0;
    B.matrix[1][1] = 2.0;

    B.matrix[2][0] = 1.0;
    B.matrix[2][1] = 2.0;

    matrix_t D;
    s21_create_matrix(2, 2, &D);
    int return_code_result = s21_mult_matrix(&A, &B, &D);
    ck_assert_int_eq(return_code_result, CALCULATION_ERROR_ENUM);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&D);
}
END_TEST

// Transpose

START_TEST(test_s21_transpose_1) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    double first_example[3][4] = {
      {0.000001, 0.6424344, 0.8785851, -0.6408750},
      {0.00000001, -4567.1082821, 0.9035930, 0.1530762},
      {0.2812518, 0.2559180, 0.9537255, 0.6256213}
    };
    fill_in_the_matrix(&A, first_example);
    
    matrix_t B;
    s21_create_matrix(4, 3, &B);
    B.matrix[0][0] = 0.000001;
    B.matrix[0][1] = 0.00000001;
    B.matrix[0][2] = 0.2812518;

    B.matrix[1][0] = 0.6424344;
    B.matrix[1][1] = -4567.1082821;
    B.matrix[1][2] = 0.255918;

    B.matrix[2][0] = 0.8785851;
    B.matrix[2][1] = 0.903593;
    B.matrix[2][2] = 0.9537255;

    B.matrix[3][0] = -0.640875;
    B.matrix[3][1] = 0.1530762;
    B.matrix[3][2] = 0.6256213;

    matrix_t D;
    int return_code_result = s21_transpose(&A, &D);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    
    int compare_result = s21_eq_matrix(&B, &D);
    ck_assert_int_eq(compare_result, SUCCESS);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_transpose_2) {
    matrix_t A;
    s21_create_matrix(0, 4, &A);
    matrix_t D;
    int return_code_result = s21_transpose(&A, &D);
    ck_assert_int_eq(return_code_result, ERROR_ENUM);
    s21_remove_matrix(&A);
}
END_TEST

// Calc complements

//     1 2 3
// A = 0 4 2
//     5 2 1

START_TEST(test_s21_calc_complements_00) {
    matrix_t A;
    s21_create_matrix(3, 3, &A);
    A.matrix[0][0] = 1.0;
    A.matrix[0][1] = 2.0;
    A.matrix[0][2] = 3.0;
    A.matrix[1][0] = 0.0;
    A.matrix[1][1] = 4.0;
    A.matrix[1][2] = 2.0;
    A.matrix[2][0] = 5.0;
    A.matrix[2][1] = 2.0;
    A.matrix[2][2] = 1.0;
    matrix_t B;
    s21_create_matrix(3, 3, &B);
    B.matrix[0][0] = 0.0;
    B.matrix[0][1] = 10.0;
    B.matrix[0][2] = -20.0;
    B.matrix[1][0] = 4.0;
    B.matrix[1][1] = -14.0;
    B.matrix[1][2] = 8.0;
    B.matrix[2][0] = -8.0;
    B.matrix[2][1] = -2.0;
    B.matrix[2][2] = 4.0;
    matrix_t D;
    int return_code_result = s21_calc_complements(&A, &D);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    int compare_result = s21_eq_matrix(&B, &D);
    ck_assert_int_eq(compare_result, SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_calc_complements_0) {
    matrix_t A;
    s21_create_matrix(3, 3, &A);
    A.matrix[0][0] = 1.0;
    A.matrix[0][1] = 2.0;
    A.matrix[0][2] = 3.0;
    A.matrix[1][0] = 1.0;
    A.matrix[1][1] = 3.0;
    A.matrix[1][2] = 2.0;
    A.matrix[2][0] = 5.0;
    A.matrix[2][1] = 2.0;
    A.matrix[2][2] = 1.0;
    matrix_t B;
    s21_create_matrix(3, 3, &B);
    B.matrix[0][0] = -1.0;
    B.matrix[0][1] = 9.0;
    B.matrix[0][2] = -13.0;
    B.matrix[1][0] = 4.0;
    B.matrix[1][1] = -14.0;
    B.matrix[1][2] = 8.0;
    B.matrix[2][0] = -5.0;
    B.matrix[2][1] = 1.0;
    B.matrix[2][2] = 1.0;
    matrix_t D;
    int return_code_result = s21_calc_complements(&A, &D);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    int compare_result = s21_eq_matrix(&B, &D);
    ck_assert_int_eq(compare_result, SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_calc_complements_1) {
    matrix_t A;
    s21_create_matrix(4, 4, &A);
    double first_example[4][4] = {
      {1.0, 2.0, 3.0, 4.0},
      {5.0, 6.0, 7.0, 8.0},
      {9.0, 10.0, 11.0, 12.0},
      {13.0, 14.0, 15.0, 16.0}
    };
    fill_in_the_matrix(&A, first_example);
    matrix_t B;
    s21_create_matrix(4, 4, &B);
    double second_example[4][4] = {
      {0.0, 0.0, 0.0, 0.0},
      {0.0, 0.0, 0.0, 0.0},
      {0.0, 0.0, 0.0, 0.0},
      {0.0, 0.0, 0.0, 0.0}
    };
    fill_in_the_matrix(&B, second_example);
    matrix_t D;
    int return_code_result = s21_calc_complements(&A, &D);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    int compare_result = s21_eq_matrix(&B, &D);
    ck_assert_int_eq(compare_result, SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_calc_complements_2) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    double first_example[3][4] = {
      {1.0, 2.0, 3.0, 4.0},
      {5.0, 6.0, 7.0, 8.0},
      {9.0, 10.0, 11.0, 12.0}
    };
    fill_in_the_matrix(&A, first_example);
    matrix_t D;
    int return_code_result = s21_calc_complements(&A, &D);
    ck_assert_int_eq(return_code_result, CALCULATION_ERROR_ENUM);
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_calc_complements_3) {
    matrix_t A;
    s21_create_matrix(1, 1, &A);
    A.matrix[0][0] = 42.0;
  matrix_t B;
    s21_create_matrix(1, 1, &B);
    B.matrix[0][0] = 42.0;
    matrix_t D;
    int return_code_result = s21_calc_complements(&A, &D);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    int compare_result = s21_eq_matrix(&B, &D);
    ck_assert_int_eq(compare_result, SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_calc_complements_4) {
    matrix_t A;
    s21_create_matrix(2, 2, &A);
    A.matrix[0][0] = 13.0;
    A.matrix[0][1] = 21.0;
    A.matrix[1][0] = 42.0;
    A.matrix[1][1] = 69.0;
    matrix_t B;
    s21_create_matrix(2, 2, &B);
    B.matrix[0][0] = 69.0;
    B.matrix[0][1] = -42.0;
    B.matrix[1][0] = -21.0;
    B.matrix[1][1] = 13.0;
    matrix_t D;
    int return_code_result = s21_calc_complements(&A, &D);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    int compare_result = s21_eq_matrix(&B, &D);
    ck_assert_int_eq(compare_result, SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_calc_complements_5) {
    matrix_t A;
    s21_create_matrix(4, 4, &A);
    double first_example[4][4] = {
      {0.0, 2.0, 5.0, 57.0},
      {5.0, 2.0, 6.0, 7.0},
      {1.0, 3.0, 7.0, 6.0},
      {45.0, 8.0, 15.0, 4.0}
    };
    fill_in_the_matrix(&A, first_example);
    matrix_t B;
    s21_create_matrix(4, 4, &B);
    double second_example[4][4] = {
      {15.0, 814.0, -537.0, 217.0},
      {571.0, -15770.0, 6707.0, -35.0},
      {-948.0, 9640.0, -2260.0, -140.0},
      {209.0, 1538.0, -695.0, 7.0}
    };
    fill_in_the_matrix(&B, second_example);
    matrix_t D;
    int return_code_result = s21_calc_complements(&A, &D);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    int compare_result = s21_eq_matrix(&B, &D);
    ck_assert_int_eq(compare_result, SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&D);
}
END_TEST

// Too big will try to fix later
// START_TEST(test_s21_calc_complements_6) {
//     matrix_t A;
//     s21_create_matrix(5, 5, &A);
//     double first_example[5][5] = {
//       {0.0, 2.0, 5.0, 57.0, 10.0},
//       {5.0, 2.0, 6.0, 7.0, 15.0},
//       {1.0, 3.0, 7.0, 6.0, 20.0},
//       {45.0, 8.0, 15.0, 4.0, 25.0},
//       {8.0, 10.0, 12.0, 16.0, 30.0}
//     };
//     fill_in_the_matrix_five(&A, first_example);
//     matrix_t B;
//     s21_create_matrix(5, 5, &B);
//     double second_example[5][5] = {
//       {64.0, -2368.0, -506.0, 3073.0, 1516.0},
//       {4595.0, -2635.0, -2365.0, -7275.0, -1438.0},
//       {-2491.0, 11439.0, 6804.0, 12541.0, -2162.0},
//       {-1090.0, -1485.0, -865.0, 4045.0, 1100.0},
//       {-4575.0, -4195.0, -6284.0, -6455.0, 3335.0}
//     };
//     fill_in_the_matrix_five(&B, second_example);
//     matrix_t D;
//     int return_code_result = s21_calc_complements(&A, &D);
//     printf("%d", return_code_result);
//     ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
//     // int compare_result = s21_eq_matrix(&B, &D);
//     // ck_assert_int_eq(compare_result, SUCCESS);
//     s21_remove_matrix(&A);
//     s21_remove_matrix(&B);
//     s21_remove_matrix(&D);
// }
// END_TEST

// Determinant

//     1 2 3
// A = 0 4 2
//     5 2 1

START_TEST(test_s21_determinant_00) {
    matrix_t A;
    s21_create_matrix(3, 3, &A);
    A.matrix[0][0] = 1.0;
    A.matrix[0][1] = 2.0;
    A.matrix[0][2] = 3.0;
    A.matrix[1][0] = 0.0;
    A.matrix[1][1] = 4.0;
    A.matrix[1][2] = 2.0;
    A.matrix[2][0] = 5.0;
    A.matrix[2][1] = 2.0;
    A.matrix[2][2] = 1.0;
    double expected_result = -40.0;
    double actual_result;
    int return_code_result = s21_determinant(&A, &actual_result);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    ck_assert_double_eq(expected_result, actual_result);
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_01) {
    matrix_t A;
    s21_create_matrix(4, 4, &A);
    A.matrix[0][0] = 5;
    A.matrix[0][1] = 4;
    A.matrix[0][2] = 13;
    A.matrix[0][3] = 7;

    A.matrix[1][0] = 5;
    A.matrix[1][1] = 10;
    A.matrix[1][2] = 23;
    A.matrix[1][3] = 11;

    A.matrix[2][0] = 13;
    A.matrix[2][1] = 6;
    A.matrix[2][2] = 9;
    A.matrix[2][3] = 8;

    A.matrix[3][0] = 20;
    A.matrix[3][1] = 12;
    A.matrix[3][2] = 4;
    A.matrix[3][3] = 7;

    double determinant = 0.0;

    int return_code_result = s21_determinant(&A, &determinant);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    ck_assert_double_eq(determinant, 596.0);
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_02) {
    matrix_t A;
    s21_create_matrix(4, 4, &A);
    double first_example[4][4] = {
      {1.0, 2.0, 3.0, 4.0},
      {5.0, 6.0, 7.0, 8.0},
      {9.0, 10.0, 11.0, 12.0},
      {13.0, 14.0, 15.0, 16.0}
    };
    fill_in_the_matrix(&A, first_example);
    double determinant = 0.0;
    int return_code_result = s21_determinant(&A, &determinant);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    ck_assert_double_eq(determinant, 0.0);
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_03) {
    matrix_t A;
    s21_create_matrix(3, 4, &A);
    double first_example[3][4] = {
      {1.0, 2.0, 3.0, 4.0},
      {5.0, 6.0, 7.0, 8.0},
      {9.0, 10.0, 11.0, 12.0}
    };
    fill_in_the_matrix_array_any(A.rows, A.columns, A.matrix, first_example);
    double determinant = 0.0;
    int return_code_result = s21_determinant(&A, &determinant);
    ck_assert_int_eq(return_code_result, CALCULATION_ERROR_ENUM);
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_04) {
    matrix_t A;
    s21_create_matrix(1, 1, &A);
    A.matrix[0][0] = 42.0;
    double determinant = 0.0;
    int return_code_result = s21_determinant(&A, &determinant);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    ck_assert_double_eq(determinant, 42.0);
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_05) {
    matrix_t A;
    s21_create_matrix(2, 2, &A);
    A.matrix[0][0] = 13.0;
    A.matrix[0][1] = 21.0;
    A.matrix[1][0] = 42.0;
    A.matrix[1][1] = 69.0;
    double determinant = 0.0;
    int return_code_result = s21_determinant(&A, &determinant);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    ck_assert_double_eq(determinant, 15.0);
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_06) {
    matrix_t A;
    s21_create_matrix(5, 5, &A);
    double first_example[5][5] = {
    {6.0, -2.0, -1.0, 5.0, 4.0},
    {3.0, 4.0, -5.0, 8.0, 8.0},
    {1.0, -5.0, 2.0, -9.0, -3.0},
    {4.0, 3.0, 8.0, 9.0, 1.0},
    {4.0, 2.0, 3.0, 4.0, 6.0}
    };
    fill_in_the_matrix_array_any(A.rows, A.columns, A.matrix, first_example);
    double determinant = 0.0;
    int return_code_result = s21_determinant(&A, &determinant);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    ck_assert_double_eq(determinant, 4032.0);
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_07) {
    matrix_t A;
    s21_create_matrix(0, 5, &A);
    double determinant = 0.0;
    int return_code_result = s21_determinant(&A, &determinant);
    ck_assert_int_eq(return_code_result, ERROR_ENUM);
    s21_remove_matrix(&A);
}
END_TEST

// Inverse

START_TEST(test_s21_inverse_1) {
    matrix_t A;
    s21_create_matrix(3, 3, &A);
    double first_example[3][3] = {
      {2.0, 5.0, 7.0},
      {6.0, 3.0, 4.0},
      {5.0, -2.0, -3.0}
    };
    fill_in_the_matrix_array_any(A.rows, A.columns, A.matrix, first_example);
    matrix_t B;
    s21_create_matrix(3, 3, &B);
    double expected[3][3] = {
      {-1.0, 1.0, -1.0},
      {38.0, -41.0, 34.0},
      {-27.0, 29.0, -24.0}
    };
    fill_in_the_matrix_array_any(B.rows, B.columns, B.matrix, expected);
    matrix_t D;
    int return_code_result = s21_inverse_matrix(&A, &D);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    int compare_result = s21_eq_matrix(&B, &D);
    ck_assert_int_eq(compare_result, SUCCESS);
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_2) {
    matrix_t A;
    s21_create_matrix(1, 1, &A);
    A.matrix[0][0] = 1.0;
    matrix_t B;
    s21_create_matrix(1, 1, &B);
    B.matrix[0][0] = 1.0;
    matrix_t D;
    int return_code_result = s21_inverse_matrix(&A, &D);
    ck_assert_int_eq(return_code_result, SUCCESS_ENUM);
    int compare_result = s21_eq_matrix(&B, &D);
    ck_assert_int_eq(compare_result, SUCCESS);
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_3) {
    matrix_t A;
    s21_create_matrix(0, 3, &A);
    matrix_t D;
    int return_code_result = s21_inverse_matrix(&A, &D);
    ck_assert_int_eq(return_code_result, ERROR_ENUM);
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_4) {
    matrix_t A;
    s21_create_matrix(2, 3, &A);
    double first_example[2][3] = {
      {2.0, 5.0, 7.0},
      {6.0, 3.0, 4.0}
    };
    fill_in_the_matrix_array_any(A.rows, A.columns, A.matrix, first_example);
    matrix_t D;
    int return_code_result = s21_inverse_matrix(&A, &D);
    ck_assert_int_eq(return_code_result, CALCULATION_ERROR_ENUM);
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_5) {
    matrix_t A;
    s21_create_matrix(4, 4, &A);
    double first_example[4][4] = {
      {1.0, 2.0, 3.0, 4.0},
      {5.0, 6.0, 7.0, 8.0},
      {9.0, 10.0, 11.0, 12.0},
      {13.0, 14.0, 15.0, 16.0},
    };
    fill_in_the_matrix_array_any(A.rows, A.columns, A.matrix, first_example);
    matrix_t D;
    int return_code_result = s21_inverse_matrix(&A, &D);
    ck_assert_int_eq(return_code_result, CALCULATION_ERROR_ENUM);
    s21_remove_matrix(&A);
}
END_TEST

int main(void) {

  // matrix_t first;
  // printf("Create:\n");
  // s21_create_matrix(5, 5, &first);
  // printf("rows = %d, columns = %d\n", first.rows, first.columns);
  // print_out_matrix(first.rows, first.columns, first.matrix);

  // printf("End of the test\n\n\n");

  // printf("Remove:\n");
  // s21_remove_matrix(&first);
  // print_out_matrix(first.rows, first.columns, first.matrix);

  // printf("End of the test\n\n\n");

  // printf("First compare:\n");
  // s21_create_matrix(5, 5, &first);
  // printf("rows = %d, columns = %d\n", first.rows, first.columns);
  // print_out_matrix(first.rows, first.columns, first.matrix);
  // printf("Second compare:\n");
  // matrix_t second;
  // s21_create_matrix(5, 5, &second);
  // printf("rows = %d, columns = %d\n", second.rows, second.columns);
  // print_out_matrix(second.rows, second.columns, second.matrix);
  // printf("Compare:\n");
  // int first_and_second = s21_eq_matrix(&first, &second);
  // printf("Compare first and second, equal: %d\n", first_and_second);

  // s21_remove_matrix(&first);
  // s21_remove_matrix(&second);

  // printf("End of the test\n\n\n");

  // printf("Second compare not equal test:\n");
  // s21_create_matrix(1, 5, &first);
  // printf("rows = %d, columns = %d\n", first.rows, first.columns);
  // print_out_matrix(first.rows, first.columns, first.matrix);
  // s21_create_matrix(5, 1, &second);
  // printf("rows = %d, columns = %d\n", second.rows, second.columns);
  // print_out_matrix(second.rows, second.columns, second.matrix);
  // printf("Compare:\n");
  // first_and_second = s21_eq_matrix(&first, &second);
  // printf("Compare first and second, not equal: %d\n", first_and_second);

  // s21_remove_matrix(&first);
  // s21_remove_matrix(&second);

  // printf("End of the test\n\n\n");

  // printf("Compare the double equal matrix\n");
  // s21_create_matrix(3, 4, &first);
  // double first_example[3][4] = {
  //   {0.9591071, 0.0943366, 0.1646078, 0.5312853},
  //   {0.4540530, 0.4396532, 0.0207605, 0.0485195},
  //   {0.3382748, 0.9805113, 0.1932359, 0.1689479}
  // };
  // fill_in_the_matrix(&first, first_example);
  // print_out_matrix(first.rows, first.columns, first.matrix);
  // s21_create_matrix(3, 4, &second);
  // fill_in_the_matrix(&second, first_example);
  // print_out_matrix(second.rows, second.columns, second.matrix);
  // first_and_second = s21_eq_matrix(&first, &second);
  // printf("Compare first and second, equal: %d\n", first_and_second);

  // s21_remove_matrix(&first);
  // s21_remove_matrix(&second);

  // printf("End of the test\n\n\n");

  // printf("Compare the double not equal matrix\n");
  // s21_create_matrix(3, 4, &first);
  // double second_example[3][4] = {
  //   {0.1302556, 0.6424344, 0.8785851, 0.6408750},
  //   {0.6786694, 0.1082821, 0.9035930, 0.1530762},
  //   {0.2812518, 0.2559180, 0.9537255, 0.6256213}
  // };
  // fill_in_the_matrix(&first, first_example);
  // print_out_matrix(first.rows, first.columns, first.matrix);
  // s21_create_matrix(3, 4, &second);
  // fill_in_the_matrix(&second, second_example);
  // print_out_matrix(second.rows, second.columns, second.matrix);
  // first_and_second = s21_eq_matrix(&first, &second);
  // printf("Compare first and second, not equal: %d\n", first_and_second);

  // s21_remove_matrix(&first);
  // s21_remove_matrix(&second);

  // printf("End of the test\n\n\n");

  // printf("Sum two matrix\n");
  // s21_create_matrix(3, 4, &first);
  // fill_in_the_matrix(&first, first_example);
  // print_out_matrix(first.rows, first.columns, first.matrix);
  // s21_create_matrix(3, 4, &second);
  // fill_in_the_matrix(&second, second_example);
  // print_out_matrix(second.rows, second.columns, second.matrix);
  // matrix_t third;
  // s21_create_matrix(3, 4, &third);
  // s21_sum_matrix(&first, &second, &third);
  // print_out_matrix(third.rows, third.columns, third.matrix);
  // printf("expected_result:\n"
  //   "1.089362 0.736771 1.043193 1.172160\n"
  //   "1.132722 0.547935 0.924353 0.201595\n"
  //   "0.619526 1.236429 1.146961 0.794569\n"
  //   );
  // s21_remove_matrix(&first);
  // s21_remove_matrix(&second);
  // s21_remove_matrix(&third);

  // printf("End of the test\n\n\n");

  // printf("Substract two matrix\n");
  // s21_create_matrix(3, 4, &first);
  // fill_in_the_matrix(&first, first_example);
  // print_out_matrix(first.rows, first.columns, first.matrix);
  // s21_create_matrix(3, 4, &second);
  // fill_in_the_matrix(&second, second_example);
  // print_out_matrix(second.rows, second.columns, second.matrix);
  // s21_sub_matrix(&first, &second, &third);
  // print_out_matrix(third.rows, third.columns, third.matrix);
  // printf("expected_result:\n"
  //   "0.828851 -0.548098 -0.713977 -0.109590\n"
  //   "-0.224616 0.331371 -0.882833 -0.104556\n" 
  //   "0.057023 0.724593 -0.760489 -0.456673 \n"
  //   );
  // s21_remove_matrix(&first);
  // s21_remove_matrix(&second);
  // s21_remove_matrix(&third);

  // printf("End of the test\n\n\n");

  /// Current example
  
  // printf("Current example\n");
  
  // matrix_t A;
  // s21_create_matrix(5, 5, &A);
  // double first_example_t[5][5] = {
  //   {0.0, 2.0, 5.0, 57.0, 10.0},
  //   {5.0, 2.0, 6.0, 7.0, 15.0},
  //   {1.0, 3.0, 7.0, 6.0, 20.0},
  //   {45.0, 8.0, 15.0, 4.0, 25.0},
  //   {8.0, 10.0, 12.0, 16.0, 30.0}
  // };
  // fill_in_the_matrix_five(&A, first_example_t);
  // matrix_t B;
  // s21_create_matrix(5, 5, &B);
  // double second_example_t[5][5] = {
  //   {64.0, -2368.0, -506.0, 3073.0, 1516.0},
  //   {4595.0, -2635.0, -2365.0, -7275.0, -1438.0},
  //   {-2491.0, 11439.0, 6804.0, 12541.0, -2162.0},
  //   {-1090.0, -1485.0, -865.0, 4045.0, 1100.0},
  //   {-4575.0, -4195.0, -6284.0, -6455.0, 3335.0}
  // };
  // fill_in_the_matrix_five(&B, second_example_t);
  // matrix_t D;
  // int return_code_result = s21_calc_complements(&A, &D);
  // printf("return code = %d", return_code_result);
  // printf("B, expected output:\n");
  // print_out_matrix(5, 5, B.matrix);
  // printf("End of B:\n");
  // printf("D, real output:\n");
  // print_out_matrix(5, 5, D.matrix);
  // printf("End of D:\n");
  // s21_remove_matrix(&A);
  // s21_remove_matrix(&B);
  // s21_remove_matrix(&D);

  // End of current example

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
  tcase_add_test(tc1_1, test_s21_sub_matrix_10);

  // Multiply matrix by number
  tcase_add_test(tc1_1, test_s21_mult_number_1);
  tcase_add_test(tc1_1, test_s21_mult_number_2);
  tcase_add_test(tc1_1, test_s21_mult_number_3);
  tcase_add_test(tc1_1, test_s21_mult_number_4);
  tcase_add_test(tc1_1, test_s21_mult_number_5);
  tcase_add_test(tc1_1, test_s21_mult_number_6);

  // Multiply by matrix
  tcase_add_test(tc1_1, test_s21_mult_matrix_1);
  tcase_add_test(tc1_1, test_s21_mult_matrix_2);
  tcase_add_test(tc1_1, test_s21_mult_matrix_3);

  // Transpose matrix
  tcase_add_test(tc1_1, test_s21_transpose_1);
  tcase_add_test(tc1_1, test_s21_transpose_2);

  // Minor of matrix and matrix of algebraic complements
  tcase_add_test(tc1_1, test_s21_calc_complements_00);
  tcase_add_test(tc1_1, test_s21_calc_complements_0);
  tcase_add_test(tc1_1, test_s21_calc_complements_1);
  tcase_add_test(tc1_1, test_s21_calc_complements_2);
  tcase_add_test(tc1_1, test_s21_calc_complements_3);
  tcase_add_test(tc1_1, test_s21_calc_complements_4);
  tcase_add_test(tc1_1, test_s21_calc_complements_5);
  // tcase_add_test(tc1_1, test_s21_calc_complements_6);
  
  // Determinant tests
  tcase_add_test(tc1_1, test_s21_determinant_00);
  tcase_add_test(tc1_1, test_s21_determinant_01);
  tcase_add_test(tc1_1, test_s21_determinant_02);
  tcase_add_test(tc1_1, test_s21_determinant_03);
  tcase_add_test(tc1_1, test_s21_determinant_04);
  tcase_add_test(tc1_1, test_s21_determinant_05);
  tcase_add_test(tc1_1, test_s21_determinant_06);
  tcase_add_test(tc1_1, test_s21_determinant_07);

  // Inverse
  tcase_add_test(tc1_1, test_s21_inverse_1);
  tcase_add_test(tc1_1, test_s21_inverse_2);
  tcase_add_test(tc1_1, test_s21_inverse_3);
  tcase_add_test(tc1_1, test_s21_inverse_4);
  tcase_add_test(tc1_1, test_s21_inverse_5);

  srunner_run_all(sr, CK_ENV);
  result = srunner_ntests_failed(sr);
  srunner_free(sr);
  return result == 0 ? 0 : 1;
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

void fill_in_the_matrix(matrix_t* matrix, double example_array[][4]) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      matrix->matrix[i][j] = example_array[i][j];
    }
  }
}

void fill_in_the_matrix_five(matrix_t* matrix, double example_array[][5]) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      matrix->matrix[i][j] = example_array[i][j];
    }
  }
}

void fill_in_the_matrix_array(int rows, int columns, double** array, double example_array[][4]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      array[i][j] = example_array[i][j];
    }
  }
}

void fill_in_the_matrix_array_any(int rows, int columns, double** array, double (*example_array)[columns]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      array[i][j] = (*example_array)[i * columns + j];
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
