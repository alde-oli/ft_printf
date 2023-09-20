#include "../libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t i;

    if (dst == NULL || src == NULL)
        return 0;
    i = 0;
    while (i + 1 < size && src[i])
	{
        dst[i] = src[i];
        i++;
    }
    if (size > 0)
        dst[i] = 0;
    while (src[i]) 
        i++;
    return (i);
}
