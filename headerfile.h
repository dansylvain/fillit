#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX 1024

typedef struct {
   char ***tet;
   int  tetnum;
   char  *input;
} Data;

//*****************************************************************************
void    create_matrix(Data *data);
//*****************************************************************************
void    display_error(void);
void    display_tet(Data *data);
//*****************************************************************************
void    ft_putchar(char c);
//*****************************************************************************
int    check_input(char *c);
void    get_input(Data *data, char  *c);
//*****************************************************************************
void    include_tetriminoes_in_matrix(Data *data);
//*****************************************************************************
void    check_args(int argc, char **argv);


#endif