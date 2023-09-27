#include "ft_printf.h"

static int  ft_xnbrlen(unsigned long long n)
{
    int len;

    len = 1;
    while(n / 16 != 0)
    {
        len += 1;
        n /= 16;
    }
    return(len);
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
        ft_putstr_fd("0x", 1);
        ft_puthexa(p, &hexa);
    }
    free(hexa);
}

int ft_insert_p(void *p, t_flags *flags)
{
    size_t  i;

    i = 2 + ft_xnbrlen((unsigned long long)p);
    if(!p)
        i = 6;
    if(flags)
    {
        if(flags->addspaces > 0)
            i = ft_putspaces(flags->addspaces, i);
        ft_putptr((unsigned long long)p);
        if(flags->addspaces < 0)
            i = ft_putspaces(-1 * flags->addspaces, i);
    }
    else
        ft_putptr((unsigned long long)p);
    return(i);
}