/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:32:51 by mchi              #+#    #+#             */
/*   Updated: 2019/05/25 19:34:46 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

t_vec	fmt_s(t_opt *opt, va_list *arg)
{
	char	*str;
	t_vec	out;
	int		length;

	init_vec(&out);
	str = va_arg(*arg, char*);
	if (str == NULL)
		str = "(null)";
	length = ft_strlen(str);
	if (opt->precision == -1 || length < opt->precision)
		opt->precision = length;
	push_back_str(&out, str, opt->precision);
	pad_width(&out, opt);
	return (out);
}
