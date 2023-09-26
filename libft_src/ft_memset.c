#include "libft.h"

void    *ft_memset(void *s, int c, size_t len)
{
    size_t i;

    if(s)
    {
        i = 0;
        while(i < len)
        {
            ((unsigned char *)s)[i] = (unsigned char)c;
            i++;
        }
    }
    return(s);
}