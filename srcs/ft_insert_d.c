#include "ft_printf.h"

void    ft_insert_d(char *fs, size_t *i, va_list args)
{
    char    *new_fs;
    char    *to_insert;

    if(new_fs = ft_calloc(ft_strlen((const char *)fs), sizeof(char)))
    {
        to_insert = ft_itoa(va_arg(args, int));
        ft_strlcpy(new_fs, fs, *i - 1);
        ft_strlcpy(&new_fs[*i], to_insert, 14);
        ft_strlcpy(&new_fs[*i + 14], &fs[*i + 2], (ft_strlen(fs) - *i - 1));
        free(fs);
        free(to_insert);
        fs = new_fs;
        *i += 14;
    }
}