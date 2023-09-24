#include "ft_printf.h"

static t_flags   *ft_init_flags()
{
    t_flags *flags;
    flags = (t_flags *) malloc(sizeof(t_flags));
    flags->addspaces = 0;
    flags->addzeros = 0;
    flags->hash = FALSE;
    flags->space = FALSE;
    flags->plus = FALSE;
    return(flags);
}

static t_flags *ft_check_hsp(char c, size_t *i, t_flags *flags)
{
    if(c == '#')
    {
        flags->hash = TRUE;
        *i += 1;
    }
    else if(c == ' ')
    {
        flags->space = TRUE;
        *i += 1;
    }
    else if(c == '+')
    {
        flags->plus = TRUE;
        *i += 1;
    }
    return(flags);
}

static int ft_check_addspaces(const char *fs, size_t *i)
{
    int n;

    n = 0;
    if(fs[*i] == '-')
    {
        if(isdigit(fs[*i + 1]))
        {
            n = -1 * (fs[*i + 1] - '0');
            *i += 2;
        }
    }
    while(isdigit(fs[*i]))
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
    while(isdigit(fs[*i]))
    {
        if(n < 0)
            n = n * 10 - (fs[*i] - '0');
        else
            n = n * 10 + (fs[*i] - '0');
        *i += 1;
    }
    return(n);
}

t_flags *ft_check_for_flags(const char *fs, size_t *i)
{
    t_flags *flags;
    size_t  i_copy;

    i_copy = *i;
    flags = ft_init_flags();
    flags = ft_check_hsp(fs[*i], i, flags);
    flags->addspaces = ft_check_addspaces(fs, i);
    flags->addzeros = ft_check_addzeros(fs, i);
    if(!(ft_strchr("cspdiuxXù%%", fs[*i])))
        *i = i_copy;
    if(!(flags->addspaces || flags->addzeros || flags->hash || flags->plus || flags->space))
        return(NULL);
    return(flags);
}