/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 12:15:44 by mchi              #+#    #+#             */
/*   Updated: 2019/05/27 12:18:32 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

int	ft_fprintf(int fd, const char *format, ...)
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
	write(fd, vec.ptr, vec.size);
	va_end(list);
	free_vec(&vec);
	return (vec.size);
}
