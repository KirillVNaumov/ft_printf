/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:15:59 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/25 10:16:00 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <wchar.h>


# include <limits.h>
# include <stdio.h>

typedef struct  s_flags
{
    int         hashtag;        //special options
    int         right_padding;  //when using '-' ---> '     123'
    int         minus;
    int         plus;
    int         zero_padding;   //when using '0' ---> all ' ' replaced by '0'
    int         width;          //minimal width of the string
    int         precision;      //precision
    int         precision_exist;
    int         space;          //puts space before positive number
    char        conversion;
    char        *format;          // 'll', 'hh', 'h', 'l', 'j', and 'z'
}               t_flags;          

//SRCS

int          parse_flags(char **format, t_flags *flags, va_list *arg);
int          regular_character_string(char **next, t_flags *flags, va_list *arg);
int          wide_character_string(char **next, t_flags *flags, va_list *arg);
char         *conversions(char **format, t_flags *flags, va_list *arg, int *length);
char         *conversion_c(va_list *arg);
char         *conversion_wide_c(va_list *arg);
char         *conversion_wide_s(va_list *arg, int *length);
char         *conversion_s(va_list *arg);
char         *conversion_b(va_list *arg, t_flags *flags);
char         *conversion_p(va_list *arg);
char         *conversion_d_i(va_list *arg, t_flags *flags);
char         *conversion_o_O(va_list *arg, t_flags *flags);
char         *conversion_x_X(va_list *arg, t_flags *flags);
char         *conversion_u_D_U(va_list *arg, t_flags *flags);
char         *adding_width(t_flags *flags, char *str);
int          adding_width_wide(t_flags *flags, int length_str);
char         *adding_plus(t_flags *flags, char *str);
char         *adding_space(t_flags *flags, char *str);
char         *adding_minus(t_flags *flags, char *str);
char         *adding_precision_string(t_flags *flags, char *str);
char         *adding_precision_number(t_flags *flags, char *str);
int          ft_printf(const char *format, ...);

//UTILS

int          printing_string_wide(wchar_t *str);
char		*ft_itoa_intmax(long long value);
char		*ft_itoa_unsigned(uintmax_t value);
char	    *ft_itoa_base_unsigned(uintmax_t value, int base);

#endif