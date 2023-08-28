#include "headerfile.h"

void    create_matrix(Data *data)
{
    int i;
    int y;

    data->tet = malloc(sizeof(char **) * data->tetnum);
    i = 0;
    while (i < data->tetnum)
    {
        y = 0;
        data->tet[i] = malloc(sizeof(char *) * 4);   
        while (y < 4)
        {
            data->tet[i][y] = malloc(sizeof(char) * 5);   
            y++;
        }
        i++;
    }
}

void    fill_sol_matrix(Data *data)
{
    int x;
    int y;

    y = 0;
    while (y < data->tetnum * 4)
    {
        x = 0;
        while (x < data->tetnum * 4)
        {
            data->sol[y][x] = '.';
            x++;
        }
        y++;
    }
}

void    create_sol_matrix(Data *data)
{
    int i;

    data->sol = malloc(sizeof(char *) * data->tetnum * 4);
    i = 0;
    while (i < data->tetnum * 4)
        data->sol[i++] = malloc(sizeof(char) * (data->tetnum * 4 + 1)); 
    fill_sol_matrix(data);  
}