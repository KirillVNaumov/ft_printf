#include "ft_printf.h"

int     adding_width_wide(t_flags *flags, int length_str)
{
    int     l;
    char    *tmp;

    if (flags->width <= length_str)
        return (0);
    tmp = ft_bchar(flags->width, ' ');
    l = ft_strlen(tmp);
    write(1, tmp, l);
    free(tmp);
    return (l);
}