/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:16:53 by mchi              #+#    #+#             */
/*   Updated: 2019/05/25 23:46:26 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_int.h"

void	get_flag(t_opt *opt, const char **str)
{
	opt->flags = 0;
	while (**str != '\0' && (**str == '-' || **str == '+' || **str == ' '
		|| **str == '#' || **str == '0'))
	{
		if (**str == '-')
			opt->flags |= MINUS;
		else if (**str == '+')
			opt->flags |= PLUS;
		else if (**str == ' ')
			opt->flags |= SPACE;
		else if (**str == '#')
			opt->flags |= SHARP;
		else if (**str == '0')
			opt->flags |= ZERO;
		(*str)++;
	}
}

void	get_width(t_opt *opt, const char **str, va_list *arg)
{
	opt->width = 0;
	while (**str != '\0' && (('0' <= (**str) && (**str) <= '9')
		|| **str == '*'))
	{
		if (**str == '*')
		{
			opt->width = va_arg(*arg, int);
			(*str)++;
			break ;
		}
		else
		{
			opt->width *= 10;
			opt->width += **str - '0';
		}
		(*str)++;
	}
}

void	get_precision(t_opt *opt, const char **str, va_list *arg)
{
	opt->precision = -1;
	if (**str != '.')
		return ;
	opt->precision = 0;
	(*str)++;
	while (**str != '\0' && (('0' <= (**str) && (**str) <= '9')
		|| **str == '*'))
	{
		if (**str == '*')
		{
			opt->precision = va_arg(*arg, int);
			(*str)++;
			break ;
		}
		else
		{
			opt->precision *= 10;
			opt->precision += **str - '0';
		}
		(*str)++;
	}
}

void	get_length(t_opt *opt, const char **str)
{
	opt->length = 0;
	if (**str == 'h')
		opt->length = H;
	else if (**str == 'l')
		opt->length = SL;
	else if (**str == 'j')
		opt->length = J;
	else if (**str == 'z')
		opt->length = Z;
	else if (**str == 't')
		opt->length = T;
	else if (**str == 'L')
		opt->length = L;
	if (**str == 'h' || **str == 'l' || **str == 'j' || **str == 'z'
		|| **str == 't' || **str == 'L')
		(*str)++;
	if (**str == 'h' || **str == 'l')
	{
		opt->length--;
		(*str)++;
	}
}

t_opt	parse_opt(const char **str, va_list *arg)
{
	int		i;
	t_opt	out;

	i = 0;
	get_flag(&out, str);
	get_width(&out, str, arg);
	get_precision(&out, str, arg);
	get_length(&out, str);
	out.spec = **str;
	return (out);
}
