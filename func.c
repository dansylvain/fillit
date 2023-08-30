#include "headerfile.h"

int ft_sqrt(int nb)
{
    int i;
    int res;
    
    i = 0;
    res = 0;
    while (i < nb)
    {
        res++;
        i = res;
        i *= i;
    }
    return (res);
}


void    ft_putchar(char c)
{
    write (1, &c, 1);
}

