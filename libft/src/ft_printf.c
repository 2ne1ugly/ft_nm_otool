/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:38:12 by mchi              #+#    #+#             */
/*   Updated: 2019/05/27 12:12:56 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

int		ft_printf(const char *format, ...)
{
	t_vec	vec;
	va_list list;

	va_start(list, format);
	init_vec(&vec);
	while (*format != '\0')
	{
		if (*format == '%')
			format_this(&vec, &format, &list);
		else
			push_back_str(&vec, format, 1);
		format++;
	}
	write(1, vec.ptr, vec.size);
	va_end(list);
	free_vec(&vec);
	return (vec.size);
}
