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