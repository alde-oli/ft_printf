#include "ft_printf.h"

void    ft_process_fs(char *fs, size_t *i, va_list args)
{
    if(fs && i)
    {
        if(fs[*i] == '%')
        {
            if(fs[*i + 1] == 'c')
                ft_insert_c(fs, i, args);
            else if(fs[*i + 1] == 's')
                ft_insert_s(fs, i, args);
            else if(fs[*i + 1] == 'p')
                ft_insert_p(fs, i, args);
            else if(fs[*i + 1] == 'd')
                ft_insert_d(fs, i, args);
            else if(fs[*i + 1] == 'i')
                ft_insert_i(fs, i, args);
            else if(fs[*i + 1] == 'u')
                ft_insert_u(fs, i, args);
            else if(fs[*i + 1] == 'x')
                ft_insert_x(fs, i, args);
            else if(fs[*i + 1] == 'X')
                ft_insert_X(fs, i, args);
            else if(fs[*i + 1] == '%')
                ft_insert_percent(fs, i, args);
        }
    }
}