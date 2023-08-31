#include "headerfile.h"

int get_tet_size_y(char **tet)
{
    int res;

    res = 0;
    while (tet[res][0])
        res++;
    return (res);
}

int get_tet_size_x(char **tet)
{
    int res;

    res = 0;
    while (tet[0][res])
        res++;
    return (res);
}

void    add_tetriminos_to_matrix(Data *data, int tet, int x, int y)
{
    int i;
    int j;

    i = 0;
    if (!can_place_tet(data, tet, x, y))
        return;
    while (i < 4)
    {
        j = 0;
        while (data->mat_update[tet][j][i])
        {
            if (data->mat_update[tet][j][i] != '.')
                data->sol[y + j][x + i] = data->mat_update[tet][j][i];
            j++;
        }
        i++;
    }
}


