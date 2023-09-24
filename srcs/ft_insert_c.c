#include "ft_printf.h"

int ft_insert_c(int c, t_flags *flags)
{
    size_t i;

    i = 1;
    if(flags)
    {
        if(flags->addspaces > 0)
            i = ft_putspaces(flags->addspaces, i);
        ft_putchar_fd(c, 0);
        if(flags->addspaces < 0)
            i = ft_putspaces(-1 * (flags->addspaces), i);
    }
    else
        ft_putchar_fd(c, 0);
    return(i);
}