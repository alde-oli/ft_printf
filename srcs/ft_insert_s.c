#include "ft_printf.h"

void    ft_insert_s(char *fs, size_t *i, va_list args)
{
    char    *new_fs;
    char    *to_insert;
    size_t  insert_len;

    if(new_fs = ft_calloc(ft_strlen((const char *)fs), sizeof(char)))
    {
        to_insert = va_arg(args, char *);
        insert_len = ft_strlen(to_insert);
        ft_strlcpy(new_fs, fs, *i - 1);
        ft_strlcpy(&new_fs[*i], to_insert, insert_len);
        ft_strlcpy(&new_fs[*i + insert_len], &fs[*i + 2], (ft_strlen(fs) - *i - 1));
        free(fs);
        fs = new_fs;
        *i += insert_len;
    }
}