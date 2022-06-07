// Copyright 2022 finchren
/*
Task - Implement the sprintf function from the stdio.h library
What to return - number of characters written to buffer 
(not counting the terminating null character), or a negative value if an encoding error (for string and character conversion specifiers) occurred
+ 1. Write the results to a character string buffer
2. Formatting support:
    a. Specifiers: 
+        c, 
+            To finish testing of %c I need to finish %d for. Want to test how works %c as %d and the other way around
+        d,
+            Itoa function
+            Put the argp in the array of chars and append to the buffer
+        i, 
+            Find out the difference between the %d and %i: 
+            %d takes integer value as signed decimal integer i.e. it takes negative values along with positive values but values should be in decimal
+            otherwise it will print garbage value.( Note: if input is in octal format like:012 then %d will ignore 0 and take input as 12).
+            %i takes integer value as integer value with decimal, hexadecimal or octal type.
+            To enter a value in hexadecimal format – value should be provided by preceding “0x” and value in octal format – value should be provided by preceding “0”.
+-        f, 
+            Find out what %f does:
+            %f converts floating-point number to the decimal notation in the style [-]ddd.ddd.
+-           Value range of %f: -340282346638528859811704183484516925440.000000 to 340282346638528859811704183484516925440.000000, precision - 6 decimal places
-            Precision specifies the exact number of digits to appear after the decimal point character. The default precision is 6.
-            if the precision is explicitly zero, no decimal-point character appears. If a decimal point appears, at least one digit appears before it.
+-        s,
+            Find out what %s does: 
+            Writes a character string
-            The argument must be a pointer to the initial element of an array of characters. Precision specifies the maximum number of bytes to be written. 
-            If Precision is not specified, writes every byte up to and not including the first null terminator. 
-            If a precision is given, no null character need be present; if the precision is not specified, or is greater than the size of the array, 
+            the array must contain a terminating NUL character.
+        u, 
+            Find out what %u does:
+            Unsigned decimal integer. 
+                What is unsigned? 
+                Unsigned int can hold only integers without a sign (minus). Only positive values and zero can be stored
+                Signed int can store postive and negative values
+                Maximum value for a variable of type unsigned int - 4 294 967 295
+                If I enter a negative value for the %u specifierm, it will go the opposite way. Ex = %u -3 == 4 294 967 293
+                (^In that case variable is repeatedly converted by adding or subtracting one or more than a maximum value until the value is in the range of the new type)
+                The floating point value gets cut off. 3.3 == 3
+                Value bigger than the max value that the unsigned int can store again goes through the range of 0 to 4 294 967 295
+                For example: 4 294 967 296 -> 0, 4 294 967 297 -> 1, 4 294 967 298 ->3, 8 589 934 590 -> 4 294 967 294
+        %
+            To print a percent sign character, use %%.
+            If a percent sign (%) is followed by a character that has no meaning as a format field, the character is simply copied to the buffer
    b. Flags:
+        Find out what the flags do.
            I need an atoi function to convert an array of chars to an int to implement the flags;
        -, 
            Left-justify the result within the field width.
            By default the result if right-justified
        +,
            Prefix the output value with a sign (+ or -) if the output value is of a signed type.
            By default sign appears only for negative signed values (-).
        (space)
            Prefix the output value with a blank if the output value is signed and positive.
            The + flag overrides the blank flag if both appear, and a positive signed value will be output with a sign.
    c. Width description: (number)
    d. Precision description: .(number)

    e. Length description: h, l
3. Memory testß
4. Test
5. Cpplint test
6. Add and push
*/

#include "s21_sprintf.h"
#include <assert.h>
#include "../s21_string.h"


// // !!! THE COMMENTED CODE IS FOR TROUBLESHOOTING. DELETE THAT LATER
// char* s21_itoa(int number, char *buffer, int base) {
//     int current = 0;
//     if (number == 0) {
//         buffer[current++] = '0';
//         buffer[current] = '\0';
//         return buffer;
//     }
//     int num_digits = 0;
//     if (number < 0) {
//         if (base == 10) {
//         ++num_digits;
//         buffer[current] = '-';
//         ++current;
//         number *= -1;
//     } else {
//         return NULL;
//         }
//     }
//     num_digits += (int)floor(log(number) / log(base)) + 1;
//     while (current < num_digits) {
//         int base_val = (int) pow(base, num_digits -1 -current);
//         int num_val = number / base_val;
//         char value = num_val + '0';
//         buffer[current] = value;
//         ++current;
//         number -= base_val * num_val;
//     }
//     buffer[current] = '\0';
//     return buffer;
// }

// char *s21_memset_uchar(char *string, unsigned char symbol, s21_size_t size) {
//     for (s21_size_t index = 0ul; index < size; ++index)
//         string[index] = symbol;
 
//     return string;

// }


// void *s21_memset(void *string, int symbol, s21_size_t size) {
//     unsigned char *string_uchar = (unsigned char*)string;
//     unsigned char symbol_uchar = (unsigned char)symbol;

//     char * result = s21_memset_uchar(string_uchar, symbol_uchar, size);
//     return result;
// }

// int main() {
//     char buffer[100];
//     // char exclamation_point = '!';
//     // int number = 2147483647;
//     // char *buffer = NULL;
//     // s21_sprintf(buffer, "Hello world%c!%c\n", exclamation_point, exclamation_point);
//     // s21_sprintf(buffer, "%d Hello world %d ! %d\n", number, number, number);
//     // double double_value = 112345.789;
//     double max = 340282346638528859811704183484516925440.000000;
//     s21_sprintf(buffer, "Hello world! %f", max);
//     puts(buffer);

//     return 0;
// }

void choose_flag(const char **format, Specifiers* specifiers) { //  TODO: test this
    while (**format == '+' || **format == '-' || **format == ' ') {
        if (**format == '+') {
            specifiers->plus = TRUE;
            ++(*format);
        }
        if (**format == '-') {
            specifiers->minus = TRUE;
            ++(*format);
        }
        if (**format == ' ') {
            specifiers->space = TRUE;
            ++(*format);
        }
    }
}

void choose_width(const char **format, Specifiers* specifiers) {
    specifiers->width = s21_atoi(format);
}

void choose_precision(const char **format, Specifiers* specifiers) {
    while (**format == '.') {
        ++(*format);
        specifiers->precision = s21_atoi(format);
    }

    if (specifiers->precision < 0)
        specifiers->precision = 0;
}



void write_argument_to_buffer(char *buffer, int *index, const Specifiers* specifiers, const Argument* argument) {
    assert(argument->length >= 0 && "Length should not be negative!");
    if (specifiers->c) {
        if (specifiers->width > 1) {
            if (specifiers->minus) {
                // left-justify
                s21_memcpy(buffer, argument->data, argument->length);
                s21_memset(buffer + argument->length, ' ', specifiers->width - argument->length);
                *index += specifiers->width;  //  rearrange
            } else {
                // right-justify
                s21_memset(buffer, ' ', specifiers->width - argument->length);
                s21_memcpy(buffer + specifiers->width - argument->length, argument->data, argument->length);
                *index += specifiers->width;  //  rearrange
            }
        } else {
            s21_memcpy(buffer, argument->data, argument->length);
            *index += argument->length;
        }
        s21_memcpy(buffer, argument->data, argument->length);
    }
    // s21_memcpy(buffer, argument->data, (s21_size_t)(argument->length));
    if (specifiers->d || specifiers->i) {
        // Insert spaces. Left-justify and right-justify
        // ToDo: Can be replaced with a funciton, which we are going to call in each specifier - the width works the same in all specifiers
        if (specifiers->width > 1) {
            if (specifiers->minus) {
                // left-justify
                s21_memcpy(buffer, argument->data, argument->length);
                s21_memset(buffer + argument->length, ' ', specifiers->width - argument->length);
                *index += specifiers->width;  //  rearrange
            } else {
                // right-justify
                s21_memset(buffer, ' ', specifiers->width - argument->length);
                s21_memcpy(buffer + specifiers->width - argument->length, argument->data, argument->length);
                *index += specifiers->width;  //  rearrange
            }
        } else {
            // If there are no width, the data is just being copied to the buffer
            s21_memcpy(buffer, argument->data, argument->length);
            *index += argument->length;
        }
        // If precision is specified, '0' are being printed before the argp. The number of zeros = specifiers->precision - argument->length
        if (specifiers->precision > 1) {
            s21_memset(buffer, '0', specifiers->precision - argument->length);
            s21_memcpy(buffer + specifiers->precision - argument->length, argument->data, argument->length);
            *index += specifiers->precision;  //  rearrange
        }
        // If there is a plus sign before the number, we are going to print out the number with a sign. 
        // If the number is negative, the sign is being printed by default
        if (specifiers->plus) {
            // If the number is positive or zero, add '+'
            if (argument->data[0] <= 9 && argument->data[0] >= 0) {
                s21_memset(buffer, '+', argument->length); // ToDo: Not sure if argument->length is right here. Need to check that when go on to testing
                s21_memcpy(buffer, argument->data, argument->length); // Here too unsure about lenght
                *index += argument->length;  //  rearrange
            }   
            // If the number is negative, add '-' - default behaviour is defined. It is implemented in the itoa function
        }
    s21_memcpy(buffer, argument->data, argument->length);
    }
}
void initialize_specifiers(Specifiers *specifiers) {
    specifiers->c = FALSE;
    specifiers->d = FALSE;
    specifiers->i = FALSE;
    specifiers->e = FALSE;
    specifiers->E = FALSE;
    specifiers->f = FALSE;
    specifiers->g = FALSE;
    specifiers->G = FALSE;
    specifiers->o = FALSE;
    specifiers->s = FALSE;
    specifiers->u = FALSE;
    specifiers->x = FALSE;
    specifiers->X = FALSE;
    specifiers->p = FALSE;
    specifiers->n = FALSE;
    specifiers->percent = FALSE;
    
    specifiers->plus = FALSE;
    specifiers->minus = FALSE;
    specifiers->space = FALSE;

    specifiers->hashtag = FALSE;
    specifiers->zero = FALSE;

    specifiers->width = 0;
    specifiers->precision = 0;

    specifiers->star = FALSE;
    
    specifiers->h = FALSE;
    specifiers->l = FALSE;
    specifiers->L = FALSE;
}
void initialize_argument(Argument* argument) {
    s21_memset(argument->data, '\0', 100ul);
    
    argument->length = 0;
    argument->is_empty = TRUE;
}
int s21_sprintf(char *buffer, const char *format, ...) {
    //assert(0);
    // assert(buffer && "BUFFER SHOULD NOT BE NULL!!!!");
    // va_list is effictively a pointer to an arguments in the varargs array
    va_list argp;
    // After calling va_start argp points at the first vararg argument
    va_start(argp, format);
    int index = 0;
    while (*format != '\0') {
        if (*format == '%') {
            Specifiers specifiers; //  TODO: here or in choose_return_type?
            initialize_specifiers(&specifiers);

            Argument argument;
            initialize_argument(&argument);
            
            ++format;  // to move from percent
            // char **old_format = format;

            choose_flag(&format, &specifiers);   //  +- and space or their combination
            choose_width(&format, &specifiers);  //  picks width - amount of spaces to be printed minus symbol width 
            choose_precision(&format, &specifiers);
            // assert(format == old_format);
            choose_return_type(buffer, &format, &index, argp, &specifiers, &argument);
            write_argument_to_buffer(buffer + index, &index, &specifiers, &argument);
            

            ++format;
        } else {
            buffer[index] = *format;
            ++index;
            ++format;
        }
    }
    // We call va_end to stop consuming the vararg arguments
    va_end(argp);
    buffer[index] = '\0';
    // Upon successful return, the function returns the number of characters printed (excluding the null byte used to end output to strings).
    return index;
}

// Going to add flags to the choose return type function for now. Now It looks like the best solution and the easiest one
// void choose_flag_type(char *buffer, const char *format, int *index) {
    
//     if ('-' == *format) {
//         left_justify_flag(buffer, format, index);
//     }
// }

void choose_return_type(char *buffer, const char **format, int *index, va_list argp, Specifiers* specifiers, Argument* argument) {
    if ('c' == **format) {
        specifiers->c = TRUE;
        c_specifier(/*buffer, index, */argp, argument);
    } else if ('d' == **format || 'i' == **format) {
        specifiers->d = TRUE;
        specifiers->i = TRUE;
        d_i_specifier(/*buffer, index, */argp, argument);
    } else if ('f' == **format) {
        specifiers->f = TRUE;
        f_specifier(buffer, index, argp, specifiers, argument);
    } else if ('s' == **format) {
        specifiers->s = TRUE;
        s_specifier(buffer, index, argp);
    } else if ('u' == **format) {
        specifiers->u = TRUE;
    } 
   else {
        percent_specifier(buffer, index, **format); // TODO:
   }
}


void c_specifier(/*char *buffer, int *index,*/ va_list argp, Argument* argument) {
    argument->data[0] = va_arg(argp, int);
    argument->is_empty = FALSE;
    argument->length = 1;

    // buffer[*index] = argument->data[0];
    // ++*index;
}

void d_i_specifier(/*char *buffer, int *index, */va_list argp, Argument* argument) {
    // int int_array_index = 0;

    int number_of_digits = -1;
    static const int base = 10;
    s21_itoa(va_arg(argp, int), argument->data, base, &number_of_digits);
    argument->length = number_of_digits;
    argument->is_empty = FALSE;

    // while (argument->data[int_array_index] != '\0') {
    //     // buffer[*index] = argument->data[int_array_index];
    //     ++int_array_index;
    //     ++*index;
    // }
}

void f_specifier(char *buffer, int *index, va_list argp, Specifiers* specifiers, Argument* argument) {
    argument->is_empty = FALSE;
    // Here I can implement the precision for the number. Just check the format with if else
    char array_for_double[49] = {'\0'};
    char *pointer_array_for_double = array_for_double;
    // Ask Misha what's wrong here - didn't build the file with the s21_memset library + Misha didn't compile the file with gcc flags. Going to use '\0' for now
    // s21_memset(array_for_double, 0, 49);
    // !!! Can be replaced with long double to work with bigger numbers. After that you should rework the data type in all nesting functions
    const double temp_arpg_variable = va_arg(argp, double);
    int dot_index = find_dot_index(temp_arpg_variable);
    // Write to the buffer the array_for_double. When you meet dot_index, insert dot char and continue to write chars until 6 decimal places of precision
    int array_for_double_index = 0;

    const int precision = specifiers->precision;
    double_to_array_of_chars(pointer_array_for_double, temp_arpg_variable, precision);
    // Append to the buffer the values before the dot. Ex: 12345.
    while (array_for_double_index != dot_index) {
        buffer[*index] = array_for_double[array_for_double_index];
        ++array_for_double_index;
        ++*index;
    }
    // Append dot to the buffer
    char dot = '.';
    buffer[*index] = dot;
    ++*index;
    // Append to the buffer the values after the dot. Maximum precision is 6. Ex: .123456



    int max_amount_of_precision = 6; // TODO!!!!

    for (int i = 0; i < max_amount_of_precision; ++i) {
        buffer[*index] = array_for_double[array_for_double_index];
        ++array_for_double_index;
        ++*index;
    }
}

int find_dot_index(double number) {
    int index = 0;
    double remainder = number;
    while (remainder >= 1) {
        remainder /= 10;
        ++index;
    }
    return index;
}

void double_to_array_of_chars(char *pointer_array_for_double, double temp_arpg_variable, int precision) {
    double integer = -1.0;
    const double fraction = modf(temp_arpg_variable, &integer);
    long long int double_without_floating_point = fraction * pow(10, precision);
    int index = 0, flip_index = 0;
    char temp_array_for_double[49] = {'\0'};
    // Write to the temp array the integer
    int integer_int = (int)integer;
    while (integer_int > 0) {
        temp_array_for_double[index] = (char)((integer_int % 10) + 48); // REPLACE 48 WITH '0'
        integer_int /= 10;
        ++index;
    }
    // Write each number to the temp array. I'll need to flip temp later
    while (double_without_floating_point > 0) {
        temp_array_for_double[index] = (char)((double_without_floating_point % 10) + 48); // REPLACE 48 WITH '0'
        double_without_floating_point /= 10;
        ++index;
    }
    // For loop to flip the temp array
    for (int i = index - 1; i >= 0; --i) {
        pointer_array_for_double[flip_index] = temp_array_for_double[i];
        ++flip_index;
    }
}

void s_specifier(char *buffer, int *index, va_list argp) {
    int temp_argp_array_index = 0;
    char *pointer_temp_argp_array = va_arg(argp, char*);
    while (pointer_temp_argp_array[temp_argp_array_index] != '\0') {
        buffer[*index] = pointer_temp_argp_array[temp_argp_array_index];
        ++*index;
        ++temp_argp_array_index;
    }
}

void u_specifier(char *buffer, int *index, va_list argp, Argument* argument) {
    argument->is_empty = FALSE;
    char array_for_unsigned_int[12];
    int unsigned_int_array_index = 0;
    int number_of_digits = -1;
    s21_itoa_unsigned(va_arg(argp, unsigned int), array_for_unsigned_int, 10, &number_of_digits);
    while (array_for_unsigned_int[unsigned_int_array_index] != '\0') {
        buffer[*index] = array_for_unsigned_int[unsigned_int_array_index];
        ++unsigned_int_array_index;
        ++*index;
    }
}

void percent_specifier(char *buffer, int *index, const char format) {
    buffer[*index] = format;
    ++*index;
}

// int check_if_there_are_any_flags(char format, int *index) {
//     int are_there_flags = FALSE;
//     if ('-' == format || '+' == format || ' ' == format ||
//     (format >= '0' && format <= '9')) {
//         are_there_flags = TRUE;
//         ++*index;
//     }
//     return are_there_flags;
// }
void add_spaces(char* buffer, int* index, int number_of_spaces) {
    for (int i = 0; i < number_of_spaces - 1; ++i) {
        buffer[*index] = ' ';
        ++*index;
    }
}
void right_justify_flag(char *buffer, const char **format, int *index, va_list argp, Specifiers* specifiers, Argument* argument) {
    if (check_if_the_end(*format)) {
        return;
    }
    
    // Here I need to substract the length of argp
   // const int length_of_argp = argument->length;
   // const int number_of_spaces = specifiers->space - length_of_argp;
    //add_spaces(buffer, index, number_of_spaces);

    choose_return_type(buffer, format, index, argp, specifiers, argument);   //
}
// Function for right_justify. It's going to check if we are near the end of the string
// If right_justify is the last, it doesn't print the spaces
int check_if_the_end(const char *format) {
    int is_end = TRUE;
    const char *temp_format = format;
    while(*temp_format != '\0') {
        if (*temp_format < '0' || *temp_format > '9') {
            is_end = FALSE;
            break;
        }
        ++temp_format;
    }
    return is_end;
}
