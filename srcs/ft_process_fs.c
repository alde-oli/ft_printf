#include "ft_printf.h"

int ft_process_fs(const char *fs, size_t *i, va_list args)
{
    t_flags *flags;
    if(fs && i)
    {
        if(fs[*i] == '%')
        {
            *i += 1;
            flags = ft_check_for_flags(fs, i);
            if(fs[*i] == 'c')
                return(ft_insert_c(va_arg(args, int), flags));
            else if(fs[*i] == 's')
                return(ft_insert_s(va_arg(args, char *), flags));
            else if(fs[*i] == 'p')
                return(ft_insert_p(va_arg(args, void *), flags));
            else if(fs[*i] == 'd')
                return(ft_insert_d(va_arg(args, int), flags));
            else if(fs[*i] == 'i')
                return(ft_insert_d(va_arg(args, int), flags));
            else if(fs[*i] == 'u')
                return(ft_insert_u(va_arg(args, unsigned int), flags));
            else if(fs[*i] == 'x')
                return(ft_insert_x(va_arg(args, unsigned int), flags));
            else if(fs[*i] == 'X')
                return(ft_insert_xup(va_arg(args, unsigned int), flags));
            else if(fs[*i] == '%')
                return(ft_insert_c('%', NULL));
            else
                return(-1);
        }
        ft_putchar_fd(fs[*i], 1);
        return(1);
    }
    return(-1);
}