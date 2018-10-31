#include "ft_printf.h"

char    *conversion_s(va_list *arg)
{
    char    *str;
    char    *tmp;

    tmp = va_arg(*arg, char *);
    if (tmp == NULL)
        str = ft_strdup("(null)");
    else
        str = ft_strdup(tmp);
    return (str);
}