CC=gcc 
CFLAGS=-Wall -Werror -Wextra -std=c11 -pedantic -c -g -lcheck

VFLAGS=-Wall -Werror -Wextra -std=c11 -pedantic -c -g -lcheck   # elviaatt: нужен ли здесь -lcheck ?

CFLAGS_GCOV=-fprofile-arcs -ftest-coverage

CHECK_FLAGS=$(shell pkg-config --cflags --libs check)
LIBS=$(CHECK_FLAGS)


REPORT_DIRECTORY=report

all: test 
#gcov_report


# all: s21_math.a test gcov_report
# s21_decimal.h

gcov_report: test
		mkdir -p $(REPORT_DIRECTORY)
		gcovr . --html --html-details -o $(REPORT_DIRECTORY)/coverage_report.html


s21_decimal.a: s21_add.oa s21_sub.oa s21_mul.oa s21_div.oa s21_mod.oa s21_is_less.oa s21_is_less_or_equal.oa s21_is_greater.oa s21_is_greater_or_equal.oa s21_is_equal.oa s21_is_not_equal.oa s21_from_int_to_decimal.oa s21_from_float_to_decimal.oa s21_from_decimal_to_int.oa s21_from_decimal_to_float.oa s21_floor.oa s21_round.oa s21_truncate.oa s21_negate.oa
		ar rcs $@ $^

s21_add.oa: s21_add.c s21_decimal.h
		$(CC) $(VFLAGS) $< -o $@
s21_sub.oa: s21_sub.c s21_decimal.h
		$(CC) $(VFLAGS) $< -o $@
s21_mul.oa: s21_mul.c s21_decimal.h  
		$(CC) $(VFLAGS) $< -o $@
s21_div.oa: s21_div.c s21_decimal.h
		$(CC) $(VFLAGS) $< -o $@
s21_mod.oa: s21_mod.c s21_decimal.h
		$(CC) $(VFLAGS) $< -o $@

s21_is_less.oa: s21_is_less.c s21_decimal.h
		$(CC) $(VFLAGS) $< -o $@
s21_is_less_or_equal.oa: s21_is_less_or_equal.c s21_decimal.h
		$(CC) $(VFLAGS) $< -o $@
s21_is_greater.oa: s21_is_greater.c s21_decimal.h
		$(CC) $(VFLAGS) $< -o $@
s21_is_greater_or_equal.oa: s21_is_greater_or_equal.c s21_decimal.h
		$(CC) $(VFLAGS) $< -o $@
s21_is_equal.oa: s21_is_equal.c s21_decimal.h
		$(CC) $(VFLAGS) $< -o $@
s21_is_not_equal.oa: s21_is_not_equal.c s21_decimal.h
		$(CC) $(VFLAGS) $< -o $@

s21_from_int_to_decimal.oa: s21_from_int_to_decimal.c s21_from_int_to_decimal.h bit_control/bit_control.c helpers/helpers.h helpers/init_decimal.c helpers/set_sign.c helpers/get_scale.c
		$(CC) $(VFLAGS) $< -o $@
s21_from_float_to_decimal.oa: s21_from_float_to_decimal.c s21_decimal.h
		$(CC) $(VFLAGS) $< -o $@
s21_from_decimal_to_int.oa: s21_from_decimal_to_int.c s21_from_decimal_to_int.h bit_control/bit_control.c helpers/helpers.h helpers/init_decimal.c helpers/set_sign.c helpers/get_scale.c s21_from_int_to_decimal.h s21_from_int_to_decimal.c
		$(CC) $(VFLAGS) $< -o $@
s21_from_decimal_to_float.oa: s21_from_decimal_to_float.c s21_decimal.h
		$(CC) $(VFLAGS) $< -o $@
		
s21_floor.oa: s21_floor.c s21_decimal.h 
		$(CC) $(VFLAGS) $< -o $@
s21_round.oa: s21_round.c s21_decimal.h
		$(CC) $(VFLAGS) $< -o $@
s21_truncate.oa: s21_truncate.c s21_decimal.h
		$(CC) $(VFLAGS) $< -o $@
s21_negate.oa: s21_negate.c s21_decimal.h
		$(CC) $(VFLAGS) $< -o $@













test.out: tests/s21_test1.o s21_add.o s21_sub.o s21_mul.o s21_div.o s21_mod.o s21_is_less.o s21_is_less_or_equal.o s21_is_greater.o s21_is_greater_or_equal.o s21_is_equal.o s21_is_not_equal.o s21_from_int_to_decimal.o s21_from_float_to_decimal.o s21_from_decimal_to_int.o s21_from_decimal_to_float.o s21_floor.o s21_round.o s21_truncate.o s21_negate.o helpers/init_decimal.o helpers/set_scale.o helpers/set_sign.o helpers/get_scale.o bit_control/bit_control.o
		$(CC) -o $@ $^ $(LIBS)


tests/s21_test1.o: tests/s21_test1.c s21_decimal.h
		$(CC) -c -o $@ $< $(LIBS)


test: test.out
		-./test.out


s21_add.o: s21_add.c s21_decimal.h
		$(CC) $(CFLAGS) $< -o $@ 
s21_sub.o: s21_sub.c s21_decimal.h
		$(CC) $(CFLAGS) $< -o $@ 
s21_mul.o: s21_mul.c s21_decimal.h  
		$(CC) $(CFLAGS) $< -o $@ 
s21_div.o: s21_div.c s21_decimal.h
		$(CC) $(CFLAGS) $< -o $@ 
s21_mod.o: s21_mod.c s21_decimal.h
		$(CC) $(CFLAGS) $< -o $@ 

s21_is_less.o: s21_is_less.c s21_decimal.h
		$(CC) $(CFLAGS) $< -o $@ 
s21_is_less_or_equal.o: s21_is_less_or_equal.c s21_decimal.h
		$(CC) $(CFLAGS) $< -o $@ 
s21_is_greater.o: s21_is_greater.c s21_decimal.h
		$(CC) $(CFLAGS) $< -o $@ 
s21_is_greater_or_equal.o: s21_is_greater_or_equal.c s21_decimal.h
		$(CC) $(CFLAGS) $< -o $@ 
s21_is_equal.o: s21_is_equal.c s21_decimal.h
		$(CC) $(CFLAGS) $< -o $@ 
s21_is_not_equal.o: s21_is_not_equal.c s21_decimal.h
		$(CC) $(CFLAGS) $< -o $@ 

s21_from_int_to_decimal.o: s21_from_int_to_decimal.c s21_decimal.h
		$(CC) $(CFLAGS) $< -o $@ 
s21_from_float_to_decimal.o: s21_from_float_to_decimal.c s21_decimal.h
		$(CC) $(CFLAGS) $< -o $@ 
s21_from_decimal_to_int.o: s21_from_decimal_to_int.c s21_decimal.h
		$(CC) $(CFLAGS) $< -o $@ 
s21_from_decimal_to_float.o: s21_from_decimal_to_float.c s21_decimal.h
		$(CC) $(CFLAGS) $< -o $@ 
		
s21_floor.o: s21_floor.c s21_decimal.h 
		$(CC) $(CFLAGS) $< -o $@ 
s21_round.o: s21_round.c s21_decimal.h
		$(CC) $(CFLAGS) $< -o $@ 
s21_truncate.o: s21_truncate.c s21_decimal.h
		$(CC) $(CFLAGS) $< -o $@ 
s21_negate.o: s21_negate.c s21_decimal.h
		$(CC) $(CFLAGS) $< -o $@ 



helpers/init_decimal.o: helpers/init_decimal.c helpers/helpers.h
	$(CC) $(CFLAGS) $< -o $@ 

helpers/set_scale.o: helpers/set_scale.c helpers/helpers.h
	$(CC) $(CFLAGS) $< -o $@ 

helpers/set_sign.o: helpers/set_sign.c helpers/helpers.h
	$(CC) $(CFLAGS) $< -o $@ 

helpers/get_scale.o: helpers/get_scale.c helpers/helpers.h
	$(CC) $(CFLAGS) $< -o $@ 


bit_control/bit_control.o: bit_control/bit_control.c bit_control/bit_control.h
	$(CC) $(CFLAGS) $< -o $@ 



clean:
		rm -rf */*.o */*.oa */*.gcda */*.gcno */*.html
		rm -rf */*.exe
		rm -rf */*.out
		rm -rf *.o
		rm -rf *.out
		rm -rf s21_decimal.a
		rm -rf *.html
		rm -rf report/*
		rm -rf *.o *.oa *.gcda *.gcno *.html

valgrind: test.out
		mkdir -p $(REPORT_DIRECTORY)
		-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test.out > $(REPORT_DIRECTORY)/valgrind_report.txt

leaks:
		leaks -atExit -- test


style:
		-python3 ../materials/linters/cpplint.py --extensions=c *.h
		-python3 ../materials/linters/cpplint.py --extensions=c *.c
		-python3 ../materials/linters/cpplint.py --extensions=c */*.c
		-python3 ../materials/linters/cpplint.py --extensions=c */*.h


cppcheck:
		-cppcheck --enable=all --suppress=missingIncludeSystem --force ./src *.c
		-cppcheck --enable=all --suppress=missingIncludeSystem --force ./src *.h
		-cppcheck --enable=all --suppress=missingIncludeSystem --force ./src/*/ */*.c
		-cppcheck --enable=all --suppress=missingIncludeSystem --force ./src/*/ */*.h