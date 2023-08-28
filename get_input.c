#include "headerfile.h"

int    check_input(Data *data, char *c)
{
    int i;
    int j;
    int k;
    int l;

    i = 0;  // carac counter (string level)
    j = 0;  // letter counter (tetriminos level)
    k = 0;  // line counter
    l = 0;  // tetriminos counter
    while (i < data->input_size)
    {
        if (c[i] != '\n')
            j++;
        if ((c[i] == '\n' || i == data->input_size - 1) && j != 4 && c[i - 1] != '\n')
        {
            display_error();
            return (0);
        }
        if (c[i] == '\n')
        {
            k++;
            j = 0;
        }
        if (c[i] == '\n' && c[i - 1] == '\n' && k != 5)
            {
                display_error();
                return (0);
            }
        if (c[i]  == '\n' && c[i - 1] == '\n')
        {
            k = 0;
            l++;
        }
        if (c[i] != '.' && c[i] != '#' && c[i] != '\n')
        {
                display_error();    
                return (0);
        }
        i++;
    }
    if (l == 0 || l > 25)
    {
        display_error();
        return (0);
    }
    data->tetnum = l + 1;
    return (1);
}

void    get_input(Data *data, char *argv)
{
    int fd;
    size_t size;
    int input_size;
    char *input;

    input = (char*)malloc(sizeof(char) * MAX);
    fd = open(argv, O_RDONLY);
    if (fd == -1)
    {
        display_error();
    }
    size = read(fd, input, MAX);
    input[size] = '\0';
    input_size = (int)size;
    data->input_size = input_size;
    printf("input_size : %i\n", data->input_size);
    data->input = input;
    if (!check_input(data, input))
        display_error();
}