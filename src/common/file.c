/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:18:21 by mchi              #+#    #+#             */
/*   Updated: 2019/07/24 16:03:04 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

/*
**	find efficient way to read.
*/

void	*file_ensure(t_file *f, size_t offset, size_t size)
{
	if (f->length >= offset + size)
		return (void *)f->data + offset;
	return (NULL);
}

int		read_binary_file(t_file *f)
{
	t_stat	s;
	int		fd;
	int		ret;
	char	buff[1024];

	f->data = NULL;
	if ((fd = open(f->path, O_RDONLY)) < 0)
		return (0);
	if (fstat(fd, &s) == -1)
		return (0);
	f->data = malloc(s.st_size + 1);
	f->length = 0;
	f->reverse = 0;
	while ((ret = read(fd, buff, 1024)) > 0)
	{
		ft_memcpy(&f->data[f->length], buff, ret);
		f->length += ret;
		f->data[f->length] = '\0';
	}
	close(fd);
	return (1);
}
