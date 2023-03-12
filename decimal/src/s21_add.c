#include "s21_decimal.h"
#include <stdio.h>
// #include "bit_control/bit_control.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    UNUSED_SHIT(value_1);
    UNUSED_SHIT(value_2);
    UNUSED_SHIT(result);
    // TODO: deal with exponent

    //
    //s21_decimal c = {
    //  {0b10000010111000100101101011101101, 0b11111001111010000010010110101101,
    //   0b10110000001111101111000010010100, 0b10000000000011100000000000000000}};
    //s21_decimal d = {{0b00000011010000001001011100101110, 0, 0, 0}};
   
    //s21_decimal etalon = {
    //  {0b01110001001010101101101011101101, 0b00101110001111001110000111111000,
    //   0b10110000001111101110111101101101, 0b10000000000011100000000000000000}};

    printf("value_1.bits[0] = %llu\n", (unsigned long long)value_1.bits[0]);
    printf("value_2.bits[0] = %llu\n", (unsigned long long)value_2.bits[0]);
    const long long unsigned int result0 = (unsigned long long)(value_1.bits[0]) + (unsigned long long)(value_2.bits[0]);
    printf("result0 = %llu\n", result0);
    // 000000000000000000000000000001 00000000000000000000000000000000
                                   // 11111111111111111111111111111111
    // 000000000000000000000000000000 11111111111111111111111111111111
    // 111111111111111111111111111111 11111111111111111111111111111111
    printf("sum0 = %llu\n", (long long)value_1.bits[0] + (long long)value_2.bits[0]);
    const int overflow0 = result0 >> 32;
    printf("overflow0 = %u\n", overflow0);
    result->bits[0] = (int)result0;
    printf("result->bits[0] = %u\n", result->bits[0]);

    printf("========================================\n");
    const long long int result1 = (long long)value_1.bits[1] + (long long)value_2.bits[1] + overflow0;
    const int overflow1 = result1 >> 32;
    result->bits[1] = (int)result1;
    // 1000 0001
    const long long int result2 = (long long)value_1.bits[2] + (long long)value_2.bits[2] + overflow1;
    const int overflow2 = result2 >> 32;
    result->bits[2] = (int)result2;


    printf("value_1.bits[1] = %u\n", value_1.bits[1]);
    printf("value_2.bits[1] = %u\n", value_2.bits[1]);
    printf("result1 = %llu\n", result1);
    printf("overflow1 = %u\n", overflow1);
    printf("result->bits[1] = %u\n", result->bits[1]);
    printf("========================================\n");
    
    printf("value_1.bits[2] = %u\n", value_1.bits[2]);
    printf("value_2.bits[2] = %u\n", value_2.bits[2]);
    printf("result2 = %llu\n", result2);
    printf("overflow2 = %u\n", overflow2);
    printf("result->bits[2] = %u\n", result->bits[2]);


 
    printf("==============================================\n");
    printf("==============================================\n");
    if (overflow2) {
        printf("overflow2 = %u\n", overflow2);
        printf("overflow! input is too large!!!!!\n");
        return 1;
    }

    // TODO: find out when overflow occured

    // result->bits[1] = value_1.bits[1] + value_2.bits[1];
    // result->bits[2] = value_1.bits[2] + value_2.bits[2];
// 255  1111 1111
// 001  0000 0001
// 

// 255  1111 1111
// 255  1111 1111

// 255  1111 1111
// 127  0111 1111

// 255  1111 1111
// 063  0011 1111

// 255  1111 1111
// 000  0000 0000


// 063  0011 1111
// 000  0000 0000




    return 0;

    // 123 x 10e-5
    // 345 x 10e-6

    //  123 x 10e-5
    // 3450 x 10e-5
    
}

// 0000 0000  0000 0000  0000 0000  0000 0000   0000 0000  0000 0000  0000 0000  0000 0000   0000 0000  0000 0000  0000 0000  0000 0000   0000 0000  0000 0000  0000 0000  0000 0000