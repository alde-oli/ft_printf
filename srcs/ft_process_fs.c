#include "ft_printf.h"

int ft_process_fs(const char *fs, size_t *i, va_list args)
{
    //flags_t *flags;
    if(fs && i)
    {
        if(fs[*i] == '%')
        {
            i++;
            //flags = ft_check_for_flags(char *fs, size_t *i)
            if(fs[*i] == 'c')
                return(ft_insert_c(va_arg(args, int)));
            else if(fs[*i] == 's')
                return(ft_insert_s(va_arg(args, char *)));
            else if(fs[*i] == 'p')
                return(ft_insert_p(va_arg(args, void *)));
            else if(fs[*i] == 'd')
                return(ft_insert_d(va_arg(args, int)));
            else if(fs[*i] == 'i')
                return(ft_insert_d(va_arg(args, int)));
            else if(fs[*i] == 'u')
                return(ft_insert_u(va_arg(args, unsigned int)));
            else if(fs[*i] == 'x')
                return(ft_insert_x(va_arg(args, unsigned int)));
            else if(fs[*i] == 'X')
                return(ft_insert_xup(va_arg(args, unsigned int)));
            else if(fs[*i] == '%')
                return(ft_insert_c('%'));
        }
        ft_putchar_fd(fs[*i], 0);
        return(1);
    }
    return(-1);
}