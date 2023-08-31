#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



#define MAX 1024

typedef struct {
   char  *inputfile;
   int   input_size;
   char ***tet;
   char ***mat_update;
   char **sol;
   int  tetnum;
   char  *input;
   int   sol_size;
} Data;


int get_tet_size_y(char **tet);
int get_tet_size_x(char **tet);
void    add_tetriminos_to_matrix(Data *data, int tet, int x, int y);
int can_place_tet(Data *data, int tet_index, int x, int y);
void    remove_tetriminos(Data *data, int tet_index, int x, int y);
int is_possible_to_add_tetrominos(Data *data, int tet, int x, int y);



//*********************** check_tetriminis_validity.C *************************
int is_next_to_another_bloc(char **tet, int x, int  y);
int blocs_are_valid(char **tet);
int bloc_quantity_is_OK(char **tet);
int tetrimino_is_valid(char **tet);
int   tetriminis_are_valid(Data *data);


//****************************** create_3Dmatrix.C ******************************
char ***initialize_matrix(Data *data, char ***matrix);
char    ***create_3Dmatrix(Data *data);
void    fill_sol_matrix(Data *data, int size);
void    create_sol_matrix(Data *data, int size);
//*************************** DISPLAY.C ***************************************
void    display_all_tetrimini_in_matrix(Data *data);
void    display_error(void);
void    display_solution(Data *data, int size);
void    display_tetromino(Data *data, int tet_winner);
void    display_tetrominos(Data *data);
void    display_tetromino_update(Data *data, int tet_winner);
void    display_matrix_update(Data *data);

//****************** FREE_EVERYTHING.C ****************************************
void free_matrix(char ***matrix, int ternum);
void    free_everything(Data *data);
void    free_sol_matrix(Data *data, int size);

//***************************** FUNC.C ****************************************
void    ft_putchar(char c);
int ft_sqrt(int nb);

//************************* GET_INPUT.C ***************************************
int    check_input(Data *data, char *c);
void    get_input(Data *data, char  *c);
//************************* GET_SOLUTION.C ************************************
void    check_func_add_tetriminos_to_matrix(Data *data);
void    get_solution(Data *data, int tet_index);
int can_place_tet(Data *data, int tet_index, int x, int y);
//*************** INCLUDE_TETROMINOES_IN_MATRIX.C *****************************
void    handle_return(Data *data, int *i, int *y, int *x);
void    handle_new_tetriminion(Data *data, int *i, int *y, int *j);
void    include_tetriminoes_to_matrix(Data *data);

//************************ UPDATE.C *******************************************
int col_isempty(Data *data, int tet_tested, int col_tested);
int row_isempty(Data *data, int tet_tested, int row_tested);
int get_starting_x(char **tetris);
int get_starting_y(char **tetris);
void    copy_tetrimino_to_update(Data *data, int tet_winner);
void    copy_tetriminos_to_update(Data *data);
void    fill_updated_matrix(Data *data);
void    update_matrix(Data *data);

//************************ MAIN.C *********************************************
int   check_args(Data *data, int argc, char **argv);


#endif