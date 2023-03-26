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
	int length = _strlen(format) + 1;
	int i = 0;
	char *temp_format = NULL, *buffer = NULL;

	temp_format = malloc(length + 1);
	if (!temp_format)
		return (-1);
	buffer = calloc(BUFFER_LENGTH, 1);
	if (!buffer)
	{
		free(temp_format);
		return (-1);
	}

	_strcpy(temp_format, format);
	va_start(args, format);
	while (temp_format[i])
	{
		if (temp_format[i] == '%')
		{
			format_type format = _get_format(temp_format + (++i));

			_add_format(buffer, args, format);
			i += format.length;
		}
		_push_char(buffer, temp_format[i]);
		i++;
	}

	for (i = 0; buffer[i]; i++)
	{
		write(1, buffer + i, 1);
	}
	va_end(args);
	free(temp_format);
	free(buffer);
	return (i);
}
