CC = gcc
C_FLAGS = -Wall -Werror -Wextra -std=c11 -pedantic
DEBUG_FLAG = -g -fsanitize=address

CAT_PATH = ./cat/

all: s21_cat

s21_cat: $(CAT_PATH)s21_cat.c $(CAT_PATH)s21_cat.h
	$(CC) $(C_FLAGS) -o s21_cat $(CAT_PATH)s21_cat.c

test_cat:
	sh $(CAT_PATH)test_cat.sh

clean:
	rm -rf s21_cat