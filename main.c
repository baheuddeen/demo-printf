#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;
    int n = 88;
    int *p = &n;

    len = _printf("Let's try %c to printf a simple sentence.\n", 'h');
    len = _printf("Let's try to printf a simple %s.\n", "string ha ha ha");
    len = _printf("this time it's \n%+08i.\n", 15195);

    return (0);
}
