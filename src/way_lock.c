/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_lock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:50:02 by cnikia            #+#    #+#             */
/*   Updated: 2019/10/29 19:50:04 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		lock_ways(t_ways *ways)
{
	t_ways	*wst_ways;
	t_way	*wst_way;

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

void			ways_re_lock(t_lem *lem, t_ways *ways)
{
	t_link	*wst;
	t_path	*wsd;

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
	lock_ways(ways);
}

void			way_free_lock(t_lem *lem)
{
	t_link	*wst;
	t_path	*wsd;

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
}
