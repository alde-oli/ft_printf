#include "ft_printf.h"

void    ft_insert_percent(char **fs, size_t *i)
{
    char    *new_fs;
    char    to_insert;

    new_fs = ft_calloc(ft_strlen((const char *)*fs), sizeof(char));
    if(new_fs)
    {
        to_insert = '%';
        ft_strlcpy(new_fs, *fs, *i - 1);
        new_fs[*i] = to_insert;
        ft_strlcpy(&new_fs[*i + 1], &(*fs)[*i + 2], (ft_strlen(*fs) - *i - 1));
        free(*fs);
        *fs = new_fs;
        *i += 1;
    }
}