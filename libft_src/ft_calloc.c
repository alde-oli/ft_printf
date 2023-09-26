#include "libft.h"

void *ft_calloc(size_t n, size_t size)
{
    void    *a;

    a = malloc(size * n);
    if(!a)
        return(NULL);
    ft_bzero(a, n * size);
    return(a);
}