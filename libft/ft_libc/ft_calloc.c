#include "../libft.h"

void *ft_calloc(size_t n, size_t size)
{
    unsigned char   *a;

    a = malloc(size * n);
    if(!a)
        return (NULL);
    ft_bzero(a, n * size);
    return ((void *)a);
}