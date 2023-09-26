#include "ft_printf.h"

static int  ft_nbrlen(int n)
{
    int len;

    len = 1;
    if (n < 0)
        len = 2;
    while (n / 10 != 0)
    {
        len += 1;
        n /= 10;
    }
    return (len);
}

static void ft_addprefix(t_bool plus, t_bool space, int n)
{
    if (n < 0)
		ft_putchar_fd('-', 1);
	else if(plus)
        ft_putchar_fd('+', 1);
    else if(space)
        ft_putchar_fd(' ', 1);
}

static int  ft_onemorezero(size_t *i)
{
    *i += 1;
    return(1);
}

int ft_insert_d(int n, t_flags *flags)
{
    size_t i;

    i = ft_nbrlen(n);
    if(flags)
    {
        if((size_t)flags->addzeros > i)
            i = flags->addzeros;
        if((size_t)flags->addzeros == i && n < 0)
            flags->addzeros += ft_onemorezero(&i);
        if(flags->addspaces > 0)
            i = ft_putspaces(flags->addspaces, i + flags->space + flags->plus) - (flags->space + flags->plus);
        ft_addprefix(flags->plus, flags->space, n);
        if(flags->addzeros > ft_nbrlen(n))
            ft_putzeros(flags->addzeros, ft_nbrlen(n));
        ft_putnbr_fd(n, 1);
        if(flags->addspaces < 0)
            i = ft_putspaces(-1 * flags->addspaces, i + flags->space + flags->plus) - (flags->space + flags->plus);
        if((flags->plus || flags->space))
            i++;
    }
    else
        ft_putnbr_fd(n, 1);
    return(i);
}