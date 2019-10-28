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

static t_link	*prev_link(t_way *way, t_way *new)
{
	t_link	*link;

	link = way->room->link;
	while (link->path != new->room)
		link = link->next;
	return (link);
}

void			way_re_lock(t_lem *lem, t_ways *ways)
{
	t_link	*wst;
	t_path	*wsd;
	t_ways	*wst_ways;
	t_way	*wst_way;

	wsd = lem->way;
	while (wsd)
	{
		wst = wsd->link;
		while (wst)
		{
			wst->lock = 0;
			wst = wst->next;
		}
		wsd = wsd->prev;
	}
	wst_ways = ways;
	while (wst_ways)
	{
		wst_way = wst_ways->way;
		while (wst_way)
		{
			if (wst_way->prev_link)
				wst_way->prev_link->lock = 1;
			wst_way = wst_way->next;
		}
		wst_ways = wst_ways->next;
	}
}

t_way			*way_saving(t_way *way)
{
	t_way	*new;
	t_way	*curr;
	t_way	*wst;

	new = new_way();
	new->room = way->room;
	way = way->prev;
	new->prev_link = prev_link(way, new);
	curr = new;
	while (way)
	{
		wst = new_way();
		wst->room = way->room;
		way = way->prev;
		if (way)
			wst->prev_link = prev_link(way, wst);
		wst->prev = curr;
		curr->next = wst;
		curr = curr->next;
	}
	return (new);
}
