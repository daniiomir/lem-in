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

int				find_lines_of_answer(t_lem *lem, t_ways *ways)
{
	t_ways	*wst;
	int		*lenght_of_path;
	int		*ant_count_on_path;
	int		a;
	int		ants;
	int		lines_of_answer;

	lenght_of_path = (int *)malloc(sizeof(int) * lem->way_count);
	ant_count_on_path = (int *)malloc(sizeof(int) * lem->way_count);
	lines_of_answer = 0;
	a = -1;
	while (a++ < lem->way_count - 1)
		ant_count_on_path[a] = 0;
	wst = ways;
	a = -1;
	while (wst && a++ < lem->way_count - 1)
	{
		lenght_of_path[a] = wst->way->lenght;
		wst = wst->next;
	}
	ants = lem->ants;
	while (ants > 0)
	{
		a = 0;
		while (a < lem->way_count)
		{
			if (lenght_of_path[a] + ant_count_on_path[a] < lines_of_answer)
			{
				ant_count_on_path[a]++;
				ants--;
			}
			a++;
		}
		lines_of_answer++;
	}
	if (lem->lines_of_answer > lines_of_answer || !(lem->lines_of_answer))
	{
		free(lem->ant_count_on_path);
		lem->ant_count_on_path = ant_count_on_path;
		lem->lines_of_answer = lines_of_answer;
		free(lenght_of_path);
		return (1);
	}
	free(ant_count_on_path);
	free(lenght_of_path);
	return (0);
}
