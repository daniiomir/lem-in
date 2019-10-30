/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <cnikia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:55:19 by cnikia            #+#    #+#             */
/*   Updated: 2019/10/27 19:53:57 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include <gssapi.h>
# include "libft.h"

typedef struct		s_link
{
	struct s_path	*path;
	int 			lock;
	struct s_link	*next;
}					t_link;

typedef struct		s_path
{
	char			*name;
	int 			coords[2];
	int 			lock;
	int 			range;
	int 			block_range;
	struct s_link	*link;
	struct s_path	*next;
	struct s_path	*prev;
}					t_path;

typedef struct		s_lem
{
	struct s_path	*way;
	struct s_path	*start;
	struct s_path	*end;
	int				ants;
}					t_lem;

typedef struct		s_way
{
	struct s_path	*room;
	struct s_link	*prev_link;
	int 			lenght;
	struct s_way	*prev;
	struct s_way	*next;
}					t_way;

typedef struct		s_ways
{
	struct s_way	*way;
	struct s_ways	*next;
	struct s_ways	*prev;
}					t_ways;

t_path	*new_path(char *name, int x, int y);
t_link	*new_link(t_path *room);
t_way	*new_way(void);
t_ways	*new_ways(t_way *way, t_ways *prev);
void	init_lem(t_lem *lem);

void	error_exit(t_lem *lem, int error);
void	remove_ways(t_ways *ways);

t_way	*way_parse(t_lem *lem);
void	way_erase(t_way *way);
t_way	*way_saving(t_way *way, t_lem *lem);
void	way_re_lock(t_lem *lem);
void	ways_re_lock(t_lem *lem, t_ways *ways);

void	parse_map(t_lem *lem, int ret, int fd, char **map);
void	add_link(t_lem *lem, char *str);
void	fill_rooms(t_lem *lem, char **str, const int *start, const int *end);
t_way	*map_check(t_lem *lem);

void	print_moves(int ant_number, char *room);
void	print_one_path(t_lem *lem);
int 	is_one_path(t_lem *lem);
void	ant_alg(t_lem *lem, t_way *first);

#endif