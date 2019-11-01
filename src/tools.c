/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:58:32 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 13:37:10 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_one_path_to_end(t_lem *lem)
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
	char	*move;

	move = ft_strjoin_free2("L", ft_itoa(ant_number));
	move = ft_strjoin_free(move, "-");
	move = ft_strjoin_free(move, room);
	move = ft_strjoin_free(move, " ");
	ft_putstr(move);
}

int		is_one_path(t_lem *lem)
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
