#include "ft_printf.h"

int ft_insert_s(char *s, t_flags *flags)
{
    size_t  i;
    char    *new_s;

    new_s = ft_strdup((const char *)s);
    i = ft_strlen(new_s);
    if(flags)
    {
        if((flags->addzeros) && (flags->addzeros < i))
        {
            i = flags->addzeros;
            new_s[i] = '\0';
        }
        if(flags->addspaces > 0)
            i = ft_putspaces(flags->addspaces, i);
        ft_putstr_fd(new_s, 0);
        if(flags->addspaces < 0)
            i = ft_putspaces(-1 * (flags->addspaces), i);
    }
    else
        ft_putstr_fd(s, 0);
    free(new_s);
    return(i);
}