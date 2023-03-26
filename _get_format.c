#include <stdlib.h>
#include "main.h"
#include <stdio.h>

format_type _get_format(char *s)
{
	int i = 1;
	format_type format = {
		'\0',0,0,0,0,0,0,0
	};

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
