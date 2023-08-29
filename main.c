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
    data->tet = initialize_matrix(data, data->tet);
    include_tetriminoes_in_matrix(data);
    //display_tetrominos(data);
    if (!tetriminis_are_valid(data))
        return (1);
    update_matrix(data);
    display_matrix_update(data);
        //TEST THINGS HERE!!!
    

    /* NOTE: les fonctions relatives aux fonctions ci-dessous
    n'ont pas été testées et peuvent être ignorées, si tu souhaites 
    commencer ton algo sur des bases "neuves".

    En compilant et en executant le code ci-dessus, tu a un aperçu du contenu de
    la matrice data->mat_update. compile avec 'make' ;).
    Chaque Tetriminos fait 4x4 et est le plus "à gauche en haut" possible.

    La validité de l'input est testée: qualité des charactères, validité des tetriminos, 
    formatage de l'input.
    En cas d'erreur, un message est affiché et un code erreur retourné

    NOTE: j'ai remarqué que lorsque je compile avec le makefile, je n'obtiens pas toujours
    les mêmes messages d'erreurs que j'obtiens en compilant directement avec gcc. 
    */

    // create_sol_matrix(data);
    //display_solution(data);
    //add_tetromino_to_sol(data, 2, 0, 0);
    //display_solution(data);

    free_everything(data);
    return (0);
}