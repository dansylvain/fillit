#include "headerfile.h"

char ***initialize_matrix(Data *data, char ***matrix)
{
    int i;
    int x;
    int y;

    i = 0;
    while (i < data->tetnum)
    {
        y = 0;
        while (y < 5)
        {
            x = 0;
            while (x < 4)
            {
                data->tet[i][y][x] = '.';
                x++;
            }
            data->tet[i][y][x] = '\0';
            y++;
        }
        i++;
    }
    return (matrix);
}


char    ***create_3Dmatrix(Data *data)
{
    int i;
    int y;
    char ***matrix;

    matrix = malloc(sizeof(char **) * data->tetnum);
    i = 0;
    while (i < data->tetnum)
    {
        y = 0;
        matrix[i] = malloc(sizeof(char *) * 5);   
        while (y < 5)
        {
            matrix[i][y] = malloc(sizeof(char) * 5);   
            y++;
        }
        i++;
    }
    return (matrix);
}

void    fill_sol_matrix(Data *data, int size)
{
    int x;
    int y;

    y = 0;
    while (y < size)
    {
        x = 0;
        while (x < size)
        {
            data->sol[y][x] = '.';
            x++;
        }
        data->sol[y][x] = '\0';
        y++;
    }
}

void    create_sol_matrix(Data *data, int size)
{
    int i;

    data->sol = malloc(sizeof(char *) * size);
    i = 0;
    while (i < size)
        data->sol[i++] = malloc(sizeof(char) * (size + 1)); 
    fill_sol_matrix(data, size);  
}