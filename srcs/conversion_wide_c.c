# include "ft_printf.h"

char    *conversion_wide_c(va_list *arg)
{
    wchar_t     tmp_chr;
    char        chr;
    char        *str;

    tmp_chr = va_arg(*arg, wint_t);
    chr = (char)tmp_chr;
    str = ft_bchar(1, chr);
    return (str);
}