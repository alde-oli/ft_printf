#include "ft_printf.h"

char    *ft_insert_c(char *fs, size_t *i, va_list args)
{
    char    *new_fs;
    char    to_insert;

    new_fs = ft_calloc(ft_strlen((const char *)fs) - 1, sizeof(char));
    if(new_fs)
    {
        to_insert = va_arg(args, int);
        ft_strlcpy(new_fs, fs, *i - 1);
        new_fs[*i] = (char)to_insert;
        ft_strlcpy(&new_fs[*i + 1], &fs[*i + 2], (ft_strlen(fs) - *i - 1));
        free(fs);
        *i += 1;
        return(new_fs);
    }
    return(NULL);
}