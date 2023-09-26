# include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t  i;
    char    *dest;

    if(!s)
        return(NULL);
    i = 0;
    if((start + len - 1) > ft_strlen((char *)s))
        len = ft_strlen(s);
    dest = ft_calloc(len + 1, sizeof(char));
    if(!dest)
        return(NULL);
    while(i < len)
    {
        dest[i] = s[start + i];
        i++;
    }
    return(dest);
}
