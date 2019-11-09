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

void			sort_by_lenght(t_ways *ways)
{
	t_ways	*wst;
	t_ways	*check;

	wst = ways;
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
}