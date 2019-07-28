/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:09:22 by mchi              #+#    #+#             */
/*   Updated: 2019/07/27 21:58:27 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "common_struct.h"
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <libft.h>

int		read_binary_file(t_file *f);
void	*file_ensure(t_file *f, size_t offset, size_t size);

void	reverse_8(void *s);
void	reverse_4(void *s);
void	reverse_2(void *s);

void	reverse_header(t_m_h *h, int is_64);
void	reverse_segment_command(t_s_c *sc, int is_64);
void	reverse_section(t_s *s, int is_64);

t_vec	*create_vec(void);
void	push_back_vec(t_vec *v, t_sym *sym);

#endif
