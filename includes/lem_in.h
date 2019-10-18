/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <cnikia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:55:19 by cnikia            #+#    #+#             */
/*   Updated: 2019/10/17 17:58:54 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <stdio.h>

typedef struct		s_link
{
	struct s_path	*path;
	struct s_link	*next;
}					t_link;

typedef struct		s_path
{
	char			*name;
	int 			coords[2];
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

t_path	*new_path(char *name, int x, int y);
t_link	*new_link(t_path *room);
t_lem   *new_lem();
void	map_check(t_lem *lem);
void	error_exit(t_lem *lem, int error);
void	exit_lem_in(t_lem *lem);
int		digit_check(char *str);
void	init_lem(t_lem *lem);
void	parse_map(t_lem *lem, int ret, int fd);

#endif