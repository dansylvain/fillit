#include "headerfile.h"

void    display_error(void)
{
    write (1, "Error.", 6);
}

void    display_tet(Data *data)
{
    int i;
    int j;
    int k;

    i = 0;
    while (i < data->tetnum)
    {
        j = 0;
        while (j < 4)
        {
            k = 0;
            while (k < 4)
            {
                write(1, &data->tet[i][j][k], 1);
                k++;
            }
            write (1, "\n", 1);
            j++;
        }
        i++;
        write(1, "\n", 1);
    }

}