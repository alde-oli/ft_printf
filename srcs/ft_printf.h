#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define TRUE 1
# define FALSE 0

typedef char    t_bool;

typedef struct  s_flags
{
    int     addspaces;
    int     addzeros;
    t_bool  hash;
    t_bool  space;
    t_bool  plus;
}   t_flags;

# include "../libft_src/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

int     ft_printf(const char *fs, ...);
int     ft_process_fs(const char *fs, size_t *i, va_list args);
t_flags *ft_check_for_flags(const char *fs, size_t *i);
int     ft_insert_c(int c, t_flags *flags);
int     ft_insert_s(char *s, t_flags *flags);
int     ft_insert_p(void *p, t_flags *flags);
int     ft_insert_d(int n, t_flags *flags);
int     ft_insert_u(unsigned int u, t_flags *flags);
int     ft_insert_x(unsigned int u, t_flags *flags);
int     ft_insert_xup(unsigned int u, t_flags *flags);
int     ft_putspaces(int n, size_t i);
void    ft_putzeros(int n, size_t i);

#endif