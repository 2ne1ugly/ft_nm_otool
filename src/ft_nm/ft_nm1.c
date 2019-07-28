/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:09:00 by mchi              #+#    #+#             */
/*   Updated: 2019/07/27 22:11:15 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "ft_nm.h"

/*
**	TODO: find section name
*/

int		nm_parse_segment_command(t_file *f, t_nm *nm, t_s_c *sc, int is_64)
{
	t_s			*s;
	size_t		i;

	(void)f;
	s = (void *)sc + (is_64 ? sizeof(sc->sc64) : sizeof(sc->sc));
	i = -1;
	while (++i < (is_64 ? sc->sc64.nsects : sc->sc.nsects))
	{
		if (ft_strcmp("__text", s->s.sectname) == 0)
			nm->sect_symbol[nm->sect_symbol_count++] = 't';
		else if (ft_strcmp("__data", s->s.sectname) == 0)
			nm->sect_symbol[nm->sect_symbol_count++] = 'd';
		else if (ft_strcmp("__bss", s->s.sectname) == 0)
			nm->sect_symbol[nm->sect_symbol_count++] = 'b';
		else
			nm->sect_symbol[nm->sect_symbol_count++] = 's';
		s += is_64 ? sizeof(s->s) : sizeof(s->s64);
	}
	return (1);
}

int		nm_parse_header(t_file *f, t_nm *nm, t_m_h *h, int is_64)
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
			if (!nm_parse_segment_command(
				f, nm, sc, sc->sc.cmd == LC_SEGMENT_64))
				return (0);
		}
		offset += sc->sc.cmdsize;
	}
	return (1);
}

int		ft_nm_collect_sect_symbol(t_file *f, t_nm *nm)
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
	return (nm_parse_header(f, nm, h, h->h.magic == MH_MAGIC_64));
}
