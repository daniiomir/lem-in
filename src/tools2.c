/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:46:21 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 15:35:14 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_ways	*ant_move_tool(t_lem *lem, t_ant **ant_table,
	int *array, t_ways *check)
{
	t_ways	*new;
	t_ways	*wst;

	new = NULL;
	wst = check;
	while (wst)
	{
		if (wst->way == ant_table[array[2]]->way)
			return (NULL);
		wst = wst->next;
	}
	if (!ant_table[array[2]]->reached_end)
	{
		print_moves(ant_table[array[2]]->number,
			ant_table[array[2]]->way->room->name);
		new = new_ways(ant_table[array[2]]->way, NULL);
		array[3]++;
	}
	if (ft_strequ(ant_table[array[2]]->way->room->name, lem->end->name))
		ant_table[array[2]]->reached_end = 1;
	if (ant_table[array[2]]->way->prev)
		ant_table[array[2]]->way = ant_table[array[2]]->way->prev;
	return (new);
}

static void		init_array(int *array)
{
	array[1] = 0;
	array[2] = 0;
	array[3] = 0;
}

static void		moves_ways_helper(t_lem *lem, int *array, t_ant **ant_table)
{
	array[0] += lem->way_count;
	init_array(array);
	while (ant_table[array[2]]->reached_end)
		array[2]++;
}

static void		fill_struct(t_ways **curr, t_ways **new, int *array)
{
	(*curr)->next = (*new);
	(*curr) = (*curr)->next;
	array[1]++;
}

void			moves_many_ways_part(t_lem *lem, t_ant **ant_table)
{
	int		array[4];
	t_ways	*check;
	t_ways	*curr;
	t_ways	*new;

	array[0] = 0;
	while (all_ants_done(ant_table, lem))
	{
		check = new_ways(NULL, NULL);
		curr = check;
		moves_ways_helper(lem, array, ant_table);
		while (array[1] < array[0])
		{
			if (array[3] >= lem->max_ants)
				break ;
			if (array[2] == lem->ants)
				break ;
			if ((new = ant_move_tool(lem, ant_table, array, check)))
				fill_struct(&curr, &new, array);
			array[2]++;
		}
		remove_only_ways(check);
		ft_putstr("\n");
	}
}
