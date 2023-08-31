#include "headerfile.h"

int    check_args(Data *data, int argc, char **argv)
{
    if (argc != 2)
    {
        display_error();
        return (0);
    }
    data->inputfile = argv[1];
    return (1);
}

/*
    Enfin!
    Le programme a l'air de fonctionner. Je n'ai pas testé sous toutes les coutures,
    mais c'est tout de même du solide. Il n'y a plus aucun bug à ma connaissance.
    Le problème, maintenant, c'est que la recherche d'une solution devient 
    TTRRRREEEEESSS longue une fois qu'on dépasse les 12 - 13 tetriminos.

    moi perso, je m'en acomode pour maintenant parce que ça fonctionne, merde.
    La prochaine chose que je souhaite encore faire pour terminer ce projet de 
    mon côté, c'est tout mettre à la norme. Mais de ce côté là, il n'y a plus
    beaucoup de boulot. Il reste quatre fonctions qui sont une peu
    trop longue (check_input, can_place_tet, remove_tetriminos, get_solution).

    Après, si jamais je dois me faire évaluer pour ce projet, j'imagine qu'il faudra
    que je reprenne tout, en partant du Makefile jusqu'à l'optimisation. Pt'et même
    d'ailleurs que la mise à la norm je ne la ferais que dans ce cas précis.

    N'hésite pas à jeter un oeil à mon code et je te serais reconnaissant de
    me signaler les choses que tu ne comprends pas :)
    Je n'ai pas écrit une suele ligne de commentaire...

    Aussi, teste le programme, met lui en plein la poire, fais le pleurer, et dis moi
    si tu trouves des erreurs (mis à part le cas des recherches trrooppp longues) 
*/

int main(int argc, char **argv)
{
    Data *data;

    data = malloc(sizeof(Data));
    if (!check_args(data, argc, argv))
        return (1);
    get_input(data, data->inputfile);
    if (!check_input(data, data->input))
         return (1);
    data->tet = create_3Dmatrix(data);
    data->tet = initialize_matrix(data, data->tet);
    include_tetriminoes_to_matrix(data);
    if (!tetriminis_are_valid(data))
        return (1);
    update_matrix(data);
    data->sol_size = ft_sqrt(data->tetnum * 4);
    create_sol_matrix(data, data->sol_size);
    get_solution(data, 0);
    return (0);
}