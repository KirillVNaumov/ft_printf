# include "ft_printf.h"

int    wide_character_string(char **next, t_flags *flags, va_list *arg)
{
    int     length;
    wchar_t     *tmp_str;
    wchar_t      tmp_chr;

    char    **temp;
    
    temp = next;

    length = 0;

    if (flags->conversion == 'C')
        tmp_chr = va_arg(*arg, wint_t);
    if (flags->conversion == 'S')
        tmp_str = va_arg(*arg, wchar_t *);

//    tmp = w_conversions(&next, &flags, arg);
//    length += ft_wstrlen(tmp);
//    ft_putwstr(tmp);
  //  free(tmp);
    return (length);
}
