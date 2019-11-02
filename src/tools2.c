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

//void	print_paths(t_lem *lem, t_way *way)
//{
//	int ant;
//
//	ant = 1;
//	way = way->prev;
//	while (ant < lem->ants + 1)
//	{
//		while (!ft_strequ(way->room->name, lem->end->name))
//		{
//			print_moves(ant, way->room->name);
//			way = way->prev;
//		}
//		print_moves(ant, lem->end->name);
//		ant++;
//	}
//	ft_putstr("\n");
//}

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

void			print_full_moves(t_lem *lem, t_ways *ways) // Эта хрень нихрена не закончена
{
	int 	ant;
	t_ways	*normal_ways;

	ant = 1;
	while (ant < lem->ants + 1)
	{
		normal_ways = scroll_to_start(ways);
		while (normal_ways->prev)
		{
			normal_ways->way = normal_ways->way->prev;
			while (normal_ways->way->prev)
			{
				print_moves(ant, normal_ways->way->room->name);
				if (normal_ways->way->prev)
					normal_ways->way = normal_ways->way->prev;
				if (!normal_ways->way->prev)
				{
					print_moves(ant, lem->end->name);
					ft_putchar('\n');
					ant++;
				}
			}
			if (normal_ways->prev)
				normal_ways = normal_ways->prev;
		}
	}
	ft_putstr("\n");
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
