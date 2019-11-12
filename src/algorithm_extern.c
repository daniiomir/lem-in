/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_number_delete_un_optimal.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:31:43 by cnikia            #+#    #+#             */
/*   Updated: 2019/11/12 18:31:45 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			fill_serial_number(t_ways *ways)
{
	t_ways	*wst;
	int		a;

	wst = ways;
	a = 1;
	while (wst)
	{
		wst->num = a;
		a++;
		wst = wst->next;
	}
}

void			delete_un_optimal(t_ways **ways, t_lem *lem)
{
	t_ways	*wst;
	t_ways	*remove;

	wst = *ways;
	while (wst)
	{
		if (wst->delete)
		{
			if (wst->prev)
				wst->prev->next = wst->next;
			if (wst->next && wst->prev)
				wst->next->prev = wst->prev;
			remove = wst;
			if (!wst->prev)
				*ways = wst->next;
			wst = wst->next;
			remove_only_one_ways(remove);
			(lem->way_count)--;
			continue ;
		}
		wst = wst->next;
	}
}

static void		ways_swap(t_ways *check, t_ways *wst)
{
	t_ways	*swp;

	if (check->prev && check->prev != wst)
		check->prev->next = wst;
	if (wst->prev && wst->prev != check)
		wst->prev->next = check;
	swp = check->next;
	check->next = (wst->next == check) ? wst : wst->next;
	if (wst->next && wst->next != check)
		wst->next->prev = check;
	wst->next = (swp == wst) ? check : swp;
	if (swp)
		swp->prev = wst;
	swp = check->prev;
	check->prev = (wst->prev == check) ? wst : wst->prev;
	wst->prev = (swp == wst) ? check : swp;
}

void			sort_by_lenght(t_ways **ways)
{
	t_ways	*wst;
	t_ways	*check;

	wst = *ways;
	while (wst)
	{
		check = wst->next;
		while (check)
		{
			if (check->way->lenght < wst->way->lenght)
			{
				ways_swap(check, wst);
			}
			check = check->next;
		}
		wst = wst->next;
	}
	while ((*ways)->prev)
		(*ways) = (*ways)->prev;
}

void			find_way(t_way *way)
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
