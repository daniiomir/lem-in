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

static t_ways	*scroll_to_start(t_ways *ways)
{
	t_ways	*wst;

	wst = ways;
	while (wst)
	{
		while (wst->way->next)
			wst->way = wst->way->next;
		if (!wst->next)
			break ;
		wst = wst->next;
	}
	return (wst);
}

//void			print_full_moves(t_lem *lem, t_ways *ways) // Эта хрень нихрена не закончена
//{
//	int 	ant;
//	t_ways	*normal_ways;
//
//	ant = 1;
//	while (ant < lem->ants + 1)
//	{
//		normal_ways = scroll_to_start(ways);
//		while (normal_ways->prev)
//		{
//			normal_ways->way = normal_ways->way->prev;
//			while (normal_ways->way->prev)
//			{
//				print_moves(ant, normal_ways->way->room->name);
//				ft_putchar('\n');
//				if (normal_ways->way->prev)
//					normal_ways->way = normal_ways->way->prev;
//				if (!normal_ways->way->prev)
//				{
//					print_moves(ant, lem->end->name);
//					ft_putchar('\n');
//					ant++;
//				}
//			}
//			if (normal_ways->prev)
//				normal_ways = normal_ways->prev;
//		}
//	}
////	ft_putstr("\n");
//}


static	void	moves_first_part(t_lem *lem, t_ant **ant_table)
{
	int		j;
	int 	z;

	j = 0;
	while (j < lem->way_count)
	{
		z = 0;
		while (z < j)
		{
			print_moves(ant_table[z]->number, ant_table[z]->way->room->name);
			if (ft_strequ(ant_table[z]->way->room->name, lem->end->name))
				ant_table[z]->reached_end = 1;
			if (ant_table[z]->way->prev)
				ant_table[z]->way = ant_table[z]->way->prev;
			z++;
		}
		ft_putchar('\n');
		j++;
	}
}

static void		moves_middle_part(t_lem *lem, t_ant **ant_table)
{
	int		j;
	int 	count;

	while (!ant_table[lem->ants - 1]->reached_end)
	{
		j = 0;
		while (ant_table[j]->reached_end)
			j++;
		count = lem->way_count + j;
		while (j < count)
		{
			if (j == lem->ants)
				break ;
			print_moves(ant_table[j]->number, ant_table[j]->way->room->name);
			if (ft_strequ(ant_table[j]->way->room->name, lem->end->name))
				ant_table[j]->reached_end = 1;
			if (ant_table[j]->way->prev)
				ant_table[j]->way = ant_table[j]->way->prev;
			j++;
		}
		ft_putchar('\n');
	}
}

void			print_full_moves(t_lem *lem, t_ways *ways)
{
	t_ant	**ant_table;

	ant_table = create_ant_table(lem, ways);
	moves_first_part(lem, ant_table);
	moves_middle_part(lem, ant_table);
	remove_ant_table(lem, ant_table);
}

void			print_paths(t_lem *lem, t_way *way)
{
	t_way	*print;

	print = way;
	while (!ft_strequ(print->room->name, lem->end->name))
	{
		ft_putstr(print->room->name);
		ft_putstr(" -> ");
		print = print->prev;
	}
	ft_putstr(lem->end->name);
	ft_putstr("\n");
}

void			print_ant_ways(t_lem *lem, t_ways *ways)
{
	t_ways	*print;

	print = ways;
	while (print)
	{
		while (print->way->next)
			print->way = print->way->next;
		print_paths(lem, print->way);
		print = print->next;
	}
	ft_putstr("\n");
}
