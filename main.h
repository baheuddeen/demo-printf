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
} string_format;

int _putchar(char c);
int _print_format(va_list, string_format);
int _printf(const char *, ...);
string_format _get_format(char *);
int _print_string(va_list);
int _print_char(va_list);
int _print_int (va_list, string_format);

#endif
