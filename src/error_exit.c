/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:53:41 by cnikia            #+#    #+#             */
/*   Updated: 2019/11/01 13:26:05 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		free_struct(t_lem *lem)
{
	t_link	*wst;
	t_path	*wsd;

	if (lem)
	{
		while (lem->way)
		{
			if (lem->way->link)
			{
				while (lem->way->link)
				{
					wst = lem->way->link;
					lem->way->link = lem->way->link->next;
					if (wst)
						free(wst);
				}
			}
			if (lem->way->name)
				free(lem->way->name);
			wsd = lem->way;
			lem->way = lem->way->next;
			if (wsd)
				free(wsd);
		}
	}
}

void			error_exit(t_lem *lem, int error)
{
	free_struct(lem);
	if (error)
		ft_putstr("ERROR\n");
	exit(0);
}

void			way_erase(t_way *way)
{
	t_way	*wst;

	if (way)
	{
		while (way->prev)
		{
			if (way->prev)
				way = way->prev;
		}
		while (way)
		{
			wst = way;
			way = way->next;
			free(wst);
			wst = NULL;
		}
	}
}

void			remove_ways(t_ways *ways)
{
	t_ways *wst;

	while (ways)
	{
		wst = ways;
		way_erase(ways->way);
		ways = ways->next;
		free(wst);
		wst = NULL;
	}
}

void			remove_only_ways(t_ways *ways)
{
	t_ways *wst;

	while (ways)
	{
		wst = ways;
		ways = ways->next;
		free(wst);
		wst = NULL;
	}
}

void			remove_only_one_ways(t_ways *ways)
{
	if (ways)
	{
		if (ways->way)
			way_erase(ways->way);
		free(ways);
		ways = NULL;
	}
}