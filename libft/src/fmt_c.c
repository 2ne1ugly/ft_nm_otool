/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:16:42 by mchi              #+#    #+#             */
/*   Updated: 2019/05/25 18:38:24 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

t_vec	fmt_c(t_opt *opt, va_list *arg)
{
	char	c;
	t_vec	out;

	(void)opt;
	c = va_arg(*arg, int);
	init_vec(&out);
	push_back_str(&out, &c, 1);
	pad_width(&out, opt);
	return (out);
}
