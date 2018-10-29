#include "ft_printf.h"

char         *adding_space(t_flags *flags, char *str)
{
    char    *tmp;

    if (flags->conversion != 'd' && flags->conversion != 'i' && \
        flags->conversion != 'D')
    {
        tmp = ft_strdup(str);
        return (tmp);
    }
    tmp = ft_strnew(1);
    if (flags->minus == 0)
        tmp = ft_update(tmp, ft_strjoin(" ", str));
    return (tmp);
}