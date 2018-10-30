#include "ft_printf.h"

char         *adding_precision_number(t_flags *flags, char *str)
{
    char    *tmp;
    int     i;

    if (flags->conversion != 'd' && flags->conversion != 'i' && \
        flags->conversion != 'U' && flags->conversion != 'u' && \
        flags->conversion != 'D' && flags->conversion != 'X' && \
        flags->conversion != 'o' && flags->conversion != 'x' && \
        flags->conversion != 'O')
    {
        tmp = ft_strdup(str);
        return (tmp);
    }
    if (!((flags->conversion =='o' || flags->conversion == 'O') && flags->hashtag == 1))
        if (flags->precision == 0 && !ft_strcmp(str, "0"))
        {
            tmp = ft_strnew(1);
            return (tmp);
        }
    if (flags->precision <= (int)ft_strlen(str))
    {
        tmp = ft_strdup(str);
        return (tmp);
    }
    tmp = (char *)malloc(sizeof(char) * flags->precision + 1);
    i = 0;
    while (i < (flags->precision - (int)ft_strlen(str)))
        tmp[i++] = '0';
    while(*str)
    {
        tmp[i++] = *str;
        ++str;
    }
    tmp[i] = '\0';
    return (tmp);
}