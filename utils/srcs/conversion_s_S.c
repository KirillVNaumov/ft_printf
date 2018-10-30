#include "ft_printf.h"

char    *conversion_s_S(va_list *arg, t_flags *flags)
{
    char    *str;
    char    *tmp;
    t_flags *tmp_for_flags; //FIND THE USE OF %ls and %S

    tmp_for_flags = flags;
    tmp = va_arg(*arg, char *);
    if (tmp == NULL)
        str = ft_strdup("(null)");
    else
        str = ft_strdup(tmp);
    return (str);
}