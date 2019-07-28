/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 12:19:09 by mchi              #+#    #+#             */
/*   Updated: 2019/05/27 12:22:59 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

void	b_set_arg(uintmax_t *val, int length, va_list *arg)
{
	if (length == 0 || length == 1 || length == 2)
		*val = va_arg(*arg, unsigned int);
	else if (length == 3)
		*val = va_arg(*arg, unsigned long int);
	else if (length == 4)
		*val = va_arg(*arg, unsigned long long int);
	else if (length == 5)
		*val = va_arg(*arg, uintmax_t);
	else if (length == 6)
		*val = va_arg(*arg, size_t);
	else if (length == 7)
		*val = va_arg(*arg, ptrdiff_t);
}

t_vec	fmt_b(t_opt *opt, va_list *arg)
{
	uintmax_t	val;
	t_vec		out;

	if (opt->precision == -1)
		opt->precision = 1;
	else
		opt->flags &= ~ZERO;
	b_set_arg(&val, opt->length, arg);
	init_vec(&out);
	max_itoa_base(&out, val, 2, FALSE);
	pad_num_precision(&out, opt);
	add_pre_prefix(&out, opt, "0b");
	pad_width(&out, opt);
	add_post_prefix(&out, opt, "0b");
	return (out);
}
