CC = gcc
C_FLAGS = -Wall -Werror -Wextra -std=c11 -pedantic -g

CAT_PATH = ./cat
GREP_PATH = ./grep

all: s21_cat s21_grep

s21_cat: $(CAT_PATH)/s21_cat.c $(CAT_PATH)/s21_cat.h
	$(CC) $(C_FLAGS) -o $(CAT_PATH)/s21_cat $(CAT_PATH)/s21_cat.c

run_s21_cat: $(CAT_PATH)/s21_cat
	cd $(CAT_PATH); ./s21_cat

s21_grep: $(GREP_PATH)/s21_grep.c $(GREP_PATH)/s21_grep.h
	$(CC) $(C_FLAGS) -o $(GREP_PATH)/s21_grep $(GREP_PATH)/s21_grep.c

run_s21_grep: $(GREP_PATH)/s21_grep
	cd $(GREP_PATH); ./s21_grep

test_cat:
	sh $(CAT_PATH)/test_cat.sh

clean:
	rm -f s21_cat s21_grep