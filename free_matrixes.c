#include "headerfile.h"

void free_matrix(char ***matrix, int ternum)
{
    int i;
    int j;

    i = 0;
    while (i < ternum)
    {
        j = 0;
        while (j < ternum)
            free(matrix[i][j++]);
        free(matrix[i]);
        i++;
    }
    free(matrix);
}

void    free_matrixes(Data *data)
{
    free_matrix(data->tet, data->tetnum);
    free_matrix(data->mat_update, data->tetnum);
}