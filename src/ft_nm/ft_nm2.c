/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:09:00 by mchi              #+#    #+#             */
/*   Updated: 2019/07/27 22:07:06 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "ft_nm.h"

char	get_symbol(t_nm *nm, t_nl *nl, uint64_t n_value)
{
	char c;

	c = '?';
	if (N_STAB & nl->nl.n_type)
		c = '-';
	else if ((N_TYPE & nl->nl.n_type) == N_UNDF)
		c = (char)(n_value ? 'c' : 'u');
	else if ((N_TYPE & nl->nl.n_type) == N_ABS)
		c = 'a';
	else if ((N_TYPE & nl->nl.n_type) == N_SECT
		&& nm->sect_symbol[nl->nl.n_sect - 1])
		c = nm->sect_symbol[nl->nl.n_sect - 1];
	else if ((N_TYPE & nl->nl.n_type) == N_PBUD)
		c = 'u';
	else if ((N_TYPE & nl->nl.n_type) == N_INDR)
		c = 'i';
	else if (nl->nl.n_desc & N_WEAK_REF)
		c = 'W';
	else
		c = '?';
	if (nl->nl.n_type & N_EXT && c >= 'a' && c <= 'z')
		c += 'A' - 'a';
	return (c);
}

int		nm_dump_symtab_command(t_file *f, t_nm *nm, t_st_c *st, int is_64)
{
	size_t		i;
	t_nl		*nl;
	char		*stroff;
	size_t		nl_size;
	t_sym		sym;

	nl_size = is_64 ? sizeof(nl->nl64) : sizeof(nl->nl);
	if (!(stroff = file_ensure(f, st->stroff, st->strsize)) ||
		!(nl = file_ensure(f, st->symoff, st->nsyms * nl_size)))
		return (0);
	i = 0;
	while (i < st->nsyms)
	{
		sym.addr = (is_64) ? (nl->nl64.n_value) : (nl->nl.n_value);
		sym.c = get_symbol(nm, nl, sym.addr);
		sym.name = &stroff[nl->nl.n_un.n_strx];
		if (sym.c != '-')
			push_back_vec(nm->symbol, &sym);
		i++;
		nl = (void *)nl + nl_size;
	}
	return (1);
}

int		nm_dump_dysymtab_command(t_file *f, t_nm *nm, t_dyst_c *dyst, int is_64)
{
	(void)f;
	(void)dyst;
	(void)is_64;
	(void)nm;
	return (1);
}

int		nm_find_sym_tab(t_file *f, t_nm *nm, t_m_h *h, int is_64)
{
	t_s_c	*sc;
	size_t	i;
	size_t	offset;

	offset = is_64 ? sizeof(h->h64) : sizeof(h->h);
	i = -1;
	while (++i < h->h.ncmds)
	{
		if (!(sc = file_ensure(f, offset, sizeof(t_dyst_c))) || !sc->sc.cmdsize)
			return (0);
		if (sc->sc.cmd == LC_SYMTAB &&
			!nm_dump_symtab_command(f, nm, (t_st_c *)sc, is_64))
			return (0);
		else if (sc->sc.cmd == LC_DYSYMTAB &&
			!nm_dump_dysymtab_command(f, nm, (t_dyst_c *)sc, is_64))
			return (0);
		offset += sc->sc.cmdsize;
	}
	return (1);
}

int		ft_nm_collect_symbol(t_file *f, t_nm *nm)
{
	t_m_h		*h;

	if (!(h = file_ensure(f, 0, sizeof(t_m_h))))
		return (0);
	return (nm_find_sym_tab(f, nm, h, h->h.magic == MH_MAGIC_64));
}
