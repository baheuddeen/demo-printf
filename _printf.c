#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf -  prints formated string.
 * @format: string.
 *	Return:  the number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int length = strlen(format) + 1;
	int i = 0;
	char *temp_format = malloc(length);
	int printed_char_counter = 0;

	strcpy(temp_format, format);
	va_start(args, format);
	while (temp_format[i])
	{
		if (temp_format[i] == '%')
		{
			i++;
			string_format format = _get_format(temp_format + i);

			printed_char_counter += _print_format(args, format);
			i += format.length;
		}
		_putchar(temp_format[i]);
		printed_char_counter++;
		i++;
	}
	va_end(args);
	printf("\n");
	free(temp_format);
	return (printed_char_counter);
}
