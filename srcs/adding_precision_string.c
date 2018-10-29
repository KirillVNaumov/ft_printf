#include "ft_printf.h"

char        *adding_precision_string(t_flags *flags, char *str)
{
    char        *tmp;

    if (flags->conversion != 'S' && flags->conversion != 's')
    {
        tmp = ft_strdup(str);
        return (tmp);
    }
    if (flags->precision == 0)
    {
        tmp = ft_strnew(1);
        return (tmp);
    }
    if (flags->precision >= (int)ft_strlen(str))
    {
        tmp = ft_strdup(str);
        return (tmp);
    }
    str = ft_update(str, ft_strsub(str, 0, flags->precision));
    return (str);
}