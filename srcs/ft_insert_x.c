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

static char    *ft_xtoa(unsigned int n)
{
    char                *nx_str;
    size_t              i;
    char                *hexa;

    i = ft_xnbrlen(n);
    hexa = ft_strdup("0123456789abcdef");
    nx_str = ft_calloc(i + 1, sizeof(char));
    i--;
    while (n / 16 != 0 || n % 16 != 0)
    {
        nx_str[i] = hexa[n % 16];
        n /= 16;
        i--;
    }
    free(hexa);
    return(nx_str);
}

int ft_insert_x(unsigned int u)
{
    char *ux_str;
    ux_str = ft_xtoa(u);
    ft_putstr_fd(ux_str, 0);
    if(ux_str)
        free(ux_str);
    return(ft_xnbrlen);
}