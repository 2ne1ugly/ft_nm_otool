/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:29:23 by mchi              #+#    #+#             */
/*   Updated: 2019/05/25 23:42:20 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

void		f_set_arg(long double *val, int length, va_list *arg)
{
	if (length == 0)
		*val = va_arg(*arg, double);
	else if (length == L)
		*val = va_arg(*arg, long double);
}

long double	remove_sign_long_double(long double value, int *sign)
{
	*sign = 1;
	if (value < 0)
	{
		value *= -1;
		*sign = -1;
	}
	return (value);
}

void		round_long_double(t_vec *vec, long double below)
{
	int i;

	if (below >= 5)
	{
		i = vec->size - 1;
		while (i >= 0)
		{
			if (vec->ptr[i] != '.')
			{
				vec->ptr[i]++;
				if (vec->ptr[i] != '9' + 1)
					return ;
				vec->ptr[i] = '0';
			}
			i--;
		}
		push_front_str(vec, "1", 1);
	}
}

void		long_double_dtoa(t_vec *vec, t_opt *opt, long double below
	, uintmax_t above)
{
	char	c;

	if (above == 0)
		push_front_str(vec, "0", 1);
	while (above > 0)
	{
		c = above % 10 + '0';
		push_front_str(vec, &c, 1);
		above /= 10;
	}
	if (opt->precision != 0 || opt->flags & SHARP)
		push_back_str(vec, ".", 1);
	while (opt->precision > 0)
	{
		c = (int)below + '0';
		push_back_str(vec, &c, 1);
		below = (below - (int)below) * 10;
		opt->precision--;
	}
	round_long_double(vec, below);
}

t_vec		fmt_f(t_opt *opt, va_list *arg)
{
	long double	value;
	long double no_sign;
	int			sign;
	t_vec		out;

	if (opt->precision == -1)
		opt->precision = 6;
	f_set_arg(&value, opt->length, arg);
	init_vec(&out);
	no_sign = remove_sign_long_double(value, &sign);
	long_double_dtoa(&out, opt, (no_sign - (uintmax_t)no_sign) * 10,
		(uintmax_t)no_sign);
	add_pre_sign(&out, opt, sign == -1);
	pad_width(&out, opt);
	add_post_sign(&out, opt, sign == -1);
	return (out);
}
