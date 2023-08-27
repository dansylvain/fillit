#include "headerfile.h"

void    add_tetromino_to_sol(Data *data, int tet_tested)
{
    int x;
    int y;

    y = 0;
    while (y < 4)
    {
        x = 0;
        while (x < 4)
        {
            data->sol[y][x] = data->tet[tet_tested][y][x];
            x++;
        }
        y++;
    }
}