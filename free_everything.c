#include "headerfile.h"

void    free_sol_matrix(Data *data, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        free(data->sol[i]);
        i++;
    }
    free(data->sol);
}

void free_matrix(char ***matrix, int ternum)
{
    int i;
    int j;

    i = 0;
    while (i < ternum)
    {
        j = 0;
        while (j < 5)
            free(matrix[i][j++]);
        free(matrix[i]);
        i++;
    }
    free(matrix);
}

void    free_everything(Data *data)
{
    free_matrix(data->tet, data->tetnum);
    free_matrix(data->mat_update, data->tetnum);
    free(data->input);
    free(data);
}
