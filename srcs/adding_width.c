#include "ft_printf.h"

char        *adding_width(t_flags *flags, char *str)
{
    char    fill;
    char    *extra;

    if (flags->width <= (int)ft_strlen(str))
        return (str);
    fill = ' ';
    if (flags->zero_padding == 1 && flags->precision == 0 && flags->conversion != 's' && \
        flags->conversion != 'c' && flags->conversion != 'C' && flags->conversion != 'S' && \
        flags->conversion != 'p')
        fill = '0';
    if ((flags->conversion != 'x' || flags->conversion != 'X') && flags->zero_padding == 1 && flags->hashtag == 1)
    {
        extra = ft_bchar(flags->width - (int)ft_strlen(str) - 2, fill);
        extra = ft_update(extra, ft_strjoin("0x", extra));
    }
    else
        extra = ft_bchar(flags->width - (int)ft_strlen(str), fill);
    if (flags->zero_padding == 1 && (str[0] == '+' || str[0] == '-'))
        str = ft_update(str, ft_strsub(str, 1, ft_strlen(str) - 1));
    if (flags->right_padding == 1)
        str = ft_update(str, ft_strjoin(str, extra));
    if (flags->right_padding == 0)
        str = ft_update(str, ft_strjoin(extra, str));
    if (flags->zero_padding == 1 && flags->minus == 1)
        str = ft_update(str, ft_strjoin("-", str));
    else if (flags->zero_padding == 1 && flags->plus == 1)
        str = ft_update(str, ft_strjoin("+", str));
    free(extra);    
    return (str);
}