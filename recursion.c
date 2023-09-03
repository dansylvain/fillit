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

void    ft_print_all_sol(int mat_size, int n_tetrim, char sol[mat_size][mat_size][n_tetrim])
{
    int     i_tetrim;

    i_tetrim = -1;
    while (++i_tetrim < n_tetrim)
        ft_print_sol(mat_size, n_tetrim, i_tetrim, sol);
    write(1, "\n*\n", 3);
}

int     ft_is_tretrim_max_right(int mat_size, int n_tetrim, int i_tetrim, char sol[mat_size][mat_size][n_tetrim])
{
    int     i;
    int     j;

    i = 0;
    j = mat_size - 1;
    while (i < mat_size) 
    { 
        if (sol[i][j][i_tetrim] != '.') 
            return (1);        
        else   
            i++;     
    }
    return (0);
}

int     ft_is_tretrim_max_down(int mat_size, int n_tetrim, int i_tetrim, char sol[mat_size][mat_size][n_tetrim])
{
    int     i;
    int     j;

    i = mat_size - 1;
    j = mat_size - 1;
    while (j >= 0) 
    { 
        if (sol[i][j][i_tetrim] != '.') 
            return (1);        
        else   //
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

void     ft_move_tetrim_right(int mat_size, int n_tetrim, int i_tetrim, char sol[mat_size][mat_size][n_tetrim])
{   
    int     i;
    int     j;    
       
    i = 0;
    j = mat_size - 1;    
    while (i < mat_size)
    {
        while (j >= 0)
        {
            if (sol[i][j][i_tetrim] != '.')
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
void     ft_move_tetrim_down(int mat_size, int n_tetrim, int i_tetrim, char sol[mat_size][mat_size][n_tetrim])
{
    int     i;
    int     j;    
       
    i = mat_size - 1;
    j = mat_size - 1;    
    while (i >= 0)
    {
        while (j >= 0)
        {           
            if (sol[i][j][i_tetrim] != '.')
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

void    ft_move_tetrim_max_left(int mat_size, int n_tetrim, int i_tetrim, char sol[mat_size][mat_size][n_tetrim])
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
            if (sol[i][j][i_tetrim] != '.')
            {
                if (offset == -1)
                    offset = j;
                if (offset == 0)
                    return;
                sol[i][j - offset][i_tetrim] = sol[i][j][i_tetrim];
                sol[i][j][i_tetrim] = '.'; 
            }
            j++;
        }
        j = 0;
        i++;
    }    
}

int     ft_move_tetrim(int mat_size, int n_tetrim, int i_tetrim, char sol[mat_size][mat_size][n_tetrim])
{
    if (!ft_is_tretrim_max_right(mat_size, n_tetrim, i_tetrim, sol))   
        ft_move_tetrim_right(mat_size, n_tetrim, i_tetrim, sol);    
    else if (!ft_is_tretrim_max_down(mat_size, n_tetrim, i_tetrim, sol))
    {
        ft_move_tetrim_down(mat_size, n_tetrim, i_tetrim, sol);
        ft_move_tetrim_max_left(mat_size, n_tetrim, i_tetrim, sol);
    }       
    else    
        return (0);
    return (1); 
}

void    ft_save_sol(int mat_size, int n_tetrim, char sol[mat_size][mat_size][n_tetrim], char saved_sol[mat_size][mat_size][n_tetrim])
{    
    int     i;
    int     j;
    int     k;

    i = 0;
    j = 0;
    k = 0;
    while (i < mat_size)
    {
        while (j < mat_size)
        {
            while (k < n_tetrim)
            {
                saved_sol[i][j][k] = sol[i][j][k];
                k++;
            }
            k = 0;
            j++;
        }
        j = 0;
        i++;        
    }        
}

void    ft_reset_tetrim(int mat_size, int n_tetrim, int i_tetrim, char sol[mat_size][mat_size][n_tetrim], char initial_sol[mat_size][mat_size][n_tetrim])
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (i < mat_size)
    {
        while (j < mat_size)
        {
            sol[i][j][i_tetrim] = initial_sol[i][j][i_tetrim];
            j++;
        }
        j = 0;
        i++;
    }    
}

void    unmove_tetrim(int mat_size, int n_tetrim, int i_tetrim, char sol[mat_size][mat_size][n_tetrim], char saved_sol[mat_size][mat_size][n_tetrim])
{
    int     i;
    int     j;
    int     k;

    i = 0;
    j = 0;
    k = 0;
    while (i < mat_size)
    {
        while (j < mat_size)
        {
            while (k < n_tetrim)
            {
                sol[i][j][k] = saved_sol[i][j][k];
                k++;
            }
            k = 0;
            j++;
        }
        j = 0;
        i++;        
    }     
}

int     ft_is_overlapping(int mat_size, int n_tetrim, char sol[mat_size][mat_size][n_tetrim]) // 26 ligne
{
    int     c_tetrim;
    int     i;
    int     j;
    int     k;
    
    c_tetrim = 0;
    i = 0;
    j = 0;
    k = 0;
    while (i < mat_size)
    {
        while (j < mat_size)
        {
            while (k < n_tetrim)
            {
                if (sol[i][j][k] != '.')
                    c_tetrim++;
                k++;
            }
            if (c_tetrim >= 2)
                return (1);
            c_tetrim = 0;
            k = 0;
            j++;
        }
        j = 0;
        i++;
    }
    return (0);
}

int     ft_rec_search_solution(int mat_size, int n_tetrim, char sol[mat_size][mat_size][n_tetrim], char initial_sol[mat_size][mat_size][n_tetrim])
{   
    int     i_tetrim;
    int     i;
    
    i_tetrim = n_tetrim - 1;
    while (i_tetrim >= 0)
    {        
        if (ft_move_tetrim(mat_size, n_tetrim, i_tetrim, sol))
        {           
            ft_print_all_sol(mat_size, n_tetrim, sol);
            if (!ft_is_overlapping(mat_size, n_tetrim, sol))
                return (0);     
            if (ft_rec_search_solution(mat_size, n_tetrim, sol, initial_sol))
                return (1);
            else 
                return (0);            
        }
        else 
            ft_reset_tetrim(mat_size, n_tetrim, i_tetrim, sol, initial_sol);   
        i_tetrim--;             
    }     
    return (1);
}

void    ft_resize_mat(int mat_size, int n_tetrim, char sol[mat_size][mat_size][n_tetrim])
{
    
}

void    ft_print_solu(int mat_size, int n_tetrim, char sol[mat_size][mat_size][n_tetrim])
{
    int     is_tetrim_on_case;
    int     i;
    int     j;
    int     k;

    is_tetrim_on_case = 0;
    i = 0;
    j = 0;
    k = 0;
    while (i < mat_size)
    {
        while (j < mat_size)
        {
            while (k < n_tetrim)
            {
                if (sol[i][j][k] != '.')
                {
                    write(1, &sol[i][j][k], 1);
                    is_tetrim_on_case = 1;
                }                
                k++;
            }
            if (!is_tetrim_on_case)
                write(1, ".", 1);
            is_tetrim_on_case = 0;    
            k = 0;
            j++;
        }
        write(1, "\n", 1);
        j = 0;
        i++;
    }
}

int     ft_launch_recursive(int mat_size, int n_tetrim, char sol[mat_size][mat_size][n_tetrim], char initial_sol[mat_size][mat_size][n_tetrim])
{      
   while (ft_rec_search_solution(mat_size, n_tetrim, sol, initial_sol))
   {
        write(1, "no solution\n", 12);
        ft_resize_mat(++mat_size, n_tetrim, sol);
   }
   ft_print_solu(mat_size, n_tetrim, sol);
   write(1, "solution!\n", 10);
}

int     main(void)
{
    int     mat_size;
    int     n_tetrim;
    
    mat_size = 4;
    n_tetrim = 3;
    char    saved_sol[4][4][3];
    char    sol[4][4][3] =
          {{{'A', 'B', 'C'}, {'A', 'B', 'C'}, {'.', '.', 'C'}, {'.', '.', '.'}}, 
           {{'A', '.', '.'}, {'A', 'B', 'C'}, {'.', '.', '.'}, {'.', '.', '.'}}, 
           {{'.', '.', '.'}, {'.', 'B', '.'}, {'.', '.', '.'}, {'.', '.', '.'}}, 
           {{'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'}}};
    ft_save_sol(mat_size, n_tetrim, sol, saved_sol);           
    ft_launch_recursive(mat_size, n_tetrim, sol, saved_sol);
    return (0);
}