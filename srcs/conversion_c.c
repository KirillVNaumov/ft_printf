/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:07:01 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/31 22:19:50 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*conversion_c(va_list *arg, int *length)
{
	char	*str;
	int		tmp;

	tmp = va_arg(*arg, int);
	if (tmp == '\0')
	{
		(*length)++;
		ft_putchar('\0');
		str = ft_strnew(1);
	}
	else
		str = ft_bchar(1, (char)tmp);
	return (str);
}
