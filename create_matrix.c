#include "headerfile.h"


// void    fill_matrix(char *c, int tetnum)
// {
//     int i;
//     int x;
//     int y;

//     i = 0;
//     x = 0;
//     y = 0;
//     while (c[i])
//     {
//         if (c[i] == '\n')
//         {

//         }
//     }
// }

char    ***create_matrix(int tetnum)
{
    int i;
    int x;
    int y;
    char ***tet;

    tet = malloc(sizeof(char **) * tetnum);
    i = 0;
    while (i < tetnum)
    {
        y = 0;
        tet[i] = malloc(sizeof(char *) * 4);   
        while (y < 4)
        {
            tet[i][y] = malloc(sizeof(char) * 5);   
            y++;
        }
        i++;
    }

    i = 0;
    while (i < tetnum)
    {
        y = 0;
        while (y < 4)
        {
            x = 0;
            while (x < 4)
            {
                tet[i][y][x] = '.';
                x++;
            }
            tet[i][y][x] = '\0';
            y++;
        }
        i++; 
    }
    display_tet(tet, tetnum);

    return (tet);
}