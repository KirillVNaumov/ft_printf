/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 20:30:38 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/31 20:30:39 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*handling_precision(char **format, t_flags *flags, va_list *arg)
{
	int		star_precision;
	int		precision;

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
