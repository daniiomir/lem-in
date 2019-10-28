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
		clear_way = way_saving(wst);
	way_erase(way);
	return (clear_way);
}

static void		main_alg(t_lem *lem, t_way *first)
{
	t_ways	*ways;
	t_ways	*new;
	t_ways	*curr;
	t_way	*wst;

	ways = new_ways(first);
	way_re_lock(lem, ways);
	curr = ways;
	while ((wst = find_more_ways(lem)))
	{
		new = new_ways(wst);
		curr->next = new;
		curr = curr->next;
		way_re_lock(lem, ways);
	}
}

void			ant_algorythm(t_lem *lem, t_way *first_way)
{
	if (is_one_path(lem))
		print_one_path(lem);
	else
		main_alg(lem, first_way);
}
