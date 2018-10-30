#include "ft_printf.h"

char    *handling_flags(char **format, t_flags *flags)
{
    while (**format == '#' || **format == ' ' || **format == '+' \
            || **format == '-' || **format == '0')
    {
        if (**format == '#')
            flags->hashtag = 1;
        if (**format == '-')
            flags->right_padding = 1;
        if (**format == ' ')
            flags->space = 1;
        if (**format == '+')
            flags->plus = 1;
        if (**format == '0')
            flags->zero_padding = 1;
        if (flags->right_padding == 1)
            flags->zero_padding = 0;
        (*format)++;
    }
    return (*format);
}

char    *handling_width(char **format, t_flags *flags, va_list *arg)
{
    int     star_width;
    int     width;

    star_width = 0;
    while (**format == '*' || ft_isdigit(**format))
    {
        if (star_width == 1 && ft_isdigit(**format))
            return (NULL);
        if (star_width == -1 && **format == '*')
            return (NULL);
        if (star_width == 1 && **format == '*')
            return (NULL);
        if (**format == '*')
        {
            star_width = -1;
            width = va_arg(*arg, int);
            if (width < 0)
            {
                width = -width;
                flags->right_padding = 1;
            }
            flags->width = width;
        }
        if (ft_isdigit(**format))
        {
            star_width = -1;
            flags->width = flags->width * 10 + **format - 48;
        }
        (*format)++;
    }
    return (*format);
}


char    *handling_precision(char **format, t_flags *flags, va_list *arg)
{
    int     star_precision;
    int     precision;

    star_precision = 0;
    if (**format == '.')
        while (**format == '.' || **format == '*' || ft_isdigit(**format))
        {
            flags->precision_exist = 1;
            if (star_precision == 1 && ft_isdigit(**format))
                return (NULL);
            if (star_precision == -1 && **format == '*')
                return (NULL);
            if (star_precision == 1 && **format == '*')
                return (NULL);
            if (**format == '*')
            {
                star_precision = -1;
                precision = va_arg(*arg, int);
                flags->precision = precision;
            }
            if (ft_isdigit(**format))
            {
                star_precision = -1;
                flags->precision = flags->precision * 10 + **format - 48;
            }
            (*format)++;
        }
    return (*format);
}


char    *handling_format(char **format, t_flags *flags)
{
    flags->format = ft_strnew(1);
    if ((**format) == 'l')
        flags->format = ft_update(flags->format, ft_strdup("l"));
    if ((**format) == 'h')
        flags->format = ft_update(flags->format, ft_strdup("h"));
    if ((**format) == 'j')
        flags->format = ft_update(flags->format, ft_strdup("j"));
    if ((**format) == 'z')
        flags->format = ft_update(flags->format, ft_strdup("z"));
    if ((**format) == 'z' || (**format) == 'j' || (**format) == 'l' || (**format) == 'h')
        (*format)++;
    if ((**format) == 'h' && !ft_strcmp(flags->format, "h"))
        flags->format = ft_update(flags->format, ft_strdup("hh"));
    if ((**format) == 'l' && !ft_strcmp(flags->format, "l"))
        flags->format = ft_update(flags->format, ft_strdup("ll"));
    if (!ft_strcmp(flags->format, "ll") || !ft_strcmp(flags->format, "hh"))
        (*format)++;
    return (*format);
}


int     parse_flags(char **format, t_flags *flags, va_list *arg)
{
    if ((handling_flags(format, flags)) == NULL)
        return (-1);
    if ((handling_width(format, flags, arg)) == NULL)
        return (-1);
    if ((handling_precision(format, flags, arg)) == NULL)
        return (-1);
    if ((handling_format(format, flags)) == NULL)
        return (-1);
    if (!ft_strcmp(flags->format, "l") && (**format) == 'c')
        flags->conversion = 'C';
    if (!ft_strcmp(flags->format, "l") && (**format) == 's')
        flags->conversion = 'S';
//    printf("Flags: Hash = %d  Space = %d  Plus = %d  Right Padding = %d  Zero = %d  Width = %d  Precision = %d  Format = %s\n", flags->hashtag, flags->space, flags->plus, flags->right_padding, flags->zero_padding, flags->width, flags->precision, flags->length);
    return (1);
}