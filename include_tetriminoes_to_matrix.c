#include "headerfile.h"

void    handle_return(Data *data, int *i, int *y, int *x)
{
    if (data->input[*i] == '\n' && data->input[*i - 1] != '\n')
        {
            (*y)++;
            *x = 0;
        }
}

void    handle_new_tetriminion(Data *data, int *i, int *y, int *j)
{
    if (data->input[*i] == '\n' && data->input[*i - 1] == '\n')
    {
        (*j)++;
        *y = 0;
    }
}
void    include_tetriminoes_in_matrix(Data *data)
{
    int i;
    int j;
    int x;
    int y;

    i = 0;
    j = 0;
    x = 0;
    y = 0;
    while (i < data->input_size)
    {
        if (data->input[i] == '.')
            data->tet[j][y][x++] = data->input[i];
        else if (data->input[i] == '#')
            data->tet[j][y][x++] = j + 65;
        handle_return(data, &i, &y, &x);
        handle_new_tetriminion(data, &i, &y, &j);
        i++;
    }
}