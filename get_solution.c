#include "headerfile.h"

int ignore_blanks_vertical(Data *data, int tet_tested)
{
    int x;
    int y;

    y = 0;
    while (y < 4)
    {
        x = 0;
        while (x < 4)
        {
            if (data->tet[tet_tested][y][x] != '.')
                return (y);
            x++;
        }
        y++;
    }
    return(y);
}

int ignore_blanks_horizontal(Data *data, int tet_tested)
{
    int x;
    int y;

    x = 0;
    while (x < 4)
    {
        y = 0;
        while (y < 4)
        {
            if (data->tet[tet_tested][x][y] != '.')
                return (x);
            y++;
        }
        x++;
    }
    return(x);
}

void    add_tetromino_to_sol(Data *data, int tet_tested, int v, int h)
{
    int x;
    int y;
    int x_tet;
    int y_tet;

    y = 0;
    y_tet = ignore_blanks_vertical(data, tet_tested);
    while (y < 4 && y_tet < 4)
    {
        x = 0;
        x_tet = ignore_blanks_horizontal(data, tet_tested);
        while (x < 4 && x_tet < 4)
        {
            data->sol[y + v][x + h] = data->tet[tet_tested][y_tet][x_tet];
            x++;
            x_tet++;
        }
        y++;
        y_tet++;
    }
}