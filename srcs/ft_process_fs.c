#include "ft_printf.h"

char    *ft_process_fs(char *fs, size_t *i, va_list args)
{
    if(fs && i)
    {
        if(fs[*i] == '%')
        {
            if(fs[*i + 1] == 'c')
                fs = ft_insert_c(fs, i, args);
            else if(fs[*i + 1] == 's')
                fs = ft_insert_s(fs, i, args);
            else if(fs[*i + 1] == 'p')
                fs = ft_insert_p(fs, i, args);
            else if(fs[*i + 1] == 'd')
                fs = ft_insert_d(fs, i, args);
            else if(fs[*i + 1] == 'i')
                fs = ft_insert_d(fs, i, args);
            else if(fs[*i + 1] == 'u')
                fs = ft_insert_u(fs, i, args);
            else if(fs[*i + 1] == 'x')
                fs = ft_insert_x(fs, i, args);
            else if(fs[*i + 1] == 'X')
                fs = ft_insert_xup(fs, i, args);
            else if(fs[*i + 1] == '%')
                fs = ft_insert_percent(fs, i);
        }
        return(fs);
    }
    return(NULL);
}