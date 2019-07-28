/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 21:52:27 by mchi              #+#    #+#             */
/*   Updated: 2019/07/27 22:01:38 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_vec	*create_vec(void)
{
	t_vec	*v;

	v = malloc(sizeof(t_vec));
	v->size = 0;
	v->cap = 8;
	v->data = malloc(sizeof(t_sym) * v->cap);
	return (v);
}

void	reserve_vec(t_vec *v)
{
	t_sym	*d;
	size_t	i;

	v->cap *= 2;
	d = malloc(sizeof(t_sym) * v->cap);
	i = 0;
	while (i < v->size)
	{
		d[i] = v->data[i];
		i++;
	}
	free(v->data);
	v->data = d;
}

void	push_back_vec(t_vec *v, t_sym *sym)
{
	if (v->cap == v->size)
		reserve_vec(v);
	v->data[v->size++] = *sym;
}
