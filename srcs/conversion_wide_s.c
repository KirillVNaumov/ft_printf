# include "ft_printf.h"

char    *conversion_wide_s(va_list *arg, int *length)
{
    wchar_t     *tmp_str;
    char        *str;

    tmp_str = va_arg(*arg, wchar_t *);
    *length += ft_wstrlen(tmp_str);
    str = ft_wstrdup(tmp_str);
    return (str);
}

// int		ft_wstrlen_here(wchar_t *str)
// {
// 	int		len;

// 	len = 0;
// 	while (str[len])
// 		len++;
// 	return (len);
// }

// int		idkwhy(wchar_t *str)
// {
// 	int len;
// 	int counter;

// 	counter = 0;
// 	len = 0;
// 	while (str[len])
// 	{
// 		if (str[len] > 127)
// 			counter++;
// 		len++;
// 	}
// 	return (counter);
// }

// char	*ft_wstrdup_here(wchar_t *s1)
// {
// 	int		i;
// 	char	*s2;

// 	s2 = (char *)malloc(sizeof(char) * (ft_wstrlen_here(s1) - idkwhy(s1)));
// 	if (s2 == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i])
// 	{
// 		s2[i] = (char)s1[i];
// 		// if (s1[i] > 127)
// 		// 	g_ohno++;
// 		i++;
// 	}
// 	s2[i] = '\0';
// 	return (s2);
// }

// char	*conversion_wide_s(va_list *arg/*, t_flags *data*/, int *length)
// {
// 	char	*str;
// 	// char	*tmp;
// 	wchar_t *wtmp;

//     int inwer;

//     inwer = *length; 
// 	wtmp = va_arg(*arg, wchar_t*);
// 	str = ft_wstrdup_here(wtmp);
// 	return (str);
// }