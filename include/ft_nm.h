/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 22:56:23 by mchi              #+#    #+#             */
/*   Updated: 2019/07/27 22:01:25 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

#include "common.h"

typedef struct	s_nm
{
	char		sect_symbol[256];
	int			sect_symbol_count;
	t_vec		*symbol;
}				t_nm;

int				ft_nm_collect_symbol(t_file *f, t_nm *nm);
int				ft_nm_collect_sect_symbol(t_file *f, t_nm *nm);

#endif
