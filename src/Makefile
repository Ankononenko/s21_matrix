CC = gcc
FLAG = -Wall -Werror -Wextra -g
FLAGS = -g -Wall -Wextra
LIBS = -lcheck
ALL_FILES = s21_helpers.c s21_create_matrix.c s21_remove_matrix.c s21_eq_matrix.c s21_sum_matrix.c s21_sub_matrix.c s21_mult_number.c s21_mult_matrix.c s21_transpose.c s21_calc_complements.c s21_determinant.c s21_inverse_matrix.c

all: clean s21_matrix.a

s21_matrix.a:
	$(CC) $(FLAGS) $(ALL_FILES) -c
	ar rcs s21_matrix.a *.o

test: s21_matrix.a
	$(CC) test.c s21_matrix.a $(FLAG) -o test.a $(LIBS)
	./test.a

gcov_report:
	$(CC) --coverage $(ALL_FILES) test.c $(LIBS) -o gcov_report.o
	./gcov_report.o
	lcov -t s21_matrix_tests -o s21_matrix_tests.info -c -d .
	genhtml -o report s21_matrix_tests.info

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem .

style:
	clang-format -i *.c --style=Google
	clang-format -i *.h --style=Google

clean:
	rm -f *.a
	rm -f *.o
	rm -f *.gcda
	rm -f *.gcdo
	rm -f *.gcno
	rm -f *.info