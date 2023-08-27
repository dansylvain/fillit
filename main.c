#include "headerfile.h"

void    check_args(int argc, char **argv)
{
    if (argc != 2)
        display_error();
    (void)argv;
}


int main(int argc, char **argv)
{
    Data *data;

    data = malloc(sizeof(Data));
    check_args(argc, argv);
    get_input(data, argv[1]);
    create_matrix(data);
    display_tet(data);

    return (0);
}