#include "ft_printf.h"

static int  ft_pnbrlen(void *p)
{
    int                 len;
    unsigned long long  u;

    if(!p)
        return(6);
    u = (unsigned long long)p;
    len = 1;
    while(u / 16 != 0)
    {
        len += 1;
        u /= 16;
    }
    return(len + 2);
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
static void ft_putptr(unsigned long long p)
{
    char *hexa;

    if(!p)
        ft_putstr_fd("(null)", 1);
    else
    {
        hexa = ft_strdup("0123456789abcdef");
        ft_puthexa(p, &hexa);
    }
    free(hexa);
}

static void ft_manage_altzero(t_flags *flags)
{
    if(flags->altzero && flags->addzeros + 1 < flags->addspaces)
    {
        flags->addzeros = flags->addspaces - 2;
        flags->addspaces = 0;
    }
}

int ft_insert_p(void *p, t_flags *flags)
{
    size_t  i;

    i = ft_pnbrlen(p);
    if(flags)
    {
        ft_manage_altzero(flags);
        if(p && (size_t)flags->addzeros > i - 2)
            i = flags->addzeros + 2;
        if(flags->addspaces > 0 && flags->addzeros + 1 < flags->addspaces)
            i = ft_putspaces(flags->addspaces, i);
        if(p)
            ft_putstr_fd("0x", 1);
        if(p && flags->addzeros > 12)
            ft_putzeros(flags->addzeros, 12);
        ft_putptr((unsigned long long)p);
        if(flags->addspaces < 0 && flags->addzeros + 1 < -flags->addspaces)
            i = ft_putspaces(-1 * (flags->addspaces), i);
    }
    else
    {
        if(p)
            ft_putstr_fd("0x", 1);
        ft_putptr((unsigned long long)p);
    }
    return(i);
}