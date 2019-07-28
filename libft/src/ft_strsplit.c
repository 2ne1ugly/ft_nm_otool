/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:25:08 by awindham          #+#    #+#             */
/*   Updated: 2019/05/25 23:49:56 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static void	alloc_list(const char *s, char c, char ***list)
{
	int		count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != '\0')
		{
			count++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	*list = (char **)malloc(sizeof(char *) * (unsigned long)(count + 1));
	if (*list != NULL)
		(*list)[count] = NULL;
}

static int	ft_word_length(const char *s, char c)
{
	int count;

	count = 0;
	while (*s != '\0' && *s != c)
	{
		count++;
		s++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**list;
	int		i;
	int		length;

	alloc_list(s, c, &list);
	if (list == NULL)
		return (NULL);
	i = -1;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s == '\0')
			break ;
		length = ft_word_length(s, c);
		list[++i] = (char *)malloc(sizeof(char) * (unsigned long)(length + 1));
		if (list[i] == NULL)
			return (NULL);
		ft_strncpy(list[i], s, (unsigned long)length);
		list[i][length] = '\0';
		while (*s != c && *s != '\0')
			s++;
	}
	return (list);
}
