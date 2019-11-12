/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:40:38 by cnikia            #+#    #+#             */
/*   Updated: 2019/11/12 18:40:39 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
