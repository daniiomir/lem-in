/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:14:08 by cnikia            #+#    #+#             */
/*   Updated: 2019/10/25 18:36:26 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_way			*map_check(t_lem *lem)
{
	t_way	*wst;
	t_way	*way;
	t_way	*first;

	way = way_parse(lem);
	wst = way;
	while (wst)
	{
		if (ft_strequ(wst->room->name, lem->end->name))
			break ;
		wst = wst->next;
	}
	if (!wst)
		error_exit(lem, 1);
	if (!(ft_strequ(wst->room->name, lem->end->name)))
		error_exit(lem, 1);
	first = way_saving(wst);
	way_erase(way);
	return (first);
}