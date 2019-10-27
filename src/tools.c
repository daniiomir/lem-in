/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:58:32 by swarner           #+#    #+#             */
/*   Updated: 2019/10/27 19:30:09 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_moves(char *first_room, char *second_room)
{
	ft_putstr("L");
	ft_putstr(first_room);
	ft_putstr("-");
	ft_putstr(second_room);
}

int 	is_one_path(t_lem *lem)
{
	t_path	*paths;
	t_link	*links;

	paths = lem->way;
	while (paths)
	{
		if (ft_strequ(paths->name, lem->start->name))
		{
			links = paths->link;
			while (links)
			{
				if (ft_strequ(links->path->name, lem->end->name))
					return (1);
				links = links->next;
			}
		}
		paths = paths->prev;
	}
	return (0);
}

//if (ft_strequ(paths->name, lem->start->name) || ft_strequ(paths->name, lem->end->name))
//{
//if (ft_strequ(links->path->name, lem->start->name) || ft_strequ(links->path->name, lem->end->name))
//
//}
//