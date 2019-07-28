/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 19:07:53 by mchi              #+#    #+#             */
/*   Updated: 2019/05/27 12:23:56 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

t_vec	(*g_disp_spec[])(t_opt *, va_list *) =
{
	['d'] = fmt_d,
	['i'] = fmt_d,
	['u'] = fmt_u,
	['o'] = fmt_u,
	['x'] = fmt_u,
	['X'] = fmt_u,
	['c'] = fmt_c,
	['s'] = fmt_s,
	['p'] = fmt_p,
	['f'] = fmt_f,
	['b'] = fmt_b,
	['%'] = fmt_per
};

void	format_this(t_vec *vec, const char **format, va_list *list)
{
	t_opt	opt;
	t_vec	sub_vec;

	(*format)++;
	opt = parse_opt(format, list);
	if (opt.spec == 'n')
		fmt_n(&opt, list, vec->size);
	else
		sub_vec = g_disp_spec[(int)opt.spec](&opt, list);
	push_back_str(vec, sub_vec.ptr, sub_vec.size);
	free_vec(&sub_vec);
}

void	add_pre_prefix(t_vec *vec, t_opt *opt, char *str)
{
	if (opt->flags & ZERO)
		opt->width -= ft_strlen(str);
	else
		push_front_str(vec, str, ft_strlen(str));
}

void	add_post_prefix(t_vec *vec, t_opt *opt, char *str)
{
	if (opt->flags & ZERO)
		push_front_str(vec, str, ft_strlen(str));
}
