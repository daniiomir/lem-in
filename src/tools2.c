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

//static t_ways	*scroll_to_start(t_ways *ways)
//{
//	t_ways	*wst;
//
//	wst = ways;
//	while (wst)
//	{
//		while (wst->way->next)
//			wst->way = wst->way->next;
//		if (!wst->next)
//			break ;
//		wst = wst->next;
//	}
//	return (wst);
//}

static void		ant_move_tool(t_lem *lem, t_ant **ant_table, int j)
{
	if (!ant_table[j]->reached_end)
		print_moves(ant_table[j]->number, ant_table[j]->way->room->name);
	if (ft_strequ(ant_table[j]->way->room->name, lem->end->name))
		ant_table[j]->reached_end = 1;
	if (ant_table[j]->way->prev)
		ant_table[j]->way = ant_table[j]->way->prev;
}

static int 		ants_on_map(t_ways *ways)
{
	int 	ants_on_map;
	t_ways	*wst;

	wst = ways;
	ants_on_map = 0;
	while (wst)
	{
		ants_on_map += wst->way->lenght - 1;
		wst = wst->next;
	}
	return (ants_on_map);
}

static void		moves_many_ways_part(t_lem *lem, t_ant **ant_table, t_ways *ways)
{
	int 	i;
	int 	ant;
	int 	ant_on_map;

	ant_on_map = 0;
	while (!ant_table[lem->ants - 1]->reached_end)
	{
		i = 0;
		ant = 0;
		ant_on_map += lem->way_count;
		while (ant_table[ant]->reached_end)
			ant++;
		while (i < ant_on_map)
		{
			if (ant == lem->ants || i == ants_on_map(ways))
				break ;
			ant_move_tool(lem, ant_table, ant);
			ant++;
			i++;
		}
		ft_putstr("\n");
	}
//	ft_putstr("\n");
}

void			print_full_moves(t_lem *lem, t_ways *ways)
{
//	t_ways	*normal_ways;
	t_ant	**ant_table;

//	normal_ways = scroll_to_start(ways);
	ant_table = create_ant_table(lem, ways);
	moves_many_ways_part(lem, ant_table, ways);
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
		print_paths(lem, print->way, 1);
		print = print->next;
	}
	ft_putstr("\n");
}
