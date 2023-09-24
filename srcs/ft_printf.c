#include "ft_printf.h"

int    ft_printf(const char *fs, ...)
{
    va_list args;
    size_t  i;
    size_t  printed;
    size_t  temp;

    i = 0;
    printed = 0;
    if(fs)
    {
        va_start(args, fs);
        while(fs[i])
        {
            temp = ft_process_fs(fs, &i, args);
            if(temp < 0)
                return(temp);
            printed += temp;
            i++;
        }
        va_end(args);
    }
    return(printed);
}