#include "ft_printf.h"

static char    *ft_ptoa(void *p)
{
    char                *p_str;
    unsigned long long  p_cpy;
    size_t              i;
    char                *hexa;

    i = 13;
    hexa = ft_strdup("0123456789abcdef");
    p_cpy = (unsigned long long)p;
    p_str = ft_strdup("0x000000000000");
    while (p_cpy > 0 && i > 1)
    {
        p_str[i] = hexa[p_cpy % 16];
        p_cpy /= 16;
        i--;
    }
    free(hexa);
    return(p_str);
}

int ft_insert_p(void *p)
{
    char *p_str;
    p_str = ft_ptoa(p);
    ft_putstr_fd(p_str, 0);
    if(p_str)
        free(p_str);
    return(14);
}