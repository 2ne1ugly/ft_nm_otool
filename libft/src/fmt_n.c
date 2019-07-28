/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_n.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:09:04 by mchi              #+#    #+#             */
/*   Updated: 2019/05/25 18:59:38 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

void	fmt_n(t_opt *opt, va_list *arg, int size)
{
	void *ptr;

	ptr = va_arg(*arg, void*);
	if (opt->length == 0)
		*(int *)ptr = size;
	if (opt->length == 1)
		*(char *)ptr = size;
	if (opt->length == 2)
		*(short *)ptr = size;
	if (opt->length == 3)
		*(long *)ptr = size;
	if (opt->length == 4)
		*(long long *)ptr = size;
	if (opt->length == 5)
		*(intmax_t *)ptr = size;
	if (opt->length == 6)
		*(size_t *)ptr = size;
	if (opt->length == 7)
		*(ptrdiff_t *)ptr = size;
}
