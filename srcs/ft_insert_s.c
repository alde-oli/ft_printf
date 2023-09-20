#include "ft_printf.h"

int ft_insert_s(char *s)
{
    ft_putstr_fd(s, 0);
    return(ft_strlen(s));
}