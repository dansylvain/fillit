#include "headerfile.h"

void    ft_putchar(char c)
{
    write (1, &c, 1);
}

void display_error(void)
{
    write(1, "Error.\n", 6);
}