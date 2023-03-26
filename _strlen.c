#include "main.h"

/**
 * _strlen - get the string len.
 * @s: string.
 */
int _strlen(const char *s)
{
	int i = 0;

	for (i = 0; s[i]; i++)
		;
	return (i);
}
