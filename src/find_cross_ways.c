/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:42:02 by cnikia            #+#    #+#             */
/*   Updated: 2019/10/31 20:42:04 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_ways	*check_delete(t_ways *one, t_ways *two, t_lem *lem)
{
	t_way	*a;
	t_way	*b;

	a = one->way;
	while (a)
	{
		b = two->way;
		while (b)
		{
			if (a->room == b->room &&
			!(a->room == lem->start || a->room == lem->end))
			{
				if (a->lenght > b->lenght)
					return (one);
				else
					return (two);
			}
			b = b->next;
		}
		a = a->next;
	}
	return (NULL);
}

int		find_cross_ways(t_ways **ways, t_lem *lem)
{
	t_ways	*wst;
	t_ways	*check;
	t_ways	*delete;

	wst = *ways;
	check = *ways;
	delete = NULL;
	while (wst)
	{
		check = (check == wst) ? check->next : check;
		while (check)
		{
			if ((delete = check_delete(wst, check, lem)))
			{
				*ways = (delete == *ways) ? (*ways)->next : *ways;
				if (delete != *ways && delete->prev)
					delete->prev->next = delete->next;
				if (delete->next)
					delete->next->prev = delete->prev;
				remove_only_one_ways(delete);
				lem->way_count--;
				return (find_cross_ways(ways, lem));
			}
			check = check->next;
		}
		wst = wst->next;
	}
	return (0);
}
