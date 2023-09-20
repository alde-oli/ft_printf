#include "../libft.h"

static int  ft_nbrlen(int n)
{
    int len;

    len = 1;
    if (n < 0)
        len = 2;
    while (n / 10 != 0)
    {
        len += 1;
        n /= 10;
    }
    return (len);
}

char    *ft_itoa(int n)
{
    char    *dest;
    size_t     i;

    i = ft_nbrlen(n);
    dest = (char *) malloc(sizeof(char) * (i + 1));
    if (!dest)
        return (NULL);
    dest[i] = 0;
    if (n < 0)
        dest[0] = '-';
    if (n == 0)
      dest[i - 1] = '0';
    while (n / 10 != 0 || n % 10 != 0)
    {
        if(n < 0)
            dest[i - 1] = -1 * (n % 10) + '0';
        else
            dest[i - 1] = n % 10 + '0';
        n /= 10;
        i--;
    }
    return (dest);
}