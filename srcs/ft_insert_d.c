#include "ft_printf.h"

void    ft_insert_d(char *fs, size_t *i, va_list args)
{
    char    *new_fs;
    char    *to_insert;
    size_t  insert_len;

    to_insert = ft_itoa(va_arg(args, int));
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