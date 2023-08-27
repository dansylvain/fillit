    #include "headerfile.h"

    void    create_matrix(Data *data)
    {
        int i;
        int x;
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

        i = 0;
        while (i < data->tetnum)
        {
            y = 0;
            while (y < 4)
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
    }