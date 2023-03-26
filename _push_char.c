#include "main.h"

/**
 * _putchar - print char
 *
 * @c: char to print.
 *
 * Return: 0 (success)
 */

int _push_char(char *s, char c)
{
    while (*s)
    {
        s++;
    }
    *s = c;
	return (1);
}
