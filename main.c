#include "headerfile.h"

int    check_args(Data *data, int argc, char **argv)
{
    //************* REMOVE WHEN PROJECT IS COMPLETE !!! ***********
    if (argc == 1)
    {
        data->inputfile = "extern_file.txt";
        return (1);
    }



    //*************************************************************
    if (argc != 2)
    {
        display_error();
        return (0);
    }
    data->inputfile = argv[1];
    return (1);
}


int main(int argc, char **argv)
{
    Data *data;

    data = malloc(sizeof(Data));
    if (!check_args(data, argc, argv))
        return (1);
    get_input(data, data->inputfile);
     if (!check_input(data, data->input))
         return (1);
    data->tet = create_matrix(data);
    include_tetriminoes_in_matrix(data);
    //display_tetrominos(data);
    clean_tetriminos(data);
    display_tetrominos(data);
        //TEST THINGS HERE!!!
    


    // create_sol_matrix(data);
    //display_solution(data);
    //add_tetromino_to_sol(data, 2, 0, 0);
    //display_solution(data);

    return (0);
}