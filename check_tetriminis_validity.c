#include "headerfile.h"

int is_next_to_another_bloc(char **tet, int x, int  y)
{
    if (y > 0 && tet[y - 1][x] != '.')
        return (1);
    if (y < 3 && tet[y + 1][x] != '.')
        return (1);
    if (x > 0 && tet[y][x - 1] != '.')
        return (1);
    if (x < 3 && tet[y][x + 1] != '.')
        return (1);
    return (0);
}

int blocs_are_valid(char **tet)
{
    int x;
    int y;

    y = 0;
    while (y < 4)
    {
        x = 0;
        while (x < 4)
        {
            if (tet[y][x] != '.')
            {
                if (!is_next_to_another_bloc(tet, x, y))
                    return (0);
            }
            x++;
        }
        y++;
    }
    return (1);
    (void)tet;
}

int bloc_quantity_is_OK(char **tet)
{
    int x;
    int y;
    int b;

    b = 0;
    y = 0;
    while (y < 4)
    {
        x = 0;
        while (x < 4)
        {
            if (tet[y][x] != '.')
                b++;
            x++;
        }
        y++;
    }
    if (b ==4)
        return (1);
    else
        return (0);
}

int tetrimino_is_valid(char **tet)
{
    if (!bloc_quantity_is_OK(tet))
        return (0);
    if (!blocs_are_valid(tet))
        return (0);
    return (1);
}

int tetriminis_are_valid(Data *data)
{
    int i;

    i = 0;
    while (i < data->tetnum)
    {
        if (!tetrimino_is_valid(data->tet[i]))
        {
            display_error();
            return (0);
        }
        i++;
    }
    return (1);
}