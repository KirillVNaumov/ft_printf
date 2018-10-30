#include "ft_printf.h"

char        *adding_precision_string(t_flags *flags, char *str)
{
    char        *tmp;

    tmp = ft_strdup(str);
    if (flags->conversion != 'S' && flags->conversion != 's')
        return (tmp);
    if (flags->precision == 0)
    {
        tmp = ft_strnew(1);
        return (tmp);
    }
    if (flags->precision >= (int)ft_strlen(str))
        return (tmp);
    tmp = ft_update(tmp, ft_strsub(str, 0, flags->precision));
    return (tmp);
}