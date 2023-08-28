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
} Data;

//*********************** check_tetriminis_validity.C *************************
int   tetriminis_are_valid(Data *data);


//****************************** CREATE_MATRIX.C ******************************
char    ***create_matrix(Data *data);
void    create_sol_matrix(Data *data);
//*************************** DISPLAY.C ***************************************
void    display_error(void);
void    display_tet(Data *data);
void    display_tetromino(Data *data, int tet_winner);
void    display_tetrominos(Data *data);
void    display_solution(Data *data);
void    display_tetromino_update(Data *data, int tet_winner);
void    display_matrix_update(Data *data);

//***************************** FUNC.C ****************************************
void    ft_putchar(char c);
//************************* GET_INPUT.C ***************************************
int    check_input(Data *data, char *c);
void    get_input(Data *data, char  *c);
//************************* GET_SOLUTION.C ************************************
void    add_tetromino_to_sol(Data *data, int tet_tested, int v, int h);
int ignore_blanks_vertical(Data *data, int tet_tested);
int ignore_blanks_horizontal(Data *data, int tet_tested);

//*************** INCLUDE_TETROMINOES_IN_MATRIX.C *****************************
void    include_tetriminoes_in_matrix(Data *data);
int   check_tetriminos(Data *data, int tet_tested);
void    erase_blank_ligns_and_columns(Data *data, int tet_toclean);
int   first_column_isempty(Data *data, int tet_tested    );
void    erase_blank_first_column(Data *data, int tet_toclean);
int   row_isempty(Data *data, int tet_tested, int row_tested);
void  clean_tetriminos(Data *data);


//************************ UPDATE.C *******************************************
void    update_matrix(Data *data);

//************************ MAIN.C *********************************************
int   check_args(Data *data, int argc, char **argv);


#endif