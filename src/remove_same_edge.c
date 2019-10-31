/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_same_edge.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:54:23 by cnikia            #+#    #+#             */
/*   Updated: 2019/10/31 20:54:24 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		swap_edges(t_way *a, t_way *b)
{
	t_link	*wst_link;
	t_way	*swp;

	if (a->room == b->room && a->next->room == b->prev->room)
	{
		swp = a->next;
		a->next = b->next;
		b->next->prev = a;
		wst_link = a->room->link;
		while (wst_link->path != b->next->room)
			wst_link = wst_link->next;
		b->next->prev_link = wst_link;
		b->prev->next = swp->next;
		swp->next->prev = b->prev;
		wst_link = swp->room->link;
		while (wst_link->path != swp->next->room)
			wst_link = wst_link->next;
		swp->next->prev_link = wst_link;
	}
}

static void		remove_same_edge_alg(t_ways *wst, t_ways *check)
{
	t_way	*a;
	t_way	*b;

	a = wst->way;
	while (a)
	{
		b = check->way;
		while (b)
		{
			if (!(a->next) || !(b->prev) || !(a->next->next))
			{
				b = b->next;
				continue;
			}
			swap_edges(a, b);
			b = b->next;
		}
		a = a->next;
	}
}

void			remove_same_edge(t_ways *ways)
{
	t_ways	*wst;
	t_ways	*check;

	wst = ways;
	while (wst)
	{
		check = ways;
		if (check == wst)
			check = check->next;
		while (check)
		{
			remove_same_edge_alg(wst, check);
			check = check->next;
		}
		wst = wst->next;
	}
}
