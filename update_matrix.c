#include "headerfile.h"

int column_isempty(char **tested_tet, int tested_col)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (tested_tet[i][tested_col] != '\0')
            return (0);
        i++;
    }
    return (1);
}

int set_x(Data *data, int tet_winner)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < 4)
    {
        if (column_isempty(data->mat_update[tet_winner], i))
            j++;
        i++;
    }
    return (j);
}


void    update_matrix(Data *data)
{
    int i;
    int x;
    int y;

    data->mat_update = create_matrix(data);
    i = 0;
    while (i < data->tetnum)
    {
        y = 0;
        while (y < 4)
        {
            x = 0;//set_x(data, i);
            while (x < 4)
            {
                data->mat_update[i][y][x] = data->tet[i][y][x];
                x++;
            }
            y++;
        }
        i++;
    }
}