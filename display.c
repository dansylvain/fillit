#include "headerfile.h"


void    display_tet(char ***tet, int tetnum)
{
    int i;
    int j;
    int k;

    i = 0;
    while (i < tetnum)
    {
        j = 0;
        while (j < 4)
        {
            k = 0;
            while (k < 4)
            {
                write(1, &tet[i][j][k], 1);
                k++;
            }
            write (1, "\n", 1);
            j++;
        }
        i++;
        write(1, "\n", 1);
    }

}