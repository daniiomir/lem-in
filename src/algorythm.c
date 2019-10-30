/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 19:04:43 by swarner           #+#    #+#             */
/*   Updated: 2019/10/27 19:55:56 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_way	*find_more_ways(t_lem *lem)
{
	t_way	*way;
	t_way	*wst;
	t_way	*clear_way;

	clear_way = NULL;
	way = way_parse(lem);
	wst = way;
	while (wst)
	{
		if (ft_strequ(wst->room->name, lem->end->name))
			break ;
		wst = wst->next;
	}
	if (!wst)
		return (NULL);
	if ((ft_strequ(wst->room->name, lem->end->name)))
		clear_way = way_saving(wst, lem);
	way_erase(way);
	return (clear_way);
}

static void		remove_same_edge(t_ways *ways)
{
	t_ways	*wst;
	t_ways	*check;
	t_way	*swp;
	t_way	*a;
	t_way	*b;
	t_link	*wst_link;

	wst = ways;
	while (wst)
	{
		check = ways;
		if (check == wst)
			check = check->next;
		while (check)
		{
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
					b = b->next;
				}
				a = a->next;
			}
			check = check->next;
		}
		wst = wst->next;
	}
}
/* static void		find_cross_ways(t_ways *ways)
{
	t_ways	*wst;
	t_ways	*check;
	t_ways	*rm;
	t_way	*a;
	t_way	*b;
	int		a;

	a = 0;
	wst = ways;
	while (wst)
	{
		check = ways;
		if (check == wst)
			check = check->next;
		while (check)
		{
			a = wst->way;
			while (a)
			{
				b = check->way;
				while (b)
				{
					if (a->room == b->room)
					{
						a = wst->way;
						b = check->way;
						if (a->lenght > b->lenght)
						{
							rm = wst;
							if (wst->prev && wst->next)
								wst->prev->next = wst->next;
							wst = wst->prev;
							remove_ways(rm);
						}
						else
						{
							rm = check;
							if (check->prev && check->next)
								check->prev->next = check->next;
							check = check->prev;
							remove_ways(rm);
						}
						a = 1;
						break ;
					}
					b = b->next;
				}
				if (a == 1)
					break ;
				a = a->next;
			}
			if (a == 1)
				break ;
			check = check->next;
		}
		if (a == 1)
		{
			a = 0;
			continue ;
		}
		wst = wst->next;
	}
} */

static void		main_alg(t_lem *lem, t_way *first)
{
	t_ways	*ways;
	t_ways	*new;
	t_ways	*curr;
	t_way	*wst;

	ways = new_ways(first, NULL);
	ways_re_lock(lem, ways);
	curr = ways;
	while ((wst = find_more_ways(lem)))
	{
		new = new_ways(wst, curr);
		curr->next = new;
		curr = curr->next;
		remove_same_edge(ways);
		ways_re_lock(lem, ways);
	}
	//find_cross_ways(ways);
}

void			ant_alg(t_lem *lem, t_way *first_way)
{
	if (is_one_path(lem))
		print_one_path(lem);
	else
		main_alg(lem, first_way);
}
