#include "headerfile.h"

void    ft_print_sol(int mat_size, int n_tetrim, int i_tetrim, char sol[mat_size][mat_size][n_tetrim])
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (i < mat_size)
    {
        while (j < mat_size)
        {
            write(1, &sol[i][j][i_tetrim], 1);
            j++;
        }
        write(1, "\n", 1);
        j = 0;
        i++;
    }
    write(1, "\n", 1);
}

int     ft_is_tretrim_max_right(int mat_size, int n_tetrim, int i_tetrim, char tetrim, char sol[mat_size][mat_size][n_tetrim])
{
    int     i;
    int     j;

    i = 0;
    j = mat_size - 1;
    while (i < mat_size) 
    { 
        if (sol[i][j][i_tetrim] == tetrim) 
            return (1);        
        else   
            i++;     
    }
    return (0);
}

int     ft_is_tretrim_max_down(int mat_size, int n_tetrim, int i_tetrim, char tetrim, char sol[mat_size][mat_size][n_tetrim])
{
    int     i;
    int     j;

    i = mat_size - 1;
    j = mat_size - 1;
    while (j >= 0) 
    { 
        if (sol[i][j][i_tetrim] == tetrim) 
            return (1);        
        else   
            j--;     
    }
    return (0);
}

int     ft_get_i_tetrim(char tetrim)
{
    int     n;

    n = 0;
    while (tetrim-- != 'A')    
        n++;       
    return (n);
}  

void     ft_move_tetrim_right(int mat_size, int n_tetrim, int i_tetrim, char tetrim, char sol[mat_size][mat_size][n_tetrim])
{   
    int     i;
    int     j;    
       
    i = 0;
    j = mat_size - 1;    
    while (i < mat_size)
    {
        while (j >= 0)
        {
            if (sol[i][j][i_tetrim] == tetrim)
            {                             
                sol[i][j + 1][i_tetrim] = sol[i][j][i_tetrim];
                sol[i][j][i_tetrim] = '.';  
            }
            j--;
        }        
        j = mat_size - 1;
        i++;
    }
}

/*
** optimisation maybe possible if add ft_is_move_over!
*/
void     ft_move_tetrim_down(int mat_size, int n_tetrim, int i_tetrim, char tetrim, char sol[mat_size][mat_size][n_tetrim])
{
    int     i;
    int     j;    
       
    i = mat_size - 1;
    j = mat_size - 1;    
    while (i >= 0)
    {
        while (j >= 0)
        {           
            if (sol[i][j][i_tetrim] == tetrim)
            {  
                sol[i + 1][j][i_tetrim] = sol[i][j][i_tetrim];
                sol[i][j][i_tetrim] = '.';                  
            }
            j--;
        }
        j = mat_size - 1;
        i--;
    }
}

void    ft_move_tetrim_max_left(int mat_size, int n_tetrim, int i_tetrim, char tetrim, char sol[mat_size][mat_size][n_tetrim])
{
    int     i;
    int     j;
    int     offset;

    i = 0;
    j = 0;
    offset = -1; 
    while (i < mat_size)
    {
        while (j < mat_size)
        {
            if (sol[i][j][i_tetrim] == tetrim)
            {
                if (offset == -1)
                    offset = j;
                sol[i][j - offset][i_tetrim] = sol[i][j][i_tetrim];
                sol[i][j][i_tetrim] = '.'; 
            }
            j++;
        }
        j = 0;
        i++;
    }    
}

int     ft_move_tetrim(int mat_size, int n_tetrim, int i_tetrim, char tetrim, char sol[mat_size][mat_size][n_tetrim])
{
    if (!ft_is_tretrim_max_right(mat_size, n_tetrim, i_tetrim, tetrim, sol))   
        ft_move_tetrim_right(mat_size, n_tetrim, i_tetrim, tetrim, sol);    
    else if (!ft_is_tretrim_max_down(mat_size, n_tetrim, i_tetrim, tetrim, sol))
    {
        ft_move_tetrim_down(mat_size, n_tetrim, i_tetrim, tetrim, sol);
        ft_move_tetrim_max_left(mat_size, n_tetrim, i_tetrim, tetrim, sol);
    }       
    else    
        return (0);
    return (1); 
}

int     ft_rec_search_solution(int mat_size, int n_tetrim, int i_tetrim, char tetrim, char sol[mat_size][mat_size][n_tetrim])
{   
    int     i;

    i = 0;    
    ft_print_sol(mat_size, n_tetrim, i_tetrim, sol);
    if (ft_move_tetrim(mat_size, n_tetrim, i_tetrim, tetrim, sol))
    {            
        ft_rec_search_solution(mat_size, n_tetrim, i_tetrim, tetrim, sol); 
    }
    if (tetrim > 'A')    
    {
        tetrim--;
        i_tetrim--;
        ft_print_sol(mat_size, n_tetrim, i_tetrim, sol);
        if (ft_move_tetrim(mat_size, n_tetrim, i_tetrim, tetrim, sol))
        {            
            ft_rec_search_solution(mat_size, n_tetrim, i_tetrim, tetrim, sol); 
        }      
    }
         
    i++;         
    return (1);
}

int     ft_launch_recursive(int mat_size, int n_tetrim, int tetrim, char sol[mat_size][mat_size][n_tetrim])
{    
    int     i_tetrim;

    i_tetrim = ft_get_i_tetrim(tetrim);
  //  printf("%d", i_tetrim);
    ft_rec_search_solution(mat_size, n_tetrim, i_tetrim, tetrim, sol);
}

int     main(void)
{
    int     mat_size;
    int     n_tetrim;
    int     tetrim;

    mat_size = 4;
    n_tetrim = 3;
    tetrim = 'B';
    char   sol[4][4][3] =
          {{{'A', 'B', 'C'}, {'A', 'B', 'C'}, {'.', 'B', 'C'}, {'.', '.', 'C'}}, 
           {{'A', '.', '.'}, {'A', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'}}, 
           {{'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'}}, 
           {{'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'}}};           
    ft_launch_recursive(mat_size, n_tetrim, tetrim, sol);
    return (0);
}