#include "ft_printf.h"

static int  ft_nbrlen(unsigned int n)
{
    size_t len;

    len = 1;
    while (n / 10 != 0)
    {
        len += 1;
        n /= 10;
    }
    return (len);
}

static char *ft_uitoa(unsigned int n)
{
    char    *dest;
    size_t     i;

    i = ft_nbrlen(n);
    dest = (char *) malloc(sizeof(char) * (i + 1));
    if (!dest)
        return (NULL);
    dest[i] = 0;
    if (n == 0)
      dest[i - 1] = '0';
    while (n / 10 != 0 || n % 10 != 0)
    {
        dest[i - 1] = n % 10 + '0';
        n /= 10;
        i--;
    }
    return (dest);
}

void    ft_insert_d(char *fs, size_t *i, va_list args)
{
    char    *new_fs;
    char    *to_insert;
    size_t  insert_len;

    to_insert = ft_uitoa(va_arg(args, unsigned int));
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