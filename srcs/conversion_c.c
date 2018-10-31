/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:07:01 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/31 16:07:23 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*conversion_c(va_list *arg)
{
	char	*str;
	int		tmp;

	tmp = va_arg(*arg, int);
	str = ft_bchar(1, (char)tmp);
	return (str);
}
