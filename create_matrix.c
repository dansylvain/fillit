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