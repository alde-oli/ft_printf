#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft_src/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

int ft_printf(const char *fs, ...);
int ft_process_fs(char *fs, size_t *i, va_list args);
int ft_insert_c(int c);
int ft_insert_s(char *s);
int ft_insert_p(void *p);
int ft_insert_d(int n);
int ft_insert_u(unsigned int u);
int ft_insert_x(unsigned int u);
int ft_insert_xup(unsigned int u);

#endif