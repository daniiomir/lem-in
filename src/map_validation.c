/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:14:08 by cnikia            #+#    #+#             */
/*   Updated: 2019/10/21 17:14:09 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	find_first_way(t_way *way)
{
	t_way	*new;
	t_way	*curr;
	t_link	*link;

	curr = way;
	while (curr->next)
		curr = curr->next;
	link = way->room->link;
	while (link)
	{
		if (!(link->path->lock))
		{
			new = new_way();
			new->prev = way->room;
			new->room = link->path;
			new->room->lock = 1;
			curr->next = new;
			curr = curr->next;
		}
		link = link->next;
	}
}

void	map_check(t_lem *lem)
{
	t_way	*way;
	t_way	*start_way;

	if (lem->ants < 0)
		error_exit(lem, 1);
	way = new_way();
	start_way = way;
	way->room = lem->start;
	while (way)
	{
		find_first_way(way);
		way = way->next;
	}
	while (start_way)
	{
		if (ft_strequ(start_way->room->name, lem->end->name))
			break ;
		start_way = start_way->next;
	}
	if (!start_way)
		error_exit(lem, 1);
	if (!(ft_strequ(start_way->room->name, lem->end->name)))
		error_exit(lem, 1);
}