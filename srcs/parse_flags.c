/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 19:50:12 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/31 20:26:09 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*handling_flags(char **format, t_flags *flags)
{
	while (**format == '#' || **format == ' ' || **format == '+' || \
			**format == '-' || **format == '0')
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

char		*handling_width(char **format, t_flags *flags, va_list *arg)
{
	int		star_width;
	int		width;

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


int			parse_flags(char **format, t_flags *flags, va_list *arg)
{
	if ((handling_flags(format, flags)) == NULL)
		return (-1);
	if ((handling_width(format, flags, arg)) == NULL)
		return (-1);
	if ((handling_precision(format, flags, arg)) == NULL)
		return (-1);
	if ((handling_format(format, flags)) == NULL)
		return (-1);
	flags->conversion = (**format);
	if (!ft_strcmp(flags->format, "l") && (**format) == 'c')
		flags->conversion = 'C';
	if (!ft_strcmp(flags->format, "l") && (**format) == 's')
		flags->conversion = 'S';
	return (1);
}
