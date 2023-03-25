#ifndef PRINTF_H
#define PRINTF_H
#include <stdarg.h>

typedef struct string_format
{
    char type;
    int number_of_digits;
    int fill_with_zeros;
    int length;
    int add_sign;
    int base;
    int hex_upper;
    int is_pointer;
} string_format;

int _putchar(char c);
int _print_format(va_list, string_format);
int _printf(const char *, ...);
string_format _get_format(char *);
int _print_string(va_list);
int _print_char(va_list);
int _print_int (va_list, string_format);
int _print_unsigned_int(va_list, string_format);	
int _print_pointer (va_list, string_format);
int _print_int_digits(string_format,long int, int);
int _print_unsigned_int_digits(string_format, unsigned long int);
char *decimal_to_string(long int x, string_format);
char *unsigned_decimal_to_string(unsigned long int x,string_format);
char get_digit_value(long int x, int base, int digit, int hex_upper);
char insigned_get_digit_value(long int x, int base, int digit, int hex_upper);

#endif
