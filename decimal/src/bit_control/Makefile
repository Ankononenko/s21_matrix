CC = gcc
C_FLAGS = -Wall -Werror -Wextra -std=c11 -pedantic -g
RM = rm -f

default: all

all: clean test_bit_control run

test_bit_control: bit_control.c bit_control.h test.c
	$(CC) $(C_FLAGS) -o test_bit_control.exe bit_control.c test.c

run:
	./test_bit_control.exe

clean:
	$(RM) test_bit_control.exe