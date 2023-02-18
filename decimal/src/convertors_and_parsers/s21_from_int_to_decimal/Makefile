CC = gcc
C_FLAGS = -Wall -Werror -Wextra -std=c11 -pedantic -g
RM = rm -f

default: all

all: clean s21_from_int_to_decimal run

s21_from_int_to_decimal: s21_from_int_to_decimal.c s21_from_int_to_decimal.h test.c test.h ../../bit_control/bit_control.c ../../bit_control/bit_control.h ../../helpers/helpers.h ../../helpers/init_decimal.c ../../helpers/set_sign.c ../../s21_decimal.h
	$(CC) $(C_FLAGS) -o s21_from_int_to_decimal.exe s21_from_int_to_decimal.c test.c test.h s21_from_int_to_decimal.h ../../bit_control/bit_control.c ../../helpers/helpers.h ../../helpers/init_decimal.c ../../helpers/set_sign.c ../../s21_decimal.h

run:
	./s21_from_int_to_decimal.exe

clean:
	$(RM) s21_from_int_to_decimal.exe