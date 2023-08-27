#include "headerfile.h"

void    check_args(int argc, char **argv)
{
    if (argc != 2)
        display_error();
    (void)argv;
}


int main(int argc, char **argv)
{
    check_args(argc, argv);
    get_input(argv[1]);

    return (0);
}