#include "ft_printf.h"

char        *adding_width_null_char(t_flags *flags, char *str, int *length)
{
    char    *width;

    if (flags->width <= 1)
    {
        ft_putchar('\0');
        return (str);
    }
    width = ft_bchar(flags->width - 1, ' ');
    *length += ft_strlen(width);
    if (flags->right_padding == 0)
    {
        write(1, width, ft_strlen(width));
        ft_putchar('\0');
    }
    else 
    {
        ft_putchar('\0');
        write(1, width, ft_strlen(width));
    }
    free(width);
    return (str);
}