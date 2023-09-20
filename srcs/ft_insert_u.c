#include "ft_printf.h"

static int  ft_nbrlen(unsigned int n)
{
    size_t len;

    len = 1;
    while (n / 10 != 0)
    {
        len += 1;
        n /= 10;
    }
    return (len);
}

static char *ft_uitoa(unsigned int n)
{
    char    *dest;
    size_t     i;

    i = ft_nbrlen(n);
    dest = (char *) malloc(sizeof(char) * (i + 1));
    if (!dest)
        return (NULL);
    dest[i] = 0;
    if (n == 0)
      dest[i - 1] = '0';
    while (n / 10 != 0 || n % 10 != 0)
    {
        dest[i - 1] = n % 10 + '0';
        n /= 10;
        i--;
    }
    return (dest);
}

int ft_insert_u(unsigned int u)
{
    char *u_str;
    u_str = ft_uitoa(u);
    ft_putstr_fd(u_str, 0);
    if(u_str)
        free(u_str);
    return(ft_nbrlen(u));
}