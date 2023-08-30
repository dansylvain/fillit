#include "headerfile.h"

int can_place_tet(Data *data, int tet_index, int x, int y)
{
    int i;
    int j;
    int tet_size_x;
    int tet_size_y;
    int x_tmp;

    x_tmp = x;
    tet_size_x = get_tet_size_x(data->mat_update[tet_index]);
    tet_size_y = get_tet_size_y(data->mat_update[tet_index]);
    j = 0;
    while (j < tet_size_y)
    {
        i = 0;
        x = x_tmp;
        while (i < tet_size_x)
        {
            if (data->sol[y][x] != '.' && data->mat_update[tet_index][j][i] != '.')
                return (0);
            x++;
            i++;
        }
        y++;
        j++;
    }
    return (1);
}

void    remove_tetrominos(Data *data, int tet_index, int x, int y)
{

    (void)data;
    (void)tet_index;
    (void)x;
    (void)y;
}

void    get_solution(Data *data, int tet_index)
{
    int x;
    int y;

    if (tet_index == data->tetnum)
    {
        display_solution(data, 4);
        exit(1);
    }
    y = 0;
    while (y < 4)
    {
        x = 0;
        while (x < 4)
        {
            if (can_place_tet(data, tet_index, x, y))
            {
                add_tetriminos_to_matrix(data, tet_index, x, y);
                //display_solution(data, 4);        
                get_solution(data, tet_index + 1);
                remove_tetrominos(data, tet_index, x, y);
            }
            x++;
        }  
        y++;
    }

}