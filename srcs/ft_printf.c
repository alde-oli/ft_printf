#include "ft_printf.h"

int    ft_printf(const char *fs, ...)
{
    va_list args;
    size_t  i;
    size_t  printed;

    i = 0;
    printed = 0;
    if(fs)
    {
        va_start(args, fs);
        while(fs[i])
        {
            printed += ft_process_fs(fs, &i, args);
            i++;
        }
        va_end(args);
    }
    return(printed);

}