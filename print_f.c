#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void print_int(int);
char *handle_arg(char *s, int x);
int print_f(char *s, ...);


int main(void)
{
    print_f("hello %d", 10);
    print_f("hello %d, from %d", 10, 25);
    print_f("hello %d, from %d, the %d", 10, 25, 36);
    print_f("hello %d, from %d the %d other side %d", 1, 125, 256, 985);

}

int print_f(char *s, ...)
{
    va_list args;

    va_start(args, s);
    while (*s)
    {
        if (*s == '%')
        {
            s = handle_arg(s, va_arg(args, int));
        }
        else
        {
            putchar(*s);
        }
        s++;
    }
    putchar('\n');
    return (0);
}

char *handle_arg(char *s, int x)
{
    s++;
    if (*s == 'd')
    {
        print_int(x);
    }
    return (s);
}

void print_int(int x)
{
    int digits = 1, power = 10;

    while (x / power)
    {
        digits++;
        power *= 10;
    }

    power /= 10;
    while (power)
    {
        putchar((x / power) + '0');
        x %= power;
        power /= 10;
    }
}

