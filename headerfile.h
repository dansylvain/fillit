#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#define MAX 1024

void    check_args(int argc, char **argv);
void    get_input();
void    ft_putchar(char c);
void display_error(void);
void    display_tet(char ***tet, int tetnum);
char    ***create_matrix(int tetnum);




#endif