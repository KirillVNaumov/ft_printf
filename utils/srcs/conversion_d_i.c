#include "ft_printf.h"

char    *conversion_d_i(va_list *arg, t_flags *flags)
{
    char    *answer;
    intmax_t   tmp;

    answer = ft_strnew(1);
    tmp = va_arg(*arg, intmax_t);
    if (!ft_strcmp(flags->format, "ll"))
        tmp = (long long)tmp;
    else if (!ft_strcmp(flags->format, "l"))
        tmp = (long int)tmp;
    else if (!ft_strcmp(flags->format, "hh")) // WEIRD
        tmp = (char)tmp;
    else if (!ft_strcmp(flags->format, "h")) // WEIRD
        tmp = (short int)tmp;
    else if (!ft_strcmp(flags->format, "j"))
        tmp = (intmax_t)tmp;
    else if (!ft_strcmp(flags->format, "z"))
        tmp = (size_t)tmp;
    else
        tmp = (int)tmp;
    answer = ft_update(answer, ft_itoa_intmax(tmp));
    if (answer[0] == '-')
    {
        flags->minus = 1;
        answer = ft_update(answer, ft_strsub(answer, 1, ft_strlen(answer) - 1));
    }
    return (answer);
}