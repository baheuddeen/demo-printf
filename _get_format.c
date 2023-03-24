#include <stdlib.h>
#include "main.h"
#include <stdio.h>

string_format _get_format(char *s)
{
	int i = 1;
	string_format format = {};

	if (*s == '+')
	{
		format.add_sign = 1;
		i++;
		s++;
	}

	if (*s == '0')
	{
		format.fill_with_zeros = 1;
		i++;
		s++;
	}

	if (*s > '0' && *s <= '9')
	{
		format.number_of_digits = *s - '0';
		s++;
		i++;
	}

	format.type = *s;
	format.length = i;
	return (format);
}
