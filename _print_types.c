#include <stdarg.h>
#include <stdio.h>
#include "main.h"

int _print_format(va_list args, string_format format)
{
	switch (format.type)
	{
	case 'c':
		return (_print_char(args));
	case 's':
		return (_print_string(args));
	case 'i':
		return (_print_int(args, format));

	default:
		return (0);
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
	int digits = 1, power = 10;
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

	while (x / power)
	{
		digits++;
		power *= 10;
	}

	return (_print_int_digits(
		format,
		x,
		digits,
		power,
		is_negative));
}
int _print_int_digits(
	string_format format, int x, int digits, int power, int is_negative)
{
	int counter = 0;

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

	power /= 10;
	while (power)
	{
		counter += _putchar((x / power) + '0');
		x %= power;
		power /= 10;
	}
	return (counter);
}
