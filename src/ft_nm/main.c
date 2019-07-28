/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 22:56:00 by mchi              #+#    #+#             */
/*   Updated: 2019/07/27 22:04:55 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "ft_nm.h"

void	sort_tab(t_sym *sym, int count)
{
	int		i;
	int		is_sorted;
	t_sym	temp;

	is_sorted = 0;
	while (!is_sorted)
	{
		is_sorted = 1;
		i = 0;
		while (i < count - 1)
		{
			if (strcmp(sym[i].name, sym[i + 1].name) > 0)
			{
				temp = sym[i];
				sym[i] = sym[i + 1];
				sym[i + 1] = temp;
				is_sorted = 0;
			}
			i++;			
		}
	}
}

void	print_tab(t_sym *sym, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		if (sym[i].c == 'U' || sym[i].c == 'u')
			ft_printf("                ");
		else
			ft_printf("%016zx", sym[i].addr);
		ft_printf(" %c %s\n", sym[i].c, sym[i].name);
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_file	f;
	t_nm	nm;
	t_vec	*vec;
	int		i;

	i = 1;
	vec = create_vec();
	while (i < argc)
	{
		ft_bzero(&f, sizeof(t_file));
		ft_bzero(&nm, sizeof(t_nm));
		nm.symbol = vec;
		f.path = argv[i];
		if (ft_nm_collect_sect_symbol(&f, &nm) && ft_nm_collect_symbol(&f, &nm))
		{
			sort_tab(vec->data, vec->size);
			print_tab(vec->data, vec->size);
		}
		else
			ft_printf("failed on %s\n", argv[i]);
		if (f.data)
			free(f.data);
		vec->size = 0;
		i++;
	}
	return (0);	
}
