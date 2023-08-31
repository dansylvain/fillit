#include "headerfile.h"

int is_letter(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    else
        return (0);
}


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
    if (y + tet_size_y > data->sol_size || x + tet_size_x > data->sol_size)
        return (0);
    j = 0;
    while (j < tet_size_y && y < data->sol_size)
    {
        i = 0;
        x = x_tmp;
        while (i < tet_size_x && x < data->sol_size)
        {

            if (is_letter(data->sol[y][x]) && is_letter(data->mat_update[tet_index][j][i]))
                {
                    return (0);
                }
            x++;
            i++;
        }
        y++;
        j++;
    }
    return (1);
}

void    remove_tetriminos(Data *data, int tet_index, int x, int y)
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
    int y;
    int x;
    //printf("debut de fonction, tetindex = %i\n", tet_index);
    if (tet_index == data->tetnum)
    {
        display_solution(data, data->sol_size);
        printf ("solution found!\n");
        exit (1);
    }
    y = 0;
    while (y < data->sol_size)
    {
        x = 0;
        while (x < data->sol_size)
        {
            //printf("entering the loop...\n");
            // printf("tet: %i, x: %i, y: %i\n", tet_index, x, y);
            if (can_place_tet(data, tet_index, x, y))
            {
                printf("tet: %i, x: %i, y: %i", tet_index, x, y);
                printf("entering the canplacetet function\n");
                printf("tet_index placé: %i\n", tet_index);
                add_tetriminos_to_matrix(data, tet_index, x, y);
                display_solution(data, data->sol_size);
                
                // printf("tetnum++! (tetindex: %i)\n", tet_index);
                get_solution(data, tet_index + 1);
                // printf("tet n°: %i, x: %i, y: %i\n", tet_index, x, y);
                remove_tetriminos(data, tet_index, x, y);
            }
            x++;
        }  
        y++;
    }   
}