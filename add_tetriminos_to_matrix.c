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
    int tet_size_x;
    int tet_size_y;  
    
    tet_size_x = get_tet_size_x(data->mat_update[tet]);
    tet_size_y = get_tet_size_y(data->mat_update[tet]);
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (data->mat_update[tet][j][i])
        {
            if (y + tet_size_y < 5 && x + tet_size_x < 5 && data->mat_update[tet][j][i] != '.')
                data->sol[y + j][x + i] = data->mat_update[tet][j][i];
            j++;
        }
        i++;
    }
    (void)tet_size_x;
    (void)tet_size_y;
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
            create_sol_matrix(data, sol_size);
            add_tetriminos_to_matrix(data, 3, j, i);
            display_solution(data, sol_size);
            free_sol_matrix(data, sol_size);
            j++;
        }
            i++;
    }
    (void)sol_size;
}


