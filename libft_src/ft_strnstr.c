#include "libft.h"

char    *ft_strnstr(const char *h, const char *n, size_t len)
{
    size_t i;
    size_t n_len;

    i = 0;
    n_len = strlen(n);

    while(h[i] && i < len)
    {
        if(!(ft_strncmp(h + i, n, n_len)))
            return((char *)(h + i));
        i++;
    }
    return(NULL);
}