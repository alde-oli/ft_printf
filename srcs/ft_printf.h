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
void    ft_insert_c(char *fs, size_t *i, va_list args);
void    ft_insert_s(char *fs, size_t *i, va_list args);
void    ft_insert_p(char *fs, size_t *i, va_list args);
void    ft_insert_d(char *fs, size_t *i, va_list args);
void    ft_insert_u(char *fs, size_t *i, va_list args);
void    ft_insert_x(char *fs, size_t *i, va_list args);
void    ft_insert_xup(char *fs, size_t *i, va_list args);
void    ft_insert_percent(char *fs, size_t *i);

#endif