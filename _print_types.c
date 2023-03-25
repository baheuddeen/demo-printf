#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <string.h>

int _print_format(va_list args, string_format format)
{

	switch (format.type)
	{
	case 'c':
		return (_print_char(args));
	case 's':
		return (_print_string(args));
	case 'i':
	case 'd':
		format.base = 10;
		return (_print_int(args, format));	
	case 'u':
		format.base = 10;
		return (_print_unsigned_int(args, format));
	case 'o':
		format.base = 8;
		return (_print_unsigned_int(args, format));	
	case 'x':
		format.base = 16;
		return (_print_unsigned_int(args, format));	
	case 'p':
		format.base = 16;
		format.is_pointer = 1;
		return (_print_pointer(args, format));	
	case 'X':
		format.base = 16;
		format.hex_upper = 1;
		return (_print_unsigned_int(args, format));	
	case '%':
		return (_putchar('%'));
	default:
		_putchar('%');
		_putchar(format.type);
		return (2);
	}
}

int _print_string(va_list args)
{
	int counter;
	char *s = va_arg(args, char *);

	while (*s)
	{
		counter += _putchar(*s);
		s++;
	}
	return (counter);
}

int _print_char(va_list args)
{
	char c = va_arg(args, int);

	return (_putchar(c));
}


int _print_int(va_list args, string_format format)
{
	int x = va_arg(args, int);
	int is_negative = 0;

	if (x < 0)
	{
		is_negative = 1;
		format.add_sign = 1;
	}

	if (is_negative || format.add_sign == 1)
	{
		format.number_of_digits--;
	}

	x = is_negative ? -x : x;

	return (_print_int_digits(
		format,
		x,
		is_negative));
}


int _print_unsigned_int(va_list args, string_format format)
{
	unsigned int x = va_arg(args,unsigned int);
	int is_negative = 0;

	if (format.add_sign == 1)
	{
		format.number_of_digits--;
	}

	return (_print_unsigned_int_digits(
		format,
		x));
}


int _print_pointer(va_list args, string_format format)
{
	unsigned long int x = va_arg(args,unsigned long int);
	int is_negative = 0;

	if (format.add_sign == 1)
	{
		format.number_of_digits--;
	}

	return (_print_unsigned_int_digits(
		format,
		x));
}



int _print_int_digits(string_format format,long int x, int is_negative)
{
	int counter = 0;
	char *number_string = decimal_to_string(x, format);
	int digits = strlen(number_string);
	int i = 0;

	if (format.number_of_digits > 0 && !format.fill_with_zeros)
	{
		while (format.number_of_digits > digits)
		{
			counter += _putchar(' ');
			format.number_of_digits--;
		}
	}

	if (format.add_sign)
	{
		counter += _putchar(is_negative ? '-' : '+');
	}

	if (format.fill_with_zeros)
	{
		while (format.number_of_digits > digits)
		{
			counter += _putchar('0');
			format.number_of_digits--;
		}
	}

	while (i < digits)
	{
		counter += _putchar(number_string[i]);
		i++;
	}
	return (counter);
}

int _print_unsigned_int_digits(
	string_format format,unsigned long int x)
{
	int counter = 0;
	char *number_string = unsigned_decimal_to_string(x, format);
	int digits = strlen(number_string);
	int i = 0;

	if (format.number_of_digits > 0 && !format.fill_with_zeros)
	{
		while (format.number_of_digits > digits)
		{
			counter += _putchar(' ');
			format.number_of_digits--;
		}
	}

	if (format.add_sign)
	{
		counter += _putchar('+');
	}

	if (format.fill_with_zeros)
	{
		while (format.number_of_digits > digits)
		{
			counter += _putchar('0');
			format.number_of_digits--;
		}
	}

	if (format.is_pointer == 1)
	{
		counter += _putchar('0');
		counter += _putchar('x');
	}
	

	while (i < digits)
	{
		counter += _putchar(number_string[i]);
		i++;
	}
	return (counter);
}
