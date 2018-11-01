/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 19:42:21 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/31 19:48:47 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				narrow_ft_printf(const char *format, va_list *arg, int length)
{
	t_flags		flags;
	char		*next;
	char		*tmp;

	next = ft_strchr(format, '%');
	if (next == NULL)
	{
		ft_putstr(format);
		return (length + ft_strlen(format));
	}
	tmp = ft_strccrt(format, '%');
	length += ft_strlen(tmp);
	write(1, tmp, ft_strlen(tmp));
	free(tmp);
	++next;
	ft_bzero(&flags, sizeof(t_flags));
	parse_flags(&next, &flags, arg);
	tmp = conversions(&flags, arg, &length);
	++next;
	if (flags.conversion != 'S')
		length += ft_strlen(tmp);
	write(1, tmp, ft_strlen(tmp));
	free(tmp);
	free(flags.format);
	return (narrow_ft_printf(next, arg, length));
}

int				ft_printf(const char *format, ...)
{
	int			length;
	va_list		arg;

	length = 0;
	va_start(arg, format);
	length = narrow_ft_printf(format, &arg, length);
	va_end(arg);
	return (length);
}
