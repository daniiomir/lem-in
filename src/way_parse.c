/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:54:45 by cnikia            #+#    #+#             */
/*   Updated: 2019/10/28 17:54:47 by cnikia           ###   ########.fr       */
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
		if (!(link->lock) && !(way->room->block_range == 1 &&
		link->path->block_range == 0) && !(way->room->block_range == 1
		&& link->path->range < way->room->range && link->path->range))
		{
			if (way->room->block_range == 1 && link->path->block_range == 1)
				link->path->block_range = 0;
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

static t_link	*prev_link(t_way *way, t_way *new)
{
	t_link	*link;

	link = way->room->link;
	while (link->path != new->room)
		link = link->next;
	return (link);
}

t_way			*way_lenght(t_way *way, int num)
{
	t_way	*wst;

	wst = way;
	while (wst)
	{
		wst->lenght = num;
		wst = wst->next;
	}
	return (way);
}

static void		way_saving_helper(t_way *wst, t_lem *lem)
{
	if (!ft_strequ(wst->room->name, lem->start->name))
		wst->room->block_range = 1;
}

t_way			*way_saving(t_way *way, t_lem *lem)
{
	t_way	*new;
	t_way	*curr;
	t_way	*wst;
	int		a;

	a = 1;
	new = new_way();
	new->room = way->room;
	way = way->prev;
	new->prev_link = prev_link(way, new);
	curr = new;
	while (way)
	{
		wst = new_way();
		wst->room = way->room;
		way_saving_helper(wst, lem);
		way = way->prev;
		if (way)
			wst->prev_link = prev_link(way, wst);
		wst->prev = curr;
		curr->next = wst;
		curr = curr->next;
		a++;
	}
	return (way_lenght(new, a));
}
