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

//static	void	moves_first_part(t_lem *lem, t_ant **ant_table)
//{
//	int		j;
//	int 	z;
//
//	j = 0;
//	while (j < lem->way_count)
//	{
//		z = 0;
//		while (z < j)
//		{
//			print_moves(ant_table[z]->number, ant_table[z]->way->room->name);
//			if (ft_strequ(ant_table[z]->way->room->name, lem->end->name))
//				ant_table[z]->reached_end = 1;
//			if (ant_table[z]->way->prev)
//				ant_table[z]->way = ant_table[z]->way->prev;
//			z++;
//		}
//		ft_putchar('\n');
//		j++;
//	}
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

//static void		moves_many_ways_part(t_lem *lem, t_ant **ant_table, t_ways *ways)
//{
//	int		i;
//	int		j;
//	int 	count;
//
//	i = 1;
//	while (!ant_table[lem->ants - 1]->reached_end)
//	{
//		j = 0;
//		while (ant_table[j]->reached_end)
//			j++;
//		count = lem->way_count + j;
//		while (j < count * i)
//		{
//			if (j == lem->ants)
//				break ;
//			ant_move_tool(lem, ant_table, j);
//			j++;
//		}
//		i++;
//		ft_putchar('\n');
//	}
//}

static void		moves_many_ways_part(t_lem *lem, t_ant **ant_table, t_ways *ways)
{
	int		i;
	int		j;
	int 	count;
	int 	temp;
	int 	ant;

	i = 1;
	while (!ant_table[lem->ants - 1]->reached_end)
	{
		j = 0;
		ant = 0;
		while (ant_table[ant]->reached_end)
			ant++;
		count = lem->way_count + ant;
		temp = count * i;
		if (ways->way->lenght - 1 < count * i)
			temp = ways->way->lenght - 1;
		j = 0;
		while (j < temp)
		{
			if (ant == lem->ants)
				break ;
			ant_move_tool(lem, ant_table, ant);
			ant++;
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

void			print_full_moves(t_lem *lem, t_ways *ways)
{
	t_ant	**ant_table;

	ant_table = create_ant_table(lem, ways);
//	moves_first_part(lem, ant_table);
	moves_many_ways_part(lem, ant_table, ways);
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
