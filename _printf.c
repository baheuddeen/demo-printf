#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf -  prints formated string.
 * @format: string.
 *	Return:  the number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	char *buffer = NULL;

	buffer = calloc(BUFFER_LENGTH, 1);
	if (!buffer)
	{
		return (-1);
	}

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			format_type _format = _get_format(format + (++i));

			_add_format(buffer, args, _format);
			i += _format.length;
		}
		_push_char(buffer, format[i]);
		i++;
	}

	for (i = 0; buffer[i]; i++)
	{
		write(1, buffer + i, 1);
	}
	va_end(args);
	free(buffer);
	return (i);
}
