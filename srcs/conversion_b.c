#include "ft_printf.h"

char    *conversion_b(va_list *arg, t_flags *flags)
{
    char    *answer;
    intmax_t   tmp;

    answer = ft_strnew(1);
    tmp = va_arg(*arg, uintmax_t);
    if (!ft_strcmp(flags->format, "ll"))
        tmp = (unsigned long long int)tmp;
    else if (!ft_strcmp(flags->format, "l"))
        tmp = (unsigned long int)tmp;
    else if (!ft_strcmp(flags->format, "hh")) // WEIRD
        tmp = (unsigned char)tmp;
    else if (!ft_strcmp(flags->format, "h")) // WEIRD
        tmp = (unsigned short int)tmp;
    else if (!ft_strcmp(flags->format, "j"))
        tmp = (uintmax_t)tmp;
    else if (!ft_strcmp(flags->format, "z"))
        tmp = (size_t)tmp;
    else
        tmp = (unsigned int)tmp;
    answer = ft_update(answer, ft_itoa_base_unsigned(tmp, 2));
    if (flags->hashtag == 1 && tmp != 0)
        answer = ft_update(answer, ft_strjoin("0x", answer));
    return (answer);
}