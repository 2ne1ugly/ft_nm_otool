/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:39:58 by mchi              #+#    #+#             */
/*   Updated: 2019/05/25 19:39:20 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

t_vec	fmt_p(t_opt *opt, va_list *arg)
{
	t_vec		out;
	void		*ptr;

	if (opt->precision == -1)
		opt->precision = 1;
	ptr = va_arg(*arg, void*);
	init_vec(&out);
	max_itoa_base(&out, (uintmax_t)ptr, 16, FALSE);
	pad_num_precision(&out, opt);
	add_pre_prefix(&out, opt, "0x");
	pad_width(&out, opt);
	add_post_prefix(&out, opt, "0x");
	return (out);
}
