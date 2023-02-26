CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBS = -lcheck

all: clean s21_matrix.a run

run:
	./matrix.exe

s21_matrix.a:
	$(CC) $(FLAGS) s21_helpers.c s21_create_matrix.c s21_remove_matrix.c s21_eq_matrix.c s21_sum_matrix.c s21_sub_matrix.c s21_mult_number.c s21_mult_matrix.c test.c -o matrix.exe $(LIBS)

clean:
	rm -rf *.exe
	