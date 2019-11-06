/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <cnikia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:27:39 by cnikia            #+#    #+#             */
/*   Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_lem(t_lem *lem)
{
	lem->ants = -1;
	lem->way_count = 1;
	lem->start = NULL;
	lem->end = NULL;
	lem->way = NULL;
}

t_path	*new_path(char *name, int x, int y)
{
	t_path	*new;

	if ((new = (t_path *)malloc(sizeof(t_path))))
	{
		new->lock = 0;
		new->range = 0;
		new->block_range = 0;
		new->link = NULL;
		new->next = NULL;
		new->prev = NULL;
		new->name = name;
		new->coords[0] = x;
		new->coords[1] = y;
	}
	return (new);
}

t_link	*new_link(t_path *room)
{
	t_link	*new;

	if ((new = (t_link *)malloc(sizeof(t_link))))
	{
		new->path = room;
		new->lock = 0;
		new->next = NULL;
	}
	return (new);
}

t_way	*new_way(void)
{
	t_way	*new;

	if ((new = (t_way *)malloc(sizeof(t_way))))
	{
		new->room = NULL;
		new->prev_link = NULL;
		new->next = NULL;
		new->prev = NULL;
		new->lenght = 0;
	}
	return (new);
}

t_ways	*new_ways(t_way *way, t_ways *prev)
{
	t_ways	*new;

	if ((new = (t_ways *)malloc(sizeof(t_ways))))
	{
		new->way = way;
		new->prev = prev;
		new->next = NULL;
	}
	return (new);
}
