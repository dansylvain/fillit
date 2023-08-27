#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX 1024

typedef struct {
   char ***tet;
   char **sol;
   int  tetnum;
   char  *input;
} Data;

//****************************** CREATE_MATRIX.C ******************************
void    create_matrix(Data *data);
void    create_sol_matrix(Data *data);
//*************************** DISPLAY.C ***************************************
void    display_error(void);
void    display_tet(Data *data);
void    display_tetromino(Data *data, int tet_winner);
void    display_tetrominos(Data *data);
void    display_solution(Data *data);


//***************************** FUNC.C ****************************************
void    ft_putchar(char c);
//************************* GET_INPUT.C ***************************************
int    check_input(char *c);
void    get_input(Data *data, char  *c);
//************************* GET_SOLUTION.C ************************************
void    add_tetromino_to_sol(Data *data, int tet_tested);
//*************** INCLUDE TETROMINOES_IN_MATRIX.C *****************************
void    include_tetriminoes_in_matrix(Data *data);
//************************ MAIN.C *********************************************
void    check_args(int argc, char **argv);


#endif