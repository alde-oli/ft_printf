#include "ft_printf.h"

static int  ft_Xnbrlen(unsigned int n)
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

static char    *ft_Xtoa(unsigned int n)
{
    char                *nx_str;
    size_t              i;
    char                *hexa;

    i = ft_Xnbrlen(n);
    hexa = ft_strdup("0123456789ABCDEF");
    nx_str = ft_calloc(i + 1, sizeof(char));
    nx_str[i] = 0;
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

int ft_insert_xup(unsigned int u)
{
char *uX_str;
    uX_str = ft_uitoa(u);
    ft_putstr_fd(uX_str, 0);
    if(uX_str)
        free(uX_str);
    return(ft_Xnbrlen(u));
}