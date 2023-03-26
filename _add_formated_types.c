#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * _add_format - calling the write function to handle
 * the arguments with it's format.
 * @buffer: the string that will be updated with the argument value.
 * @args: arguments.
 * @format: format type.
 */
void _add_format(char *buffer, va_list args, format_type format)
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
	}
}

/**
 * _add_string - add string argument to the buffer.
 * @buffer: the string that will be updated with the argument value.
 * @args: arguments.
 */
void _add_string(char *buffer, va_list args)
{
	char *s = va_arg(args, char *);

	while (*s)
	{
		_push_char(buffer, *s);
		s++;
	}
}

/**
 * _add_char - add char argument to the buffer.
 * @buffer: the string that will be updated with the argument value.
 * @args: arguments.
 */
void _add_char(char *buffer, va_list args)
{
	char c = va_arg(args, int);

	return (_push_char(buffer, c));
}
