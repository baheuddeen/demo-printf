#include "main.h"
#include <stdlib.h>

/**
 * _push_char - push char after the last char in a buffer.
 * @buffer: buffer to push at.
 * @c: char to push.
 */

void _push_char(char *buffer, char c)
{
	int i = 0;

	for (i = 0; buffer[i]; i++)
		;
	if (i >= BUFFER_LENGTH)
	{
		exit(90);
	}
	buffer[i] = c;
}
