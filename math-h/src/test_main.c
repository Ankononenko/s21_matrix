#include <stdio.h>
#include <limits.h>
#include "s21_math.h"
#include <check.h>
#include "tests/tests.h"

int main() {
    Suite *math = suite_create("Math");
    TCase *t_abs = tcase_create("ABS");
    TCase *t_pow = tcase_create("POW");

    TCase *t_sqrt = tcase_create("SQRT");
    TCase *t_fabs = tcase_create("FABS");

    TCase *t_exp = tcase_create("EXP");

    TCase *t_ceil = tcase_create("CEIL");
    TCase *t_floor = tcase_create("FLOOR");
    TCase *t_fmod = tcase_create("FMOD");

    TCase *t_log = tcase_create("LOG");

    SRunner *sr = srunner_create(math);
    Suite *helpers = suite_create("Helpers");
    TCase *t_fact = tcase_create("Factorial");
    SRunner *sr2 = srunner_create(helpers);
    Suite *trigonometry = suite_create("Trigonometry");
    TCase *t_sin = tcase_create("SIN");
    TCase *t_cos = tcase_create("COS");
    TCase *t_tan = tcase_create("TAN");
    TCase *t_atan = tcase_create("ATAN");
    TCase *t_asin = tcase_create("ASIN");
    TCase *t_acos = tcase_create("ACOS");
    SRunner *sr3 = srunner_create(trigonometry);

    suite_add_tcase(math, t_abs);
    abs_tests(t_abs);


    suite_add_tcase(math, t_pow);
    pow_tests(t_pow);

    suite_add_tcase(math, t_sqrt);
    sqrt_tests(t_sqrt);
    suite_add_tcase(math, t_fabs);
    fabs_tests(t_fabs);

    suite_add_tcase(math, t_exp);
    exp_tests(t_exp);

    suite_add_tcase(helpers, t_fact);
    fact_tests(t_fact);
    suite_add_tcase(trigonometry, t_sin);
    sin_tests(t_sin);
    suite_add_tcase(trigonometry, t_cos);
    cos_tests(t_cos);
    suite_add_tcase(trigonometry, t_tan);
    tan_tests(t_tan);

    suite_add_tcase(math, t_log);
    log_tests(t_log);

    suite_add_tcase(trigonometry, t_atan);
    atan_tests(t_atan);
    suite_add_tcase(trigonometry, t_asin);
    asin_tests(t_asin);
    suite_add_tcase(trigonometry, t_acos);
    acos_tests(t_acos);
    suite_add_tcase(math, t_ceil);
    ceil_tests(t_ceil);
    suite_add_tcase(math, t_floor);
    floor_tests(t_floor);
    suite_add_tcase(math, t_fmod);
    fmod_tests(t_fmod);

    puts("\033[31m");
    srunner_set_fork_status(sr2, CK_NOFORK);
    srunner_run_all(sr2, CK_NORMAL);
    srunner_free(sr2);
    puts("\033[32m");
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);
    puts("\033[34m");
    srunner_set_fork_status(sr3, CK_NOFORK);
    srunner_run_all(sr3, CK_NORMAL);
    srunner_free(sr3);
    puts("\033[30m");

    return 0;
}
