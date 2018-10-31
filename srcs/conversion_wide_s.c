# include "ft_printf.h"

char    *conversion_wide_s(va_list *arg)
{
    wchar_t     *tmp_str;
    char        *str;

    tmp_str = va_arg(*arg, wchar_t *);
    str = ft_wstrdup(tmp_str);
    return (str);
}