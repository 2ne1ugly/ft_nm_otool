/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:15:19 by mchi              #+#    #+#             */
/*   Updated: 2019/07/24 18:09:33 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	reverse_8(void *s)
{
	char	*c;
	char	tmp_c;

	c = (char *)s;
	tmp_c = c[0];
	c[0] = c[7];
	c[7] = tmp_c;
	tmp_c = c[1];
	c[1] = c[6];
	c[6] = tmp_c;
	tmp_c = c[2];
	c[2] = c[5];
	c[5] = tmp_c;
	tmp_c = c[3];
	c[3] = c[4];
	c[4] = tmp_c;
}

void	reverse_4(void *s)
{
	char	*c;
	char	tmp_c;

	c = (char *)s;
	tmp_c = c[0];
	c[0] = c[3];
	c[3] = tmp_c;
	tmp_c = c[1];
	c[1] = c[2];
	c[2] = tmp_c;
}

void	reverse_2(void *s)
{
	char	*c;
	char	tmp_c;

	c = (char *)s;
	tmp_c = c[0];
	c[0] = c[1];
	c[1] = tmp_c;
}
