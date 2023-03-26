#ifndef PRINTF_H
#define PRINTF_H
#include <stdarg.h>

typedef struct format_type
{
    char type;
    int number_of_digits;
    int fill_with_zeros;
    int length;
    int add_sign;
    int base;
    int hex_upper;
    int is_pointer;
} format_type;

int _push_char(char *s, char c);
int _printf(const char *, ...);
int _add_format(char *, va_list, format_type);
format_type _get_format(char *);
int _add_string(char *, va_list);
int _add_char(char *, va_list);
int _add_int (char *, va_list, format_type);
int _add_unsigned_int(char *, va_list, format_type);	
int _add_pointer (char *, va_list, format_type);
int _add_int_digits(char *, format_type,long int, int);
int _print_unsigned_int_digits(char *, format_type, unsigned long int);
char *decimal_to_string(long int x, format_type);
char *unsigned_decimal_to_string(unsigned long int x,format_type);
char get_digit_value(long int x, int base, int digit, int hex_upper);
char unsigned_get_digit_value(unsigned long int x, int base, int digit, int hex_upper);

#endif
