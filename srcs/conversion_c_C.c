#include "ft_printf.h"

char    *conversion_c_C(va_list *arg, t_flags *flags)
{
    char    *str;
    int    tmp;

    tmp = va_arg(*arg, int);
    if (!ft_strcmp(flags->format, "l"))
        flags->conversion = 'C';
    if (flags->conversion == 'C')
        if (tmp > 127)
            return (ft_strnew(1));
    str = ft_bchar(1, (char)tmp);
    return (str);
}