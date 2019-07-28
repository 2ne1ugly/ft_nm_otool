/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:12:25 by mchi              #+#    #+#             */
/*   Updated: 2019/07/27 21:54:03 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_STRUCT_H
# define COMMON_STRUCT_H

# include <mach-o/loader.h>
# include <mach-o/fat.h>
# include <mach-o/nlist.h>
# include <stdlib.h>

// typedef struct mach_header			t_m_h_t;
// typedef struct mach_header_64		t_m_h64_t;
// typedef struct segment_command		t_s_c_t;
// typedef struct segment_command_64	t_s_c64_t;
// typedef struct section				t_s_t;
// typedef struct section_64			t_s64_t;

typedef union						u_m_h
{
	struct mach_header		h;
	struct mach_header_64	h64;
}									t_m_h;

typedef union						u_s_c
{
	struct segment_command		sc;
	struct segment_command_64	sc64;	
}									t_s_c;

typedef union						u_s
{
	struct section		s;
	struct section_64	s64;
}									t_s;

typedef union						u_nl
{
	struct nlist	nl;
	struct nlist_64	nl64;
}									t_nl;

typedef struct stat					t_stat;

typedef struct symtab_command		t_st_c;
typedef struct dysymtab_command		t_dyst_c;

typedef struct						s_file
{
	char	*path;
	char	*data;
	size_t	length;
	int		reverse;
}									t_file;

typedef struct						s_sym
{
	uint64_t	addr;
	char		c;
	char		*name;
}									t_sym;

typedef struct						s_vec
{
	t_sym	*data;
	size_t	size;
	size_t	cap;
}									t_vec;

#endif