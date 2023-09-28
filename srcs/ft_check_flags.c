#include "ft_printf.h"

static t_flags   *ft_init_flags()
{
    t_flags *flags;
    flags = (t_flags *) malloc(sizeof(t_flags));
    flags->addspaces = 0;
    flags->addzeros = 0;
    flags->altzero = FALSE;
    flags->hash = FALSE;
    flags->space = FALSE;
    flags->plus = FALSE;
    return(flags);
}

static t_flags *ft_check_hsp(const char *fs, size_t *i, t_flags *flags)
{
    while(fs[*i] == '#' || fs[*i] == ' ' || fs[*i] == '+')
    {
        if(fs[*i] == '#')
        {
            flags->hash = TRUE;
            *i += 1;
        }
        else if(fs[*i] == ' ')
        {
            flags->space = TRUE;
            *i += 1;
        }
        else if(fs[*i] == '+')
        {
            flags->plus = TRUE;
            *i += 1;
        }
    }
    return(flags);
}

static int ft_check_addspaces(const char *fs, size_t *i, t_flags *flags)
{
    int n;

    n = 0;
    if(fs[*i] == '-' && ft_isdigit(fs[*i + 1]))
    {
        n = -1 * (fs[*i + 1] - '0');
        *i += 2;
    }
    else if(fs[*i] == '0')
    {
        flags->altzero = TRUE;
        *i += 1;
    }
    while(ft_isdigit(fs[*i]))
    {
        if(n < 0)
            n = n * 10 - (fs[*i] - '0');
        else
            n = n * 10 + (fs[*i] - '0');
        *i += 1;
    }
    return(n);
}

static int  ft_check_addzeros(const char *fs, size_t *i)
{
    int n;

    n = 0;
    if(fs[*i] == '.')
        *i += 1;
    while(ft_isdigit(fs[*i]))
    {
        if(n < 0)
            n = n * 10 - (fs[*i] - '0');
        else
            n = n * 10 + (fs[*i] - '0');
        *i += 1;
    }
    return(n);
}

t_flags *ft_check_flags(const char *fs, size_t *i)
{
    t_flags *flags;
    size_t  i_copy;

    i_copy = *i;
    flags = ft_init_flags();
    flags = ft_check_hsp(fs, i, flags);
    flags->addspaces = ft_check_addspaces(fs, i, flags);
    flags->addzeros = ft_check_addzeros(fs, i);
    if(!(ft_strchr("cspdiuxXù%%", fs[*i])))
        *i = i_copy;
    if(!(flags->addspaces || flags->addzeros || flags->hash || flags->plus || flags->space))
        return(NULL);
    return(flags);
}