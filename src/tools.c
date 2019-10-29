/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:58:32 by swarner           #+#    #+#             */
/*   Updated: 2019/10/27 20:00:51 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_one_path(t_lem *lem)
{
	int ant;

	ant = 1;
	while (ant < lem->ants + 1)
	{
		ft_putstr("\n");
		print_moves(ant, lem->end->name);
		ant++;
	}
	ft_putstr("\n");
}

void	print_moves(int ant_number, char *room)
{
	ft_putstr("L");
	ft_putnbr(ant_number);
	ft_putstr("-");
	ft_putstr(room);
	ft_putstr(" ");
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
