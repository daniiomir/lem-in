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

static t_ways	*ant_move_tool(t_lem *lem, t_ant **ant_table, int j, int *max_ants, t_ways *check)
{
	t_ways	*new;
	t_ways	*wst;

	new = NULL;
	wst = check;
	while (wst)
	{
		if (wst->way == ant_table[j]->way)
			return (NULL);
		wst = wst->next;
	}
	if (!ant_table[j]->reached_end)
	{
		print_moves(ant_table[j]->number, ant_table[j]->way->room->name);
		new = new_ways(ant_table[j]->way, NULL);
		(*max_ants)++;
	}
	if (ft_strequ(ant_table[j]->way->room->name, lem->end->name))
		ant_table[j]->reached_end = 1;
	if (ant_table[j]->way->prev)
		ant_table[j]->way = ant_table[j]->way->prev;
	return (new);
}

int				all_ants_done(t_ant **ant_table, t_lem *lem)
{
	int		ant;

	ant = 0;
	while (ant < lem->ants)
	{
		if (!(ant_table[ant]->reached_end))
			return (1);
		ant++;
	}
	return (0);
}

static void		moves_many_ways_part(t_lem *lem, t_ant **ant_table)
{
	int		i;
	int		ant;
	int		ant_on_map;
	int		max_ants;
	t_ways	*check;
	t_ways	*curr;
	t_ways	*new;

	ant_on_map = 0;
	while (all_ants_done(ant_table, lem))
	{
		check = new_ways(NULL, NULL);
		curr = check;
		i = 0;
		ant = 0;
		max_ants = 0;
		ant_on_map += lem->way_count;
		while (ant_table[ant]->reached_end)
			ant++;
		while (i < ant_on_map)
		{
			if (max_ants >= lem->max_ants)
				break ;
			if (ant == lem->ants)
				break ;
			if ((new = ant_move_tool(lem, ant_table, ant, &max_ants, check)))
			{
				curr->next = new;
				curr = curr->next;
				i++;
			}
			ant++;
		}
		remove_only_ways(check);
		ft_putstr("\n");
	}
}

void			print_full_moves(t_lem *lem, t_ways *ways)
{
	t_ant	**ant_table;

	ant_table = create_ant_table(lem, ways);
	moves_many_ways_part(lem, ant_table);
	remove_ant_table(lem, ant_table);
}

void			print_paths(t_lem *lem, t_way *way, int debug)
{
	t_way	*print;

	print = way;
	while (!ft_strequ(print->room->name, lem->end->name))
	{
		if (debug)
		{
			ft_putstr(print->room->name);
			ft_putstr(" -> ");
		}
		print = print->prev;
	}
	if (debug)
	{
		ft_putstr(lem->end->name);
		ft_putstr("\n");
	}
}

void			print_ant_ways(t_lem *lem, t_ways *ways)
{
	t_ways	*print;

	print = ways;
	while (print)
	{
		while (print->way->next)
			print->way = print->way->next;
		print_paths(lem, print->way, 0);
		print = print->next;
	}
}
