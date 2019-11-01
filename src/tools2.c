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

void	print_full_moves(t_lem *lem, t_ways *ways) // Эта хрень нихрена не закончена
{
	int 	ant;
	t_ways	*wst;

	ant = 1;
	wst = ways;
	while (wst->next)
	{
		while (wst->way->next)
			wst->way = wst->way->next;
		if (wst->next)
			wst = wst->next;
	}
	while (ant < lem->ants + 1)
	{
		print_moves(ant, wst->way->room->name);
		while (wst)
		{
			wst = wst->prev;
		}
		ant++;
	}
}

void	print_paths(t_lem *lem, t_way *way)
{
	t_way	*print;

	print = way;
	ft_putstr("\n\n");
	while (!ft_strequ(print->room->name, lem->end->name))
	{
		ft_putstr(print->room->name);
		ft_putstr(" -> ");
		print = print->prev;
	}
	ft_putendl(lem->end->name);
}

void	print_ant_ways(t_lem *lem, t_ways *ways)
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
}
