#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    int i;
    char *new_s;

    i = 0;
    if(!s || !f)
        return(NULL);
    if(!(new_s = ft_calloc((ft_strlen(s) + 1), sizeof(char))))
        return(NULL);
    while(s[i])
    {
        new_s[i] = f(i, s[i]);
        i++;
    }
    return(new_s);
}
