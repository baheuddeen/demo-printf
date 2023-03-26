#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <string.h>
#include <stdlib.h>

int _add_format(char *buffer, va_list args, format_type format)
{

	switch (format.type)
	{
	case 'c':
		return (_add_char(buffer, args));
	case 's':
		return (_add_string(buffer, args));
	case 'i':
	case 'd':
		format.base = 10;
		return (_add_int(buffer, args, format));
	case 'u':
		format.base = 10;
		return (_add_unsigned_int(buffer, args, format));
	case 'o':
		format.base = 8;
		return (_add_unsigned_int(buffer, args, format));
	case 'x':
		format.base = 16;
		return (_add_unsigned_int(buffer, args, format));
	case 'p':
		format.base = 16;
		format.is_pointer = 1;
		return (_add_pointer(buffer, args, format));
	case 'X':
		format.base = 16;
		format.hex_upper = 1;
		return (_add_unsigned_int(buffer, args, format));
	case '%':
		return (_push_char(buffer, '%'));
	default:
		_push_char(buffer, '%');
		_push_char(buffer, format.type);
		return (2);
	}
}

int _add_string(char *buffer, va_list args)
{
	int counter;
	char *s = va_arg(args, char *);

	while (*s)
	{
		counter += _push_char(buffer, *s);
		s++;
	}
	return (counter);
}

int _add_char(char *buffer, va_list args)
{
	char c = va_arg(args, int);

	return (_push_char(buffer, c));
}

int _add_int(char *buffer, va_list args, format_type format)
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

	return (_add_int_digits(
		buffer,
		format,
		x,
		is_negative));
}

int _add_unsigned_int(char *buffer, va_list args, format_type format)
{
	unsigned int x = va_arg(args, unsigned int);

	if (format.add_sign == 1)
	{
		format.number_of_digits--;
	}

	return (_print_unsigned_int_digits(
		buffer,
		format,
		x));
}

int _add_pointer(char *buffer, va_list args, format_type format)
{
	unsigned long int x = va_arg(args, unsigned long int);

	if (format.add_sign == 1)
	{
		format.number_of_digits--;
	}

	return (_print_unsigned_int_digits(
		buffer,
		format,
		x));
}

int _add_int_digits(char *buffer, format_type format, long int x, int is_negative)
{
	int counter = 0;
	char *number_string = decimal_to_string(x, format);
	int digits = strlen(number_string);
	int i = 0;

	if (format.number_of_digits > 0 && !format.fill_with_zeros)
	{
		while (format.number_of_digits > digits)
		{
			counter += _push_char(buffer, ' ');
			format.number_of_digits--;
		}
	}

	if (format.add_sign)
	{
		counter += _push_char(buffer, is_negative ? '-' : '+');
	}

	if (format.fill_with_zeros)
	{
		while (format.number_of_digits > digits)
		{
			counter += _push_char(buffer, '0');
			format.number_of_digits--;
		}
	}

	while (i < digits)
	{
		counter += _push_char(buffer, number_string[i]);
		i++;
	}
	free(number_string);
	return (counter);
}

int _print_unsigned_int_digits(
	char *buffer, format_type format, unsigned long int x)
{
	int counter = 0;
	char *number_string = unsigned_decimal_to_string(x, format);
	int digits = strlen(number_string);
	int i = 0;

	if (format.number_of_digits > 0 && !format.fill_with_zeros)
	{
		while (format.number_of_digits > digits)
		{
			counter += _push_char(buffer, ' ');
			format.number_of_digits--;
		}
	}

	if (format.add_sign)
	{
		counter += _push_char(buffer, '+');
	}

	if (format.fill_with_zeros)
	{
		while (format.number_of_digits > digits)
		{
			counter += _push_char(buffer, '0');
			format.number_of_digits--;
		}
	}

	if (format.is_pointer == 1)
	{
		counter += _push_char(buffer, '0');
		counter += _push_char(buffer, 'x');
	}

	while (i < digits)
	{
		counter += _push_char(buffer, number_string[i]);
		i++;
	}
	free(number_string);
	return (counter);
}
