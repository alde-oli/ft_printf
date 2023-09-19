#include "ft_printf.h"
#include <stdint.h>


char    *ft_itoa_hex(void *p)
{
    char       *p_str;
    uintptr_t  p_cpy;
    size_t     i;
    char       *hexa;

    i = 13;
    hexa = ft_strdup("0123456789abcdef");
    p_cpy = (uintptr_t)p;
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

    if(new_fs = ft_calloc(ft_strlen((const char *)fs), sizeof(char)))
    {
        to_insert = ft_itoa_hex(va_arg(args, void *));
        ft_strlcpy(new_fs, fs, *i - 1);
        ft_strlcpy(&new_fs[*i], to_insert, 14);
        ft_strlcpy(&new_fs[*i + 14], &fs[*i + 2], (ft_strlen(fs) - *i - 1));
        free(fs);
        free(to_insert);
        fs = new_fs;
        *i += 14;
    }
}