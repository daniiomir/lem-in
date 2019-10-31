/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:14:08 by cnikia            #+#    #+#             */
/*   Updated: 2019/10/25 18:36:26 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		exec_range(t_way *way)
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
			new->prev = way;
			new->room = link->path;
			if (new->room->range < new->prev->room->range + 1)
				new->room->range = new->prev->room->range + 1;
			new->room->lock = 1;
			curr->next = new;
			curr = curr->next;
		}
		link = link->next;
	}
}

static void		map_range_add(t_lem *lem)
{
	t_way	*way;

	way = new_way();
	way->room = lem->end;
	way->room->range = 1;
	while (way)
	{
		exec_range(way);
		way = way->next;
	}
	way_erase(way);
	way_free_lock(lem);
}

t_way			*map_check(t_lem *lem)
{
	t_way	*wst;
	t_way	*way;
	t_way	*first;

	way = way_parse(lem);
	wst = way;
	while (wst)
	{
		if (ft_strequ(wst->room->name, lem->end->name))
			break ;
		wst = wst->next;
	}
	if (!wst)
		error_exit(lem, 1);
	if (!(ft_strequ(wst->room->name, lem->end->name)))
		error_exit(lem, 1);
	first = way_saving(wst, lem);
	way_erase(way);
	way_free_lock(lem);
	map_range_add(lem);
	return (first);
}
