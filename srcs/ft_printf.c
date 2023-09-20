#include "ft_printf.h">

int    ft_printf(const char *fs, ...)
{
    va_list args;
    char    *fs_cpy;
    size_t  i;
    i = 0;
    if(fs)
    {
        fs_cpy = ft_strdup(fs);
        va_start(args, fs);
        while(fs[i])
        {
            ft_process_fs(fs_cpy, &i, args);
            i++;
        }
        va_end(args);
    }
    if(fs_cpy)
    {
        ft_putstr(fs_cpy, 0);
        free(fs_cpy);
        return(i);
    }
    return(-42);
}