#include "ft_printf.h"

int     printing_string_wide(wchar_t *str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        ft_putwchar(str[i]);
        ++i;
    }
    return (i);
}