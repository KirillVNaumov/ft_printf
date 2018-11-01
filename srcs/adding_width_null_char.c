/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_width_null_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 23:18:44 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/31 23:20:03 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*adding_width_null_char(t_flags *flags, char *str, int *length)
{
	char	*width;

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
