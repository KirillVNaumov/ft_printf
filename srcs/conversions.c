/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 18:52:46 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/31 19:19:48 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*apply_flags(char *answer, t_flags *flags)
{
	if (flags->precision_exist != 0)
	{
		answer = ft_update(answer, adding_precision_string(flags, answer));
		answer = ft_update(answer, adding_precision_number(flags, answer));
	}
	if (flags->minus == 1)
		answer = ft_update(answer, adding_minus(flags, answer));
	else if (flags->plus == 1)
		answer = ft_update(answer, adding_plus(flags, answer));
	else if (flags->space == 1)
		answer = ft_update(answer, adding_space(flags, answer));
	if (flags->width != 0)
		answer = adding_width(flags, answer);
	return (answer);
}

char		*conversions_extra(t_flags *flags, va_list *arg, char *answer)
{
	if (flags->conversion == 'b')
		answer = ft_update(answer, conversion_b(arg, flags));
	if (flags->conversion == '%')
		answer = ft_update(answer, ft_bchar(1, '%'));
	return (answer);
}

char		*conversions(t_flags *flags, va_list *arg, int *length)
{
	char	*answer;

	answer = ft_strnew(1);
	if (flags->conversion == 'C')
		answer = ft_update(answer, conversion_wide_c(arg));
	if (flags->conversion == 'S')
		answer = ft_update(answer, conversion_wide_s(arg, length));
	if (flags->conversion == 's')
		answer = ft_update(answer, conversion_s(arg));
	if (flags->conversion == 'c')
		answer = ft_update(answer, conversion_c(arg));
	if (flags->conversion == 'i' || flags->conversion == 'd')
		answer = ft_update(answer, conversion_d_i(arg, flags));
	if (flags->conversion == 'p')
		answer = ft_update(answer, conversion_p(arg));
	if (flags->conversion == 'D' || flags->conversion == 'u' || \
		flags->conversion == 'U')
		answer = ft_update(answer, conversion_u_cap_d_cap_u(arg, flags));
	if (flags->conversion == 'o' || flags->conversion == 'O')
		answer = ft_update(answer, conversion_o_cap_o(arg, flags));
	if (flags->conversion == 'x' || flags->conversion == 'X')
		answer = ft_update(answer, conversion_x_cap_x(arg, flags));
	answer = conversions_extra(flags, arg, answer);
	answer = apply_flags(answer, flags);
	return (answer);
}
