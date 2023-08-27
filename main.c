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
    include_tetriminoes_in_matrix(data);
    create_sol_matrix(data);
    display_tetrominos(data);
    add_tetromino_to_sol(data, 1);
    display_solution(data);
    return (0);
}