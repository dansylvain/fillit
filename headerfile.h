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
} Data;

void    check_args(int argc, char **argv);
void    get_input(Data *data, char  *c);
void    ft_putchar(char c);
void    display_error(void);
void    display_tet(Data *data);
void    create_matrix(Data *data);




#endif