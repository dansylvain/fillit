#include "headerfile.h"

void    display_tet(char ***tet, int tetnum)
{
    int i;
    int j;
    int k;

    i = 0;
    while (i < tetnum)
    {
        j = 0;
        while (j < 4)
        {
            k = 0;
            while (k < 4)
            {
                write(1, &tet[i][j][k], 1);
                k++;
            }
            write (1, "\n", 1);
            j++;
        }
        i++;
        write(1, "\n", 1);
    }

}


char    ***create_matrix(int tetnum)
{
    int i;
    int x;
    int y;
    char ***tet;

    tet = malloc(sizeof(char **) * tetnum);
    i = 0;
    while (i < tetnum)
    {
        y = 0;
        tet[i] = malloc(sizeof(char *) * 4);   
        while (y < 4)
        {
            tet[i][y] = malloc(sizeof(char) * 5);   
            y++;
        }
        i++;
    }

    i = 0;
    while (i < tetnum)
    {
        y = 0;
        while (y < 4)
        {
            x = 0;
            while (x < 4)
            {
                tet[i][y][x] = '.';
                x++;
            }
            tet[i][y][x] = '\0';
            y++;
        }
        i++; 
    }
    display_tet(tet, tetnum);

    return (tet);
}

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

void    fill_matrix(char *c, int tetnum)
{
    int i;
    int x;
    int y;

    i = 0;
    x = 0;
    y = 0;
    while (c[i])
    {
        if (c[i] == '\n')
        {

        }
    }
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
        fill_matrix(c, tetnum);
    }
}