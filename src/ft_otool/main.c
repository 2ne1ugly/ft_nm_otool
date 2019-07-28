/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:01:09 by mchi              #+#    #+#             */
/*   Updated: 2019/07/27 21:13:52 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "ft_otool.h"

int	main(int argc, char **argv)
{
	t_file	f;
	int		i;

	i = 1;
	while (i < argc)
	{
		f.path = argv[i];
		if (!ft_otool(&f))
			ft_printf("failed on %s\n", argv[i]);
		if (f.data)
			free(f.data);
		i++;
	}
	return (0);	
}
