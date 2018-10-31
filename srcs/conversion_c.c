#include "ft_printf.h"

char    *conversion_c(va_list *arg)
{
    char    *str;
    int    tmp;

    tmp = va_arg(*arg, int);
    str = ft_bchar(1, (char)tmp);
    return (str);
}