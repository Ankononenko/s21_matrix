CC = gcc
C_FLAGS = -Wall -Werror -Wextra -std=c11 -pedantic -g
RM = rm -f

default: all

all: clean s21_from_decimal_to_float run

s21_from_decimal_to_float: s21_from_decimal_to_float.c s21_from_decimal_to_float.h ../../bit_control/bit_control.c ../../bit_control/bit_control.h ../../helpers/helpers.h ../../helpers/set_sign.c ../../helpers/set_scale.c ../../s21_decimal.h test.c test.h
	$(CC) $(C_FLAGS) -o s21_from_decimal_to_float.exe s21_from_decimal_to_float.c s21_from_decimal_to_float.h ../../bit_control/bit_control.c ../../helpers/helpers.h ../../helpers/set_sign.c ../../helpers/set_scale.c ../../s21_decimal.h test.c test.h

run:
	./s21_from_decimal_to_float.exe

clean:
	$(RM) s21_from_decimal_to_float.exe