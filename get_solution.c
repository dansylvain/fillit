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
    while (j < tet_size_y && y + j < data->sol_size)
    {
        i = 0;
        x = x_tmp;
        while (i < tet_size_x && x + i < data->sol_size)
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
    int i;
    int j;
    int tet_size_x;
    int tet_size_y;
    int x_tmp;

    x_tmp = x;
    tet_size_x = get_tet_size_x(data->mat_update[tet_index]);
    tet_size_y = get_tet_size_y(data->mat_update[tet_index]);
    j = 0;
    while (j < tet_size_y && y < data->sol_size)
    {
        i = 0;
        x = x_tmp;
 printf("tet_size_y: %i, y: %i, j: %i, data->sol_size + 1: %i\n",tet_size_y, y, j, data->sol_size + 1);
 printf("tet_size_x: %i, x: %i, i: %i, data->sol_size + 1: %i\n",tet_size_x, x, i, data->sol_size + 1);
printf("data->mat_update[tet_index][j][i]: %c\n", data->mat_update[tet_index][j][i]);
        while (i < tet_size_x && x < data->sol_size)
        {
            if (data->mat_update[tet_index][j][i] != '.')
            {
                data->sol[y][x] = '.';
            }
            x++;
            i++;
        }
        y++;
        j++;
    }
}

void    get_solution(Data *data, int tet_index)
{
    int x;
    int y;

    if (tet_index == data->tetnum)
    {
        printf("Hourra!\n");
        display_solution(data, data->sol_size);
        return;
    }
    y = 0;
    while (y < data->sol_size)
    {
        x = 0;
        while (x < data->sol_size)
        {
            if (can_place_tet(data, tet_index, x, y))
            {
                add_tetriminos_to_matrix(data, tet_index, x, y);
                display_solution(data, data->sol_size   );        
                get_solution(data, tet_index + 1);
                remove_tetrominos(data, tet_index, x, y);
            }
            x++;
        }  
        y++;
    }

}