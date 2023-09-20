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

void    ft_insert_p(char *fs, size_t *i, va_list args)
{
    char    *new_fs;
    char    *to_insert;
    size_t  insert_len;

    to_insert = ft_ptoa(va_arg(args, void *));
    insert_len = ft_strlen((const char *)to_insert);
    new_fs = ft_calloc(ft_strlen((const char *)fs) + insert_len - 1, sizeof(char));
    if(new_fs && to_insert)
    {
        ft_strlcpy(new_fs, fs, *i - 1);
        ft_strlcpy(&new_fs[*i], to_insert, insert_len);
        ft_strlcpy(&new_fs[*i + insert_len], &fs[*i + 2], (ft_strlen(fs) - *i - 1));
        free(fs);
        free(to_insert);
        fs = new_fs;
        *i += 14;
    }
}