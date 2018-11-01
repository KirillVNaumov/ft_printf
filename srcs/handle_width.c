/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 20:30:43 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/31 20:32:15 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*handling_width(char **format, t_flags *flags, va_list *arg)
{
	int		star_width;
	int		width;

	star_width = 0;
	while (**format == '*' || ft_isdigit(**format))
	{
		if ((star_width == 1 && ft_isdigit(**format)) || \
			(star_width != 0 && **format == '*'))
			return (NULL);
		if (**format == '*')
		{
			star_width = 1;
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
