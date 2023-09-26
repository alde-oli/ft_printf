#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t len)
{
    size_t   i;

    if(dest && src)
    {
        i = 0;
        while(i < len)
        {
            ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
            i++;
        }
    }
    return(dest);
}