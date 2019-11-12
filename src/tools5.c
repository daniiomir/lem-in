/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:38:00 by cnikia            #+#    #+#             */
/*   Updated: 2019/11/12 20:38:02 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
