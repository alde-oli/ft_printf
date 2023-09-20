#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

int     ft_printf(const char *fs, ...);
void    ft_process_fs(char *fs, size_t *i, va_list args);
void    ft_insert_c(fs, i, args);
void    ft_insert_s(fs, i, args);
void    ft_insert_p(fs, i, args);
void    ft_insert_d(fs, i, args);
void    ft_insert_i(fs, i, args);
void    ft_insert_u(fs, i, args);
void    ft_insert_x(fs, i, args);
void    ft_insert_xup(fs, i, args);
void    ft_insert_percent(fs, i);

#endif