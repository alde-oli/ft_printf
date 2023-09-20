#include "../libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *dest;
    int     i;
    int     j;

    if(!s1 || !s2)
        return(NULL);
    i = 0;
    j = 0;
    dest = (char *) malloc(sizeof(char) * (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
    if (!dest)
        return (NULL);
    while (s1[i])
    {
        dest[i] = s1[i];
        i++;
    }
    while(s2[j])
    {
        dest[i + j] = s2[j];
        j++;
    }
    dest[i + j] = 0;
    return (dest);
}