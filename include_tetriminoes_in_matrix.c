#include "headerfile.h"

void    erase_blank_first_column(Data *data, int tet_toclean)
{
       int i;

    i = 0;
    if (first_column_isempty(data, tet_toclean))
    {
        while (i < 4)
        {
                data->tet[tet_toclean][i][0] = '\0';
                i++;
        }
    }
}

void    erase_blank_ligns_and_columns(Data *data, int tet_toclean)
{
    int i;
    int j;
    int k;

    i = 0;
    while (i < 4)
    {
        j = 3;
        k = 0;
        while (j >= 0)
        {
            if (data->tet[tet_toclean][i][j] == '.' && k == 0)
            {
                data->tet[tet_toclean][i][j] = '\0';
            }
            else if (data->tet[tet_toclean][i][j] != '.')
                k++;
            j--;
        }
        i++;
    }
}

int first_column_isempty(Data *data, int tet_tested)
{
    int i;

    i = 0;
    while (i < 4)
    {
        printf("tet: %i, char: %c\n", tet_tested, data->tet[tet_tested][i][0]);
        if (data->tet[tet_tested][i][0] != '.' && data->tet[tet_tested][i][0] != '\0')
            return (0);
        i++;
    }
    return (1);
}

int row_isempty(Data *data, int tet_tested, int row_tested)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (data->tet[tet_tested][row_tested][i] != '\0')
        {
            return (0);

        }

        i++;
    }
    return (1);
}

void clean_tetriminos(Data *data)
{
    int i;
    
    i = 0;
    while (i < data->tetnum)
    {
        erase_blank_ligns_and_columns(data, i);
        erase_blank_first_column(data, i);
        i++;
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
