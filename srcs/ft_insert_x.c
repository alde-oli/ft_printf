#include "ft_printf.h"

static int  ft_xnbrlen(unsigned int n)
{
    int len;

    len = 1;
    while (n / 16 != 0)
    {
        len += 1;
        n /= 16;
    }
    return (len);
}

static void	ft_puthexa(unsigned long long p, char **hexa)
{
	char    digit;

	digit = (*hexa)[p % 16];
	p /= 16;
	if (p != 0)
		ft_puthexa(p, hexa);
	write(1, &digit, 1);
}

static void ft_manage_altzero(t_flags *flags)
{
    if(flags->altzero && flags->addzeros < flags->addspaces)
    {
        flags->addzeros = flags->addspaces;
        flags->addspaces = 0;
    }
}

int ft_insert_x(unsigned int u, t_flags *flags)
{
    size_t  i;
    char *hexa;

    hexa = ft_strdup("0123456789abcdef");
    i = ft_xnbrlen(u);
    if(flags)
    {
        ft_manage_altzero(flags);
        if((size_t)flags->addzeros > i)
            i = flags->addzeros;
        if(flags->hash)
            i += 2;
        if(flags->addspaces > 0)
            i = ft_putspaces(flags->addspaces, i);
        if(flags->hash)
            ft_putstr_fd("0x", 1);
        if(flags->addzeros > ft_xnbrlen(u))
            ft_putzeros(flags->addzeros, ft_xnbrlen(u));
        ft_puthexa(u, &hexa);
        if(flags->addspaces < 0)
            i = ft_putspaces(-1 * (flags->addspaces), i);
    }
    else
        ft_puthexa(u, &hexa);
    free(hexa);
    return(i);
}