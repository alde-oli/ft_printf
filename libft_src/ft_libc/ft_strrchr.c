#include "../libft.h"

char    *ft_strrchr(const char *s, int c)
{
    int i;

    i = ft_strlen((char *)s) - 1;
    while (s[i] != c && i >= 0)
        i--;
    if (s[i] == c)
        return ((char *)(s + i));
    return (NULL);
}