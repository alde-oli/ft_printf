#include "ft_printf.h"

int ft_insert_c(int c)
{
    ft_putchar_fd(c, 0);
    return(1);
}