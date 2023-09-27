#include "ft_printf.h"

static int  ft_unbrlen(unsigned int n)
{
    size_t len;

    len = 1;
    while(n / 10 != 0)
    {
        len += 1;
        n /= 10;
    }
    return(len);
}

static void	ft_putu(unsigned int nb)
{
	char	digit;

	digit = nb % 10 + 48;
	nb /= 10;
	if(nb != 0)
		ft_putu(nb);
	write(1, &digit, 1);
}

int ft_insert_u(unsigned int u, t_flags *flags)
{
    size_t i;
    i = ft_unbrlen(u);
    if(flags)
    {
        if((size_t)flags->addzeros > i)
            i = flags->addzeros;
        if(flags->addspaces > 0)
            i = ft_putspaces(flags->addspaces, i);
        if(flags->addzeros > ft_unbrlen(u))
            ft_putzeros(flags->addzeros, ft_unbrlen(u));
        ft_putu(u);
        if(flags->addspaces < 0)
            i = ft_putspaces(-1 * (flags->addspaces), i);
    }
    else
        ft_putu(u);
    return(i);
}