#include "headerfile.h"

void    ft_print_sol(int mat_size, int n_tetrim, char sol[mat_size][mat_size][n_tetrim])
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (i < mat_size)
    {
        while (j < mat_size)
        {
            write(1, &sol[i][j][0], 1);
            j++;
        }
        write(1, "\n", 1);
        j = 0;
        i++;
    }
    write(1, "\n", 1);
}

int     ft_get_tetrim_index(char tetrim)
{
    int     n;

    n = 0;
    while (tetrim-- != 'A')    
        n++;       
    return (n);
}  

int     ft_is_tretrim_max_right(int mat_size, int n_tetrim, int tetrim_index, char tetrim, char sol[mat_size][mat_size][n_tetrim])
{
    int     i;
    int     j;

    i = 0;
    j = mat_size - 1;
    while (i < mat_size) 
    { 
        if (sol[i][j][tetrim_index] == tetrim) 
            return (1);        
        else   
            i++;     
    }
    return (0);
}

void     ft_move_tetrim_right(int mat_size, int n_tetrim, int tetrim_index, char tetrim, char sol[mat_size][mat_size][n_tetrim])
{   
    int     i;
    int     j;    
       
    i = 0;
    j = mat_size - 1;    
    while (i < mat_size)
    {
        while (j >= 0)
        {
            if (sol[i][j][tetrim_index] == tetrim)
            {                             
                sol[i][j + 1][tetrim_index] = sol[i][j][tetrim_index];
                sol[i][j][tetrim_index] = '.';  
            }
            j--;
        }        
        j = mat_size - 1;
        i++;
    }
}

int     ft_is_tretrim_max_down(int mat_size, int n_tetrim, int tetrim_index, char tetrim, char sol[mat_size][mat_size][n_tetrim])
{
    int     i;
    int     j;

    i = mat_size - 1;
    j = mat_size - 1;
    while (j >= 0) 
    { 
        if (sol[i][j][tetrim_index] == tetrim) 
            return (1);        
        else   
            j--;     
    }
    return (0);
}

void     ft_move_tetrim_down(int mat_size, int n_tetrim, int tetrim_index, char tetrim, char sol[mat_size][mat_size][n_tetrim])
{
    int     i;
    int     j;    
       
    i = mat_size - 1;
    j = mat_size - 1;    
    while (i >= 0)
    {
        while (j >= 0)
        {
            if (sol[i][j][tetrim_index] == tetrim)
            {  
                sol[i + 1][j][tetrim_index] = sol[i][j][tetrim_index];
                sol[i][j][tetrim_index] = '.';                  
            }
            j--;
        }
        j = mat_size - 1;
        i--;
    }
}
int     ft_rewind_tetrim_left()
{

}

int     ft_move_tetrim(int mat_size, int n_tetrim, int tetrim_index, char tetrim, char sol[mat_size][mat_size][n_tetrim])
{
    if (!ft_is_tretrim_max_right(mat_size, n_tetrim, tetrim_index, tetrim, sol))   
        ft_move_tetrim_right(mat_size, n_tetrim, tetrim_index, tetrim, sol);    
    else if (!ft_is_tretrim_max_down(mat_size, n_tetrim, tetrim_index, tetrim, sol))
        ft_move_tetrim_down(mat_size, n_tetrim, tetrim_index, tetrim, sol);  
    else   
        return (0);
    return (1); 
}

int     ft_rec_search_optimal_solution(int mat_size, int n_tetrim, char tetrim, char sol[mat_size][mat_size][n_tetrim])
{
    int     tetrim_index;

    tetrim_index = ft_get_tetrim_index(tetrim);   
    ft_print_sol(mat_size, n_tetrim, sol);    
    while (ft_move_tetrim(mat_size, n_tetrim, tetrim_index, tetrim, sol))     
        ft_print_sol(mat_size, n_tetrim, sol);
}

int     ft_launch_recursive(int mat_size, int n_tetrim, char sol[mat_size][mat_size][n_tetrim])
{    
    ft_rec_search_optimal_solution(mat_size, n_tetrim, 'A', sol);
}

int     main(void)
{
    int     mat_size;
    int     n_tetrim;

    mat_size = 4;
    n_tetrim = 2;
    char   sol[4][4][2] =
          {{{'.', 'B'}, {'.', 'B'}, {'A', '.'}, {'.', 'B'}}, 
           {{'.', 'B'}, {'.', 'B'}, {'A', '.'}, {'.', 'B'}}, 
           {{'.', '.'}, {'.', '.'}, {'.', '.'}, {'.', '.'}}, 
           {{'.', '.'}, {'.', '.'}, {'.', '.'}, {'.', '.'}}};           
    ft_launch_recursive(mat_size, n_tetrim, sol);
    return (0);
}