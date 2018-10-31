# include "ft_printf.h"

char    *conversion_wide_s(va_list *arg, int *length)
{
    wchar_t     *tmp_str;
    char        *str;

    tmp_str = va_arg(*arg, wchar_t *);
    *length += ft_wstrlen(tmp_str);
    str = ft_wstrdup(tmp_str);

    return (str);
}