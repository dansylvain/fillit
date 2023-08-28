#include "headerfile.h"

void    display_error(void)
{
    write (1, "Error.\n", 7);
}

void    display_solution(Data *data)
{
    int x;
    int y;

    write (1, "Solution:\n", 10);
    y = 0;
    while (y < data->tetnum * 4)
    {
        x = 0;
        while (x < data->tetnum * 4)
        {
            write (1, &data->sol[y][x], 1);
            x++;
        }
        write (1, "\n", 1);
        y++;
    }
}

void    display_tetromino(Data *data, int tet_winner)
{
    int x;
    int y;

    printf("tetromino n°%i:\n", tet_winner);
    y = 0; 
    while (y < 4)
    {
        x = 0; 
        if (!row_isempty(data, tet_winner, y))
            {
                while (x < 4)
                {
                    if (data->tet[tet_winner][y][x] != '.')
                        write (1, &data->tet[tet_winner][y][x], 1);
                    else
                        write (1, ".", 1);

                    x++;
                }
            write (1, "\n", 1);
            }
        y++;
    }

}


void    display_tetrominos(Data *data)
{
    int i;

    i = 0;
    while (i < data->tetnum)
    {
        display_tetromino(data, i);
        i++;
    }

}