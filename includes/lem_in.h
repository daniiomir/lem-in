/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <cnikia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:55:19 by cnikia            #+#    #+#             */
/*   Updated: 2019/10/27 19:00:19 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

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
	struct s_way	*prev;
	struct s_way	*next;
}					t_way;

t_path	*new_path(char *name, int x, int y);
t_link	*new_link(t_path *room);
t_lem   *new_lem();
t_way	*new_way(void);

t_way	*way_parse(t_lem *lem);
void	error_exit(t_lem *lem, int error);
void	way_erase(t_way *way);
int		digit_check(char *str);
void	init_lem(t_lem *lem);
void	parse_map(t_lem *lem, int ret, int fd);
void	add_link(t_lem *lem, char *str);
t_way	*map_check(t_lem *lem);
void	unlock_way(t_lem *lem, t_way *way);

void	print_moves(char *first_room, char *second_room);
int 	is_one_path(t_lem *lem);

#endif