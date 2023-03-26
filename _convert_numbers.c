#include <stdlib.h>
#include "main.h"
#include <stdio.h>

char *decimal_to_string(long int x, format_type format)
{
    char *bin;
    long int temp_x = x;
    int i = 0;

    int bin_digits = 1;
    while (temp_x / format.base)
    {
        temp_x /= format.base;
        bin_digits++;
    }
    bin = malloc(bin_digits + 1);
    bin[bin_digits] = '\0';

    for (i = 0 ; i < bin_digits ; i++)
    {
        bin[bin_digits - i - 1] = get_digit_value(x, format.base, i, format.hex_upper);
    }
    return bin;
}

char get_digit_value(long int x, int base, int digit, int hex_upper)
{
    int value = 0;
    while (digit)
    {
        x /= base;
        digit--;
    }
    value = x % base;
    if (value >= 0 && value <= 9)
    {
        return (value + '0');    
    }
    else
    {
        if (hex_upper)
        {
            return (value - 10 + 'A');
        }
        
        return (value - 10 + 'a');
    }    
}


char *unsigned_decimal_to_string(unsigned long int x, format_type format)
{
    char *bin;
    long int temp_x = x;
    int i = 0;

    int bin_digits = 1;
    while (temp_x / format.base)
    {
        temp_x /= format.base;
        bin_digits++;
    }
    bin = malloc(bin_digits + 1);
    bin[bin_digits] = '\0';

    for (i = 0 ; i < bin_digits ; i++)
    {
        bin[bin_digits - i - 1] = get_digit_value(x, format.base, i, format.hex_upper);
    }
    return bin;
}

char unsigned_get_digit_value(unsigned long int x, int base, int digit, int hex_upper)
{
    int value = 0;
    while (digit)
    {
        x /= base;
        digit--;
    }
    value = x % base;
    if (value >= 0 && value <= 9)
    {
        return (value + '0');    
    }
    else
    {
        if (hex_upper)
        {
            return (value - 10 + 'A');
        }
        
        return (value - 10 + 'a');
    }    
}
