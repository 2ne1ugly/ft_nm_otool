/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:13:06 by mchi              #+#    #+#             */
/*   Updated: 2019/05/25 20:33:43 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

void		d_set_arg(intmax_t *val, int length, va_list *arg)
{
	if (length == 0)
		*val = va_arg(*arg, int);
	else if (length == HH)
		*val = (char)va_arg(*arg, int);
	else if (length == H)
		*val = (short)va_arg(*arg, int);
	else if (length == LL)
		*val = va_arg(*arg, long int);
	else if (length == SL)
		*val = va_arg(*arg, long long int);
	else if (length == J)
		*val = va_arg(*arg, intmax_t);
	else if (length == Z)
		*val = va_arg(*arg, size_t);
	else if (length == T)
		*val = va_arg(*arg, ptrdiff_t);
}

t_vec		fmt_d(t_opt *opt, va_list *arg)
{
	intmax_t	raw;
	uintmax_t	no_sign;
	t_vec		out;

	if (opt->precision == -1)
		opt->precision = 1;
	else
		opt->flags &= ~ZERO;
	d_set_arg(&raw, opt->length, arg);
	init_vec(&out);
	no_sign = raw;
	if (raw < 0)
		no_sign = raw * -1;
	max_itoa_base(&out, no_sign, 10, FALSE);
	pad_num_precision(&out, opt);
	add_pre_sign(&out, opt, raw < 0);
	pad_width(&out, opt);
	add_post_sign(&out, opt, raw < 0);
	return (out);
}
