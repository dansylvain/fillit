#include "headerfile.h"

int    check_input(char *c)
{
    int i;
    int j;
    int k;
    int l;

    i = 0;  // carac counter (string level)
    j = 0;  // letter counter (tetriminos level)
    k = 0;  // line counter
    l = 0;  // tetriminos counter
    while (c[i])
    {
        if (c[i] != '\n')
            j++;
        if (c[i] == '\n' && j != 4 && c[i - 1] != '\n')
        {
            display_error();
            return (0);
        }
        if (c[i] == '\n')
        {
            k++;
            j = 0;
        }
        if (c[i] == '\n' && c[i - 1] == '\n' && k != 5)
            {
                display_error();
                return (0);
            }
        if (c[i]  == '\n' && c[i - 1] == '\n')
        {
            k = 0;
            l++;
        }
        if (c[i] != '.' && c[i] != '#' && c[i] != '\n')
        {
                display_error();    
                return (0);
        }
        i++;
    }
    if (l == 0 || l > 25)
    {
        display_error();
        return (0);
    }
    return (l);
}

void    get_input(char *argv)
{
    int fd;
    size_t size;
    char *c;
    int tetnum;

    c = (char*)malloc(sizeof(char) * MAX);
    fd = open(argv, O_RDONLY);
    if (fd == -1)
    {
        display_error();
    }
    size = read(fd, c, MAX);
    c[size] = '\0';

    tetnum = check_input(c) + 1;
    if (check_input(c))
    {
        create_matrix(tetnum);
        //fill_matrix(c, tetnum);
    }
}