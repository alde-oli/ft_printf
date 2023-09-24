#include "ft_printf.h"

int  ft_putspaces(int n, size_t i)
{
    size_t j;

    j = (size_t)n;
    while((size_t)n > i)
    {
        ft_putchar_fd(' ', 0);
        n--;
    }
    return(j);
}