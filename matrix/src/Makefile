FLAGS=-Wall -Werror -Wextra

all: clean matrix.exe run

run:
	./matrix.exe

matrix.exe:
	gcc $(FLAGS) s21_create_matrix.c s21_remove_matrix.c s21_eq_matrix.c s21_sum_matrix.c test.c -o matrix.exe

clean:
	rm -rf *.exe
	