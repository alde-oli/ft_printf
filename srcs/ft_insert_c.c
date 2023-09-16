#include "ft_printf.h"

void    ft_insert_c(char *fs, size_t *i, va_list args)
{
    char    *new_fs;
    char    to_insert;

    if(new_fs = ft_calloc(ft_strlen((const char *)fs, sizeof(char))))
    {
        to_insert = va_arg(args, char);
        ft_strlcpy(new_fs, fs, *i - 1);
        new_fs[*i] = to_insert;
        ft_strlcpy(&new_fs[*i + 1], &fs[*i + 2], (ft_strlen(fs) - *i - 1));
        free(fs);
        fs = new_fs;
        *i += 1;
    }
}