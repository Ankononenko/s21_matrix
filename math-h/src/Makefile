CC=gcc 
CFLAGS=-Wall -Werror -Wextra -std=c11 -pedantic -c -g -lcheck -fsanitize=address

VFLAGS=-Wall -Werror -Wextra -std=c11 -pedantic -c -g -lcheck

CFLAGS_GCOV=-fprofile-arcs -ftest-coverage

LIBS=-lcheck -lgcov -fsanitize=address

REPORT_DIRECTORY=report

all: s21_math.a test gcov_report

gcov_report: test
		mkdir -p $(REPORT_DIRECTORY)
		gcovr . --html --html-details -o $(REPORT_DIRECTORY)/coverage_report.html

s21_math.a: s21_abs/s21_abs.oa s21_acos/s21_acos.oa s21_asin/s21_asin.oa s21_atan/s21_atan.oa s21_ceil/s21_ceil.oa s21_cos/s21_cos.oa s21_exp/s21_exp.oa s21_fabs/s21_fabs.oa s21_floor/s21_floor.oa s21_fmod/s21_fmod.oa s21_log/s21_log.oa s21_pow/s21_pow.oa s21_sin/s21_sin.oa s21_sqrt/s21_sqrt.oa s21_tan/s21_tan.oa common/common.oa
		ar rcs $@ $^


s21_abs/s21_abs.o: s21_abs/s21_abs.c s21_abs/s21_abs.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@ $(CFLAGS_GCOV)
s21_acos/s21_acos.o: s21_acos/s21_acos.c s21_acos/s21_acos.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@ $(CFLAGS_GCOV)
s21_asin/s21_asin.o: s21_asin/s21_asin.c s21_asin/s21_asin.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@ $(CFLAGS_GCOV)
s21_atan/s21_atan.o: s21_atan/s21_atan.c s21_atan/s21_atan.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@ $(CFLAGS_GCOV)

s21_ceil/s21_ceil.o: s21_ceil/s21_ceil.c s21_ceil/s21_ceil.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@ $(CFLAGS_GCOV)
s21_cos/s21_cos.o: s21_cos/s21_cos.c s21_cos/s21_cos.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@ $(CFLAGS_GCOV)
s21_exp/s21_exp.o: s21_exp/s21_exp.c s21_exp/s21_exp.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@ $(CFLAGS_GCOV)
s21_fabs/s21_fabs.o: s21_fabs/s21_fabs.c s21_fabs/s21_fabs.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@ $(CFLAGS_GCOV)

s21_floor/s21_floor.o: s21_floor/s21_floor.c s21_floor/s21_floor.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@ $(CFLAGS_GCOV)
s21_fmod/s21_fmod.o: s21_fmod/s21_fmod.c s21_fmod/s21_fmod.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@ $(CFLAGS_GCOV)
s21_log/s21_log.o: s21_log/s21_log.c s21_log/s21_log.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@ $(CFLAGS_GCOV)
s21_pow/s21_pow.o: s21_pow/s21_pow.c s21_pow/s21_pow.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@ $(CFLAGS_GCOV)
		
s21_sin/s21_sin.o: s21_sin/s21_sin.c s21_sin/s21_sin.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@ $(CFLAGS_GCOV)
s21_sqrt/s21_sqrt.o: s21_sqrt/s21_sqrt.c s21_sqrt/s21_sqrt.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@ $(CFLAGS_GCOV)
s21_tan/s21_tan.o: s21_tan/s21_tan.c s21_tan/s21_tan.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@ $(CFLAGS_GCOV)

common/common.o: common/common.c common/common.h 
		$(CC) $(CFLAGS) $< -o $@ $(CFLAGS_GCOV)





s21_abs/s21_abs.oa: s21_abs/s21_abs.c s21_abs/s21_abs.h common/common.h 
		$(CC) $(VFLAGS) $< -o $@
s21_acos/s21_acos.oa: s21_acos/s21_acos.c s21_acos/s21_acos.h common/common.h 
		$(CC) $(VFLAGS) $< -o $@
s21_asin/s21_asin.oa: s21_asin/s21_asin.c s21_asin/s21_asin.h common/common.h 
		$(CC) $(VFLAGS) $< -o $@
s21_atan/s21_atan.oa: s21_atan/s21_atan.c s21_atan/s21_atan.h common/common.h 
		$(CC) $(VFLAGS) $< -o $@

s21_ceil/s21_ceil.oa: s21_ceil/s21_ceil.c s21_ceil/s21_ceil.h common/common.h 
		$(CC) $(VFLAGS) $< -o $@
s21_cos/s21_cos.oa: s21_cos/s21_cos.c s21_cos/s21_cos.h common/common.h 
		$(CC) $(VFLAGS) $< -o $@
s21_exp/s21_exp.oa: s21_exp/s21_exp.c s21_exp/s21_exp.h common/common.h 
		$(CC) $(VFLAGS) $< -o $@
s21_fabs/s21_fabs.oa: s21_fabs/s21_fabs.c s21_fabs/s21_fabs.h common/common.h 
		$(CC) $(VFLAGS) $< -o $@

s21_floor/s21_floor.oa: s21_floor/s21_floor.c s21_floor/s21_floor.h common/common.h 
		$(CC) $(VFLAGS) $< -o $@
s21_fmod/s21_fmod.oa: s21_fmod/s21_fmod.c s21_fmod/s21_fmod.h common/common.h 
		$(CC) $(VFLAGS) $< -o $@
s21_log/s21_log.oa: s21_log/s21_log.c s21_log/s21_log.h common/common.h 
		$(CC) $(VFLAGS) $< -o $@
s21_pow/s21_pow.oa: s21_pow/s21_pow.c s21_pow/s21_pow.h common/common.h 
		$(CC) $(VFLAGS) $< -o $@
		
s21_sin/s21_sin.oa: s21_sin/s21_sin.c s21_sin/s21_sin.h common/common.h 
		$(CC) $(VFLAGS) $< -o $@
s21_sqrt/s21_sqrt.oa: s21_sqrt/s21_sqrt.c s21_sqrt/s21_sqrt.h common/common.h 
		$(CC) $(VFLAGS) $< -o $@
s21_tan/s21_tan.oa: s21_tan/s21_tan.c s21_tan/s21_tan.h common/common.h 
		$(CC) $(VFLAGS) $< -o $@

common/common.oa: common/common.c common/common.h 
		$(CC) $(VFLAGS) $< -o $@




test.out: test_main.o tests/abs.o tests/acos.o tests/asin.o tests/atan.o tests/ceil.o tests/cos.o tests/exp.o tests/fabs.o tests/factorial.o tests/floor.o tests/fmod.o tests/log.o tests/pow.o tests/sin.o tests/sqrt.o tests/tan.o s21_abs/s21_abs.o s21_acos/s21_acos.o s21_asin/s21_asin.o s21_atan/s21_atan.o s21_ceil/s21_ceil.o s21_cos/s21_cos.o s21_exp/s21_exp.o s21_fabs/s21_fabs.o s21_floor/s21_floor.o s21_fmod/s21_fmod.o s21_log/s21_log.o s21_pow/s21_pow.o s21_sin/s21_sin.o s21_sqrt/s21_sqrt.o s21_tan/s21_tan.o common/common.o
		$(CC) -o $@ $^ $(LIBS)

test: test.out
		-./test.out

test_main.o: test_main.c tests/tests.h s21_math.h
		$(CC) $(CFLAGS) $< -o $@


tests/abs.o: tests/abs.c tests/tests.h
		$(CC) $(CFLAGS) $< -o $@
tests/acos.o: tests/acos.c tests/tests.h
		$(CC) $(CFLAGS) $< -o $@
tests/asin.o: tests/asin.c tests/tests.h
		$(CC) $(CFLAGS) $< -o $@
tests/atan.o: tests/atan.c tests/tests.h
		$(CC) $(CFLAGS) $< -o $@

tests/ceil.o: tests/ceil.c tests/tests.h
		$(CC) $(CFLAGS) $< -o $@
tests/cos.o: tests/cos.c tests/tests.h
		$(CC) $(CFLAGS) $< -o $@
tests/exp.o: tests/exp.c tests/tests.h
		$(CC) $(CFLAGS) $< -o $@
tests/fabs.o: tests/fabs.c tests/tests.h
		$(CC) $(CFLAGS) $< -o $@

tests/factorial.o: tests/factorial.c tests/tests.h
		$(CC) $(CFLAGS) $< -o $@
tests/floor.o: tests/floor.c tests/tests.h
		$(CC) $(CFLAGS) $< -o $@
tests/fmod.o: tests/fmod.c tests/tests.h
		$(CC) $(CFLAGS) $< -o $@
tests/log.o: tests/log.c tests/tests.h
		$(CC) $(CFLAGS) $< -o $@

tests/pow.o: tests/pow.c tests/tests.h
		$(CC) $(CFLAGS) $< -o $@
tests/sin.o: tests/sin.c tests/tests.h
		$(CC) $(CFLAGS) $< -o $@
tests/sqrt.o: tests/sqrt.c tests/tests.h
		$(CC) $(CFLAGS) $< -o $@
tests/tan.o: tests/tan.c tests/tests.h
		$(CC) $(CFLAGS) $< -o $@


tests/tests.o: abs.c


clean:
		rm -rf */*.o */*.oa */*.gcda */*.gcno */*.html
		rm -rf */*.exe
		rm -rf */*.out
		rm -rf *.o
		rm -rf *.out
		rm -rf s21_math.a
		rm -rf *.html
		rm -rf report/*

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
