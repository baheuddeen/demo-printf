#ifndef PRINTF_H
#define PRINTF_H
#include <stdarg.h>

#define BUFFER_LENGTH 1024

/**
 * struct format_type - format_type
 * @type: char to specify the type Ex:
 * 'i' for int and 's' for string. etc
 * @length: the length of the formater itself Ex:
 * "%+08f" will have length of 4.
 * @number_of_digits: if it's a number Ex:
 * "%+08f" will have number_of_digits of 8.
 * @fill_with_zeros: flag to fill the empty digits with zero.
 * @add_sign: flag to add '-' or '+'.
 * @base: the base of number. Ex
 * Binary: 2, oct: 8, dec: 10 ..
 * @hex_upper: flag to print hex letters in upper case.
 * @is_pointer: flag to check if it's a pointer.
 */
typedef struct format_type
{
	char type;
	int length;
	int number_of_digits;
	int fill_with_zeros;
	int add_sign;
	int base;
	int hex_upper;
	int is_pointer;
} format_type;

int _strlen(const char *str);
char *_strcpy(char *dest, char const *src);
void _push_char(char *s, char c);
int _printf(const char *, ...);
void _add_format(char *, va_list, format_type);
format_type _get_format(char *);
void _add_string(char *, va_list);
void _add_char(char *, va_list);
void _add_int(char *, va_list, format_type);
void _add_unsigned_int(char *, va_list, format_type);
void _add_pointer(char *, va_list, format_type);
void _add_int_digits(char *, format_type, long int, int);
void _add_unsigned_int_digits(char *, format_type, unsigned long int);
char *decimal_to_string(long int x, format_type);
char *unsigned_decimal_to_string(unsigned long int x, format_type);
char get_digit_value(long int x, int base, int digit, int hex_upper);
char unsigned_get_digit_value(
	unsigned long int x, int base, int digit, int hex_upper);

#endif
