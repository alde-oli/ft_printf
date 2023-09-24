#include "ft_printf.h"

void  ft_putzeros(int n, size_t i)
{
    while((size_t)n > i)
    {
        ft_putchar_fd('0', 0);
        n--;
    }
}