# include "ft_printf.h"

int    wide_character_string(char **next, t_flags *flags, va_list *arg)
{
    int     length;
    wchar_t     *tmp_str;
    wchar_t      tmp_chr;    

    length = 0;
    if (flags->conversion == 'C')
    {
        if (flags->right_padding == 0)
            length += adding_width_wide(flags, 1);
        tmp_chr = va_arg(*arg, wchar_t);
        ft_putwchar(tmp_chr);
        length++;
        if (flags->right_padding == 1)
            length += adding_width_wide(flags, 1);
    }
    if (flags->conversion == 'S')
    {
        tmp_str = va_arg(*arg, wchar_t *);
        if (flags->right_padding == 0)
            length += adding_width_wide(flags, ft_wstrlen(tmp_str));
        length += printing_string_wide(tmp_str);
        if (flags->right_padding == 1)
            length += adding_width_wide(flags, ft_wstrlen(tmp_str));
    }
    (*next)++;
    return (length);
}
