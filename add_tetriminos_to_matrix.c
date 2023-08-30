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


int is_possible_to_add_tetrominos(Data *data, int tet, int x, int y)
{
    int tet_size_x;
    int tet_size_y;
    int i;
    int j;


    tet_size_x = get_tet_size_x(data->mat_update[tet]);
    tet_size_y = get_tet_size_y(data->mat_update[tet]);
    if (x + tet_size_x > data->sol_size || y + tet_size_y > data->sol_size)
        return (0);
    i = 0;
    while (i < tet_size_y)
    {
        j = 0;
        while (j < tet_size_x)
        {
            if (data->mat_update[tet][j][i] != '.' && data->sol[y][x] != '.')
                return (0);
            j++;
            x++;
        }
        x -= tet_size_x;
        i++;
        y++;
    }
    return (1);
}

void    add_tetriminos_to_matrix(Data *data, int tet, int x, int y)
{
    int i;
    int j;

    i = 0;
    if (!is_possible_to_add_tetrominos(data, tet, x, y))
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

void    check_func_add_tetriminos_to_matrix(Data *data)
{
    int i;
    int j;
    int sol_size = ft_sqrt(data->tetnum * 4);
    // printf("tetnum: %i\n", data->tetnum);
    // printf("tet x = %i\n", get_tet_size_x(data->mat_update[0]));

    i = 0;
    while (i < data->tetnum)
    {
        j = 0;
        while (j < data->tetnum)
        {
            // create_sol_matrix(data, sol_size);
            // add_tetriminos_to_matrix(data, 3, j, i);
            // display_solution(data, sol_size);
            // free_sol_matrix(data, sol_size);
            j++;
        }
            i++;
    }
    (void)sol_size;
}


