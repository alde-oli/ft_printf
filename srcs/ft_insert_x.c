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

char    *ft_insert_x(char *fs, size_t *i, va_list args)
{
    char    *new_fs;
    char    *to_insert;
    size_t  insert_len;

    to_insert = ft_xtoa(va_arg(args, unsigned int));
    insert_len = ft_strlen((const char *)to_insert);
    new_fs = ft_calloc(ft_strlen((const char *)fs) + insert_len - 1, sizeof(char));
    if(new_fs && to_insert)
    {
        ft_strlcpy(new_fs, fs, *i - 1);
        ft_strlcpy(&new_fs[*i], to_insert, insert_len);
        ft_strlcpy(&new_fs[*i + insert_len], &fs[*i + 2], (ft_strlen(fs) - *i - 1));
        free(fs);
        free(to_insert);
        *i += 14;
        return(new_fs);
    }
    return(NULL);
}