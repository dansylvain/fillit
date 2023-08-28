#include "headerfile.h"

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
    while (i < data->tetnum * 21)
    {
        if (data->input[i] == '.')
            data->tet[j][y][x++] = data->input[i];
        else if (data->input[i] == '#')
            data->tet[j][y][x++] = j + 65;
        else if (data->input[i] == '\n' && data->input[i - 1] != '\n')
            {
                y++;
                x = 0;
            }
        else if (data->input[i] == '\n' && data->input[i - 1] == '\n')
        {
            j++;
            y = 0;
        }
        i++;
    }

}
