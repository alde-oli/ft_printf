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

    i = ft_xnbrlen(n);
    hexa = ft_strdup("0123456789ABCDEF");
    nx_str = ft_calloc(nx_str + 1, sizeof(char));
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

void    ft_insert_xup(char *fs, size_t *i, va_list args)
{
    char    *new_fs;
    char    *to_insert;

    if(new_fs = ft_calloc(ft_strlen((const char *)fs), sizeof(char)))
    {
        to_insert = ft_Xtoa(va_arg(args, unsigned int));
        ft_strlcpy(new_fs, fs, *i - 1);
        ft_strlcpy(&new_fs[*i], to_insert, 14);
        ft_strlcpy(&new_fs[*i + 14], &fs[*i + 2], (ft_strlen(fs) - *i - 1));
        free(fs);
        free(to_insert);
        fs = new_fs;
        *i += 14;
    }
}