/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 15:24:43 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/28 23:46:30 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_abs(long long nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

static char	*itoa_filler(char *tab, long long value, int base, int flag)
{
	long long			tmp;
	int					size;
	char				*str;

	size = 0;
	tmp = ft_abs(value);
	while (tmp /= base)
		size++;
	size = size + flag + 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = tab[ft_abs(value % base)];
		size--;
		value = value / base;
	}
	return (str);
}

char	*ft_itoa_base(long long value, int base)
{
	char				*str;
	char				*tab;
	int					flag;

	flag = 0;
	tab = "0123456789abcdef";
	if (value < 0 && base == 10)
		flag = 1;
	str = itoa_filler(tab, value, base, flag);
	return (str);
}
