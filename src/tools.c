/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:58:32 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 13:37:10 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant			*create_ant(int ant_number, t_way *way)
{
	t_ant	*ant;

	ant = (t_ant *)malloc(sizeof(t_ant));
	ant->number = ant_number;
	ant->reached_end = 0;
	ant->way = way;
	return (ant);
}

static t_ant	**malloc_ant_table(int ants)
{
	t_ant	**ant_table;

	ant_table = (t_ant **)malloc(sizeof(t_ant) * ants);
	if (!ant_table)
		return (NULL);
	return (ant_table);
}

static void		create_ant_table_helper(t_ways *wst,
	t_ant **ant_table, int *ant)
{
	if (!wst->prev && !wst->next && wst->way)
	{
		ant_table[*ant - 1] = create_ant(*ant, wst->way->prev);
		(*ant)++;
	}
}

static void		fill_ant_table(t_ways *wst, t_ant **ant_table,
	int *ant, int *patency)
{
	ant_table[*ant - 1] = create_ant(*ant, wst->way->prev);
	if (wst->num == 1)
		(*patency)++;
	(*ant)++;
}

t_ant			**create_ant_table(t_lem *lem, t_ways *ways)
{
	int		ant;
	t_ways	*wst;
	t_ant	**ant_table;
	int		patency;

	patency = 0;
	ant = 1;
	ant_table = malloc_ant_table(lem->ants);
	while (ant < lem->ants + 1)
	{
		wst = ways;
		create_ant_table_helper(wst, ant_table, &ant);
		while (wst)
		{
			if (patency >= wst->way->lenght - ways->way->lenght
				|| wst->num == 1)
			{
				if (ant > lem->ants)
					break ;
				fill_ant_table(wst, ant_table, &ant, &patency);
			}
			wst = wst->next;
		}
	}
	return (ant_table);
}
