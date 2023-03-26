#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * _add_int - add int argument to the buffer.
 * @buffer: the string that will be updated with the argument value.
 * @args: arguments.
 * @format: format.
 */
void _add_int(char *buffer, va_list args, format_type format)
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

/**
 * _add_unsigned_int - add unsigned int argument to the buffer.
 * @buffer: the string that will be updated with the argument value.
 * @args: arguments.
 * @format: format.
 */
void _add_unsigned_int(char *buffer, va_list args, format_type format)
{
	unsigned int x = va_arg(args, unsigned int);

	if (format.add_sign == 1)
	{
		format.number_of_digits--;
	}

	return (_add_unsigned_int_digits(
		buffer,
		format,
		x));
}

/**
 * _add_pointer - add pointer argument to the buffer.
 * @buffer: the string that will be updated with the argument value.
 * @args: arguments.
 * @format: format.
 */
void _add_pointer(char *buffer, va_list args, format_type format)
{
	unsigned long int x = va_arg(args, unsigned long int);

	if (format.add_sign == 1)
	{
		format.number_of_digits--;
	}

	return (_add_unsigned_int_digits(
		buffer,
		format,
		x));
}

/**
 * _add_int_digits - add int argument to the buffer digit by digit.
 * @buffer: the string that will be updated with the argument value.
 * @format: format.
 * @x: the int.
 * @is_negative: 1 if the argument is negative.
 */
void _add_int_digits(
	char *buffer, format_type format, long int x, int is_negative)
{
	char *number_string = decimal_to_string(x, format);
	int digits = _strlen(number_string);
	int i = 0;

	if (format.number_of_digits > 0 && !format.fill_with_zeros)
	{
		while (format.number_of_digits > digits)
		{
			_push_char(buffer, ' ');
			format.number_of_digits--;
		}
	}

	if (format.add_sign)
	{
		_push_char(buffer, is_negative ? '-' : '+');
	}

	if (format.fill_with_zeros)
	{
		while (format.number_of_digits > digits)
		{
			_push_char(buffer, '0');
			format.number_of_digits--;
		}
	}

	while (i < digits)
	{
		_push_char(buffer, number_string[i]);
		i++;
	}
	free(number_string);
}

/**
 * _add_unsigned_int_digits - add unsigend int argument
 * to the buffer digit by digit.
 * @buffer: the string that will be updated with the argument value.
 * @format: format.
 * @x: the number.
 */
void _add_unsigned_int_digits(
	char *buffer, format_type format, unsigned long int x)
{

	char *number_string = unsigned_decimal_to_string(x, format);
	int digits = _strlen(number_string);
	int i = 0;

	if (format.number_of_digits > 0 && !format.fill_with_zeros)
	{
		while (format.number_of_digits > digits)
		{
			_push_char(buffer, ' ');
			format.number_of_digits--;
		}
	}

	if (format.add_sign)
	{
		_push_char(buffer, '+');
	}

	if (format.fill_with_zeros)
	{
		while (format.number_of_digits > digits)
		{
			_push_char(buffer, '0');
			format.number_of_digits--;
		}
	}

	if (format.is_pointer == 1)
	{
		_push_char(buffer, '0');
		_push_char(buffer, 'x');
	}

	while (i < digits)
	{
		_push_char(buffer, number_string[i]);
		i++;
	}
	free(number_string);
}
