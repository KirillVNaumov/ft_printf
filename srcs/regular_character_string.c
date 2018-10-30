# include "ft_printf.h"

int          regular_character_string(char **next, t_flags *flags, va_list *arg)
{
    char    *tmp;
    int     length;

    length = 0;
    tmp = conversions(next, flags, arg);
    length = ft_strlen(tmp);
    write(1, tmp, length);
    free(tmp);
    return (length);
}