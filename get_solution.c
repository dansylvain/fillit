#include "headerfile.h"

void    add_tetriminos_to_matrix(Data *data, int tetnum, int x, int y)
{
    int i;
    int j;    
    
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (data->mat_update[tetnum][j][i])
        {
            if (y + j < 4 && x + i < 4)
                data->sol[y + j][x + i] = data->mat_update[tetnum][j][i];
            j++;
        }
        i++;
    }
}

int check_sol_state(Data *data)
{
    int x;
    int y;
    data->sol_size = 4;

    y = 0;
    while(y < data->sol_size)
    {
        x = 0;
        while (x < data->sol_size)
        {

            x++;
        }
        y++;
    }
    return 0;
}