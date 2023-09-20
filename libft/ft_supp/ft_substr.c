# include "../libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t  i;
    char    *dest;

    if(!s)
        return(NULL);
    i = 0;
    if((start + len - 1) > (size_t)ft_strlen((char *)s))
        len = ft_strlen((char *)s);
    dest = (char *) malloc(sizeof(char) * len + 1);
    if (!dest)
        return(NULL);
    while (i < len)
    {
        dest[i] = s[start + i];
        i++;
    }
    dest[i] = 0;
    return (dest);
}
