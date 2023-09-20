#include "../libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;
    unsigned char uc;

    i = 0;
    uc = (unsigned char)c;
    while (i < n)
    {
        if (((unsigned char *)s)[i] == uc)
            return ((unsigned char *)s + i);
        i++;
    }
    return (NULL);
}