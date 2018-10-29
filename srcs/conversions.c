# include "ft_printf.h"

char          *conversions(char **format, t_flags *flags, va_list *arg)
{
    char    *answer;

    answer = ft_strnew(1);
    flags->conversion = (**format);
    if ((**format) == 's' || (**format) == 'S') //FIX FOR S = ls
        answer = ft_update(answer, conversion_s_S(arg, flags));
    if ((**format) == 'c' || (**format) == 'C') //FIX FOR C = lc
        answer = ft_update(answer, conversion_c_C(arg, flags));
    if ((**format) == 'i' || (**format) == 'd')
        answer = ft_update(answer, conversion_d_i(arg, flags));
    if ((**format) == 'p') 
        answer = ft_update(answer, conversion_p(arg));
    if ((**format) == 'D' || (**format) == 'u' || (**format) == 'U') 
        answer = ft_update(answer, conversion_u_D_U(arg, flags));
    if ((**format) == 'o' || (**format) == 'O') 
        answer = ft_update(answer, conversion_o_O(arg, flags));
    if ((**format) == 'x' || (**format) == 'X') 
        answer = ft_update(answer, conversion_x_X(arg, flags));
    if ((**format) == '%')
        answer = ft_update(answer, ft_bchar(1, '%'));
    if (flags->precision_exist != 0)
    {
        answer = adding_precision_string(flags, answer);
        answer = adding_precision_number(flags, answer);
    }
    if (flags->minus == 1)
        answer = ft_update(answer, adding_minus(flags, answer));
    else if (flags->plus == 1)
        answer = ft_update(answer, adding_plus(flags, answer));
    else if (flags->space == 1)
        answer = ft_update(answer, adding_space(flags, answer));
    if (flags->width != 0)
        answer = adding_width(flags, answer);
    (*format)++;
    return (answer);
}