#include "headerfile.h"


void    check_input(char *c)
{
    int i;
    int d;
    int e;
    int f;

    i = 0;
    d = 0;
    e = 0;
    f = 0;
    while (c[i])
    {
        if (c[i] != '\n')
            d++;
        if (c[i] == '\n' && d != 4 && c[i - 1] != '\n')
            display_error();
        if (c[i] == '\n')
        {
            e++;
            d = 0;
        }
        if (c[i] == '\n' && c[i - 1] == '\n' && e != 5)
            display_error();
        if (c[i]  == '\n' && c[i - 1] == '\n')
        {
            e = 0;
            f++;
        }
        if (c[i] != '.' && c[i] != '#' && c[i] != '\n')
            {
                display_error();
            }
        
        ft_putchar(c[i++]);
    }
    if (f == 0 || f > 25)
    {
        display_error();
    }
}



void    get_input()
{
    int fd;
    size_t size;
    char* c = (char*)malloc(sizeof(char) * MAX);

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        display_error();
    }

    size = read(fd, c, MAX);
    c[size] = '\0';
    check_input(c);
}