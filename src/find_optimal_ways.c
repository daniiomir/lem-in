/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortirovochka_dlya_algoritma_lol.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:17:46 by cnikia            #+#    #+#             */
/*   Updated: 2019/11/09 17:17:48 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		fill_serial_number(t_ways *ways)
{
	t_ways	*wst;
	int 	a;

	wst = ways;
	a = 1;
	while (wst)
	{
		wst->num = a;
		a++;
		wst = wst->next;
	}
}

int				find_sum(t_ways *ways, t_ways *curr)
{
	int 	a;
	t_ways	*wst;

	a = 0;
	wst = ways;
	while (wst)
	{
		if (wst == curr)
			break ;
		a += wst->way->lenght;
		wst = wst->next;
	}
	return (a);
}

static void		delete_un_optimal(t_ways **ways)
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
			continue ;
		}
		wst = wst->next;
	}
}

void			find_optimal_ways(t_ways **ways, int ants)
{
	int 	l;
	t_ways	*wst;

	fill_serial_number(*ways);
	wst = *ways;
	while (wst)
	{
		l = wst->way->lenght;
		l++;
		l *= wst->num;
		l -= find_sum(*ways, wst);
		if (ants <= l)
			wst->delete = 1;
		if (wst->way->lenght < 5 || wst->way->lenght > 50)
			wst->delete = 1;
		wst = wst->next;
	}
	delete_un_optimal(ways);
}