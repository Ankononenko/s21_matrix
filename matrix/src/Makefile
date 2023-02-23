FLAGS=-Wall -Werror -Wextra

all: clean s21_matrix.a run

run:
	./matrix.exe

s21_matrix.a:
	gcc $(FLAGS) s21_create_matrix.c s21_remove_matrix.c s21_eq_matrix.c s21_sum_matrix.c s21_sub_matrix.c test.c -o matrix.exe

clean:
	rm -rf *.exe
	