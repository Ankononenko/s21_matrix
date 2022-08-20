CC=gcc 
CFLAGS=-Wall -Werror -Wextra -std=c11 -pedantic -c -g -lcheck

s21_abs/s21_abs.o: s21_abs/s21_abs.c s21_abs/s21_abs.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@
s21_acos/s21_acos.o: s21_acos/s21_acos.c s21_acos/s21_acos.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@
s21_asin/s21_asin.o: s21_asin/s21_asin.c s21_asin/s21_asin.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@
s21_atan/s21_atan.o: s21_atan/s21_atan.c s21_atan/s21_atan.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@

s21_ceil/s21_ceil.o: s21_ceil/s21_ceil.c s21_ceil/s21_ceil.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@
s21_cos/s21_cos.o: s21_cos/s21_cos.c s21_cos/s21_cos.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@
s21_exp/s21_exp.o: s21_exp/s21_exp.c s21_exp/s21_exp.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@
s21_fabs/s21_fabs.o: s21_fabs/s21_fabs.c s21_fabs/s21_fabs.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@

s21_floor/s21_floor.o: s21_floor/s21_floor.c s21_floor/s21_floor.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@
s21_fmod/s21_fmod.o: s21_fmod/s21_fmod.c s21_fmod/s21_fmod.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@
s21_log/s21_log.o: s21_log/s21_log.c s21_log/s21_log.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@
s21_pow/s21_pow.o: s21_pow/s21_pow.c s21_pow/s21_pow.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@
		
s21_sin/s21_sin.o: s21_sin/s21_sin.c s21_sin/s21_sin.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@
s21_sqrt/s21_sqrt.o: s21_sqrt/s21_sqrt.c s21_sqrt/s21_sqrt.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@
s21_tan/s21_tan.o: s21_tan/s21_tan.c s21_tan/s21_tan.h common/common.h 
		$(CC) $(CFLAGS) $< -o $@

common/common.o: common/common.c common/common.h 
		$(CC) $(CFLAGS) $< -o $@



test.out: main.o tests/abs.o tests/acos.o tests/asin.o tests/atan.o tests/ceil.o tests/cos.o tests/exp.o tests/fabs.o tests/factorial.o tests/floor.o tests/fmod.o tests/log.o tests/pow.o tests/sin.o tests/sqrt.o tests/tan.o s21_abs/s21_abs.o s21_acos/s21_acos.o s21_asin/s21_asin.o s21_atan/s21_atan.o s21_ceil/s21_ceil.o s21_cos/s21_cos.o s21_exp/s21_exp.o s21_fabs/s21_fabs.o s21_floor/s21_floor.o s21_fmod/s21_fmod.o s21_log/s21_log.o s21_pow/s21_pow.o s21_sin/s21_sin.o s21_sqrt/s21_sqrt.o s21_tan/s21_tan.o common/common.o
		$(CC) -o test.out $^ -lcheck

test: test.out
		-./test.out

main.o: main.c tests/tests.h s21_math.h
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
		rm -rf common/*.o 
		rm -rf */*.o
		rm -rf */*.exe
		rm -rf */*.out
		rm -rf tests/*.o