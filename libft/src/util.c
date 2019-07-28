/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:56:35 by mchi              #+#    #+#             */
/*   Updated: 2019/05/25 20:42:26 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

void	add_pre_sign(t_vec *vec, t_opt *opt, int is_neg)
{
	if ((opt->flags & PLUS) || is_neg)
	{
		if (opt->flags & ZERO)
			opt->width--;
		else
			push_front_str(vec, (is_neg) ? ("-") : ("+"), 1);
	}
	else if (opt->flags & SPACE)
	{
		if (opt->flags & ZERO)
			opt->width--;
		else
			push_front_str(vec, " ", 1);
	}
}

void	add_post_sign(t_vec *vec, t_opt *opt, int is_neg)
{
	if (!(opt->flags & ZERO))
		return ;
	if ((opt->flags & PLUS) || is_neg)
		push_front_str(vec, (is_neg) ? ("-") : ("+"), 1);
	else if (opt->flags & SPACE)
		push_front_str(vec, " ", 1);
}

void	pad_width(t_vec *vec, t_opt *opt)
{
	if (opt->width <= vec->size)
		return ;
	if (opt->flags & MINUS)
		while (vec->size < opt->width)
			push_back_str(vec, " ", 1);
	else
		while (vec->size < opt->width)
			push_front_str(vec, (opt->flags & ZERO) ? ("0") : (" "), 1);
}

void	max_itoa_base(t_vec *vec, uintmax_t val, int base, int is_upper)
{
	char	*cbase;

	cbase = "0123456789abcdef";
	if (is_upper)
		cbase = "0123456789ABCDEF";
	while (val > 0)
	{
		push_front_str(vec, &cbase[val % base], 1);
		val /= base;
	}
}

void	pad_num_precision(t_vec *vec, t_opt *opt)
{
	if (vec->size >= opt->precision)
		return ;
	while (vec->size < opt->precision)
		push_front_str(vec, "0", 1);
}
