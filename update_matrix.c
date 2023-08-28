#include "headerfile.h"

int col_isempty(Data *data, int tet_tested, int col_tested)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (data->tet[tet_tested][i][col_tested] != '.')
        {
            return (0);
        }
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
        if (data->tet[tet_tested][row_tested][i] != '.')
        {
            return (0);
        }
        i++;
    }
    return (1);
}


int get_starting_x(char **tetris)
{
    int x;
    int y;

    x = 0;
    while (x < 4)
    {
        y = 0;
        while (y < 4)
        {
            if (tetris[y][x] != '.')
                return (x);
            y++;
        }
        x++;
    }
    return (y);
}

int get_starting_y(char **tetris)
{
    int x;
    int y;

    y = 0;
    while (y < 4)
    {
        x = 0;
        while (x < 4)
        {
            if (tetris[y][x] != '.')
                return (y);
            x++;
        }
        y++;
    }
    return (y);
}

void    copy_tetrimino_to_update(Data *data, int tet_winner)
{
    int x;
    int y;
    int x_tet;
    int y_tet;

    y = 0;
    y_tet = get_starting_y(data->tet[tet_winner]);
    while (y_tet < 4)
    {
        x = 0;
        x_tet = get_starting_x(data->tet[tet_winner]);
        while (x_tet < 4)
        {
            if (!row_isempty(data, tet_winner, y_tet) && 
            !col_isempty(data, tet_winner, x_tet))
                data->mat_update[tet_winner][y][x] = data->tet[tet_winner][y_tet][x_tet];
            x++;
            x_tet++; 
        }
        y++;
        y_tet++;
    }
}


void    copy_tetriminos_to_update(Data *data)
{
    int i;

    i = 0;
    while (i < data->tetnum)
    {
        copy_tetrimino_to_update(data, i);
        i++;
    }
}


void    fill_updated_matrix(Data *data)
{
    int i;
    int x;
    int y;

    i = 0;
    while (i < data->tetnum)
    {
        y = 0;
        while (y < 4)
        {
            x = 0;
            while (x < 4)
            {
                data->mat_update[i][y][x] = '\0';
                x++;
            }
            y++;
        }
        i++;
    }
}

void    update_matrix(Data *data)
{
    data->mat_update = create_matrix(data);
    fill_updated_matrix(data);
    copy_tetriminos_to_update(data);
}