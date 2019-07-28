/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 18:03:39 by mchi              #+#    #+#             */
/*   Updated: 2019/07/24 18:09:29 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	reverse_header(t_m_h *h, int is_64)
{
	if (is_64)
	{
		reverse_4(&h->h64.cputype);
		reverse_4(&h->h64.cpusubtype);
		reverse_4(&h->h64.filetype);
		reverse_4(&h->h64.ncmds);
		reverse_4(&h->h64.sizeofcmds);
		reverse_4(&h->h64.flags);
		reverse_4(&h->h64.reserved);
	}
	else
	{
		reverse_4(&h->h.cputype);
		reverse_4(&h->h.cpusubtype);
		reverse_4(&h->h.filetype);
		reverse_4(&h->h.ncmds);
		reverse_4(&h->h.sizeofcmds);
		reverse_4(&h->h.flags);
	}
}

void	reverse_segment_command(t_s_c *sc, int is_64)
{
	if (is_64)
	{
		reverse_4(&sc->sc64.cmdsize);
		reverse_8(&sc->sc64.vmaddr);
		reverse_8(&sc->sc64.vmsize);
		reverse_8(&sc->sc64.fileoff);
		reverse_8(&sc->sc64.filesize);
		reverse_4(&sc->sc64.maxprot);
		reverse_4(&sc->sc64.initprot);
		reverse_4(&sc->sc64.nsects);
		reverse_4(&sc->sc64.flags);
	}
	else
	{
		reverse_4(&sc->sc.cmdsize);
		reverse_4(&sc->sc.vmaddr);
		reverse_4(&sc->sc.vmsize);
		reverse_4(&sc->sc.fileoff);
		reverse_4(&sc->sc.filesize);
		reverse_4(&sc->sc.maxprot);
		reverse_4(&sc->sc.initprot);
		reverse_4(&sc->sc.nsects);
		reverse_4(&sc->sc.flags);
	}
}

void	reverse_section(t_s *s, int is_64)
{
	if (is_64)
	{
		reverse_8(&s->s64.addr);
		reverse_8(&s->s64.size);
		reverse_4(&s->s64.offset);
		reverse_4(&s->s64.align);
		reverse_4(&s->s64.reloff);
		reverse_4(&s->s64.nreloc);
		reverse_4(&s->s64.flags);
		reverse_4(&s->s64.reserved1);
		reverse_4(&s->s64.reserved2);
		reverse_4(&s->s64.reserved3);
	}
	else
	{
		reverse_4(&s->s.addr);
		reverse_4(&s->s.size);
		reverse_4(&s->s.offset);
		reverse_4(&s->s.align);
		reverse_4(&s->s.reloff);
		reverse_4(&s->s.nreloc);
		reverse_4(&s->s.flags);
		reverse_4(&s->s.reserved1);
		reverse_4(&s->s.reserved2);
	}
}
