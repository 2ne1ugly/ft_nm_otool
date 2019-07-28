/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:03:09 by mchi              #+#    #+#             */
/*   Updated: 2019/07/27 20:44:55 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "ft_otool.h"

int		otool_dump_section(t_file *f, t_s *s, int is_64)
{
	unsigned char	*data;
	size_t			offset;
	size_t			size;
	size_t			addr;
	size_t			i;

	offset = is_64 ? s->s64.offset : s->s.offset;
	size = is_64 ? s->s64.size : s->s.size;
	addr = is_64 ? s->s64.addr : s->s.addr;
	if (!(data = file_ensure(f, offset, size)))
		return (0);
	i = 0;
	while (i < size)
	{
		ft_printf("%016zx\t", addr + i);
		ft_printf("%02x ", (unsigned int)data[i]);
		i++;
		while (i % 16 && i < size)
		{
			ft_printf("%02x ", (unsigned int)data[i]);
			i++;
		}
		ft_printf("\n");
	}
	return (1);
}

int		parse_otool_segment_command(t_file *f, t_s_c *sc, int is_64)
{
	t_s			*s;
	size_t		i;

	(void)f;
	s = (void *)sc + (is_64 ? sizeof(sc->sc64) : sizeof(sc->sc));
	i = -1;
	while (++i < (is_64 ? sc->sc64.nsects : sc->sc.nsects))
	{
		if (f->reverse)
			reverse_section(s, is_64);
		if (ft_strcmp(s->s.sectname, "__text") == 0 &&
			ft_strcmp(s->s.segname, "__TEXT") == 0)
			if (!otool_dump_section(f, s, is_64))
				return (0);
		s += is_64 ? sizeof(s->s) : sizeof(s->s64);
	}
	return (1);
}

int		parse_otool_header(t_file *f, t_m_h *h, int is_64)
{
	t_s_c	*sc;
	size_t	i;
	size_t	offset;

	offset = is_64 ? sizeof(h->h64) : sizeof(h->h);
	i = -1;
	while (++i < h->h.ncmds)
	{
		if (!(sc = file_ensure(f, offset, sizeof(sc->sc64))) || !sc->sc.cmdsize)
			return (0);
		if (f->reverse)
			reverse_4(&sc->sc.cmd);
		if (sc->sc.cmd == LC_SEGMENT_64 || sc->sc.cmd == LC_SEGMENT)
		{
			if (f->reverse)
				reverse_segment_command(sc, sc->sc.cmd == LC_SEGMENT_64);
			if (!file_ensure(f, offset, sc->sc.cmdsize))
				return (0);
			if (!parse_otool_segment_command(
				f, sc, sc->sc.cmd == LC_SEGMENT_64))
				return (0);
		}
		offset += sc->sc.cmdsize;
	}
	return (1);
}

int		ft_otool(t_file *f)
{
	t_m_h		*h;
	uint32_t	*magic;

	if (!read_binary_file(f))
		return (0);
	if (!(magic = file_ensure(f, 0, sizeof(uint32_t))))
		return (0);
	if (*magic == MH_CIGAM || *magic == MH_CIGAM_64)
	{
		reverse_4(magic);
		f->reverse = 1;
	}
	if (!(h = file_ensure(f, 0, sizeof(t_m_h))))
		return (0);
	if (!(h->h.magic == MH_MAGIC) && !(h->h.magic == MH_MAGIC_64))
		return (0);
	if (f->reverse)
		reverse_header(h, h->h.magic == MH_MAGIC_64);
	return (parse_otool_header(f, h, h->h.magic == MH_MAGIC_64));
}
