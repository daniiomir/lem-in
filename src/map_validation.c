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

static void		find_way(t_way *way)
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
		if (!(link->lock))
		{
			new = new_way();
			new->prev = way;
			new->room = link->path;
			link->lock = 1;
			curr->next = new;
			curr = curr->next;
		}
		link = link->next;
	}
}

t_way			*way_parse(t_lem *lem)
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
		if (ft_strequ(start_way->room->name, lem->end->name))
			break ;
		find_way(way);
		way = way->next;
	}
	return (start_way);
}

t_way			*way_saving(t_way *way)
{
	t_way	*new;
	t_way	*curr;
	t_way	*wst;

	new = new_way();
	new->room = way->room;
	way = way->prev;
	curr = new;
	while (way)
	{
		wst = new_way();
		wst->room = way->room;
		way = way->prev;
		wst->prev = curr;
		curr->next = wst;
		curr = curr->next;
	}
	return (new);
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
	first = way_saving(wst);
	unlock_way(lem, first);
	way_erase(way);
	return (first);
}