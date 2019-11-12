/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 19:04:43 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 15:33:02 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_way	*find_more_ways(t_lem *lem)
{
	t_way	*way;
	t_way	*wst;
	t_way	*clear_way;

	clear_way = NULL;
	way = way_parse(lem);
	wst = way;
	while (wst)
	{
		if (ft_strequ(wst->room->name, lem->end->name))
			break ;
		wst = wst->next;
	}
	if (!wst)
	{
		way_erase(way);
		return (NULL);
	}
	if ((ft_strequ(wst->room->name, lem->end->name)))
		clear_way = way_saving(wst, lem);
	way_erase(way);
	return (clear_way);
}

static void		main_alg_helper(t_ways *ways, t_lem *lem)
{
	delete_un_optimal(&ways, lem);
	find_cross_ways(&ways, lem);
	fill_serial_number(ways);
	sort_by_lenght(&ways);
}

static t_ways	*main_alg(t_lem *lem, t_way *first)
{
	t_ways	*ways;
	t_ways	*new;
	t_ways	*curr;
	t_way	*wst;

	ways = new_ways(first, NULL);
	ways_re_lock(lem, ways);
	curr = ways;
	while ((wst = find_more_ways(lem)))
	{
		new = new_ways(wst, curr);
		lem->way_count++;
		curr->next = new;
		curr = curr->next;
		remove_same_edge(ways);
		ways_re_lock(lem, ways);
		parse_true_lenght(ways);
		if (!(find_lines_of_answer(lem, ways)))
		{
			new->delete = 1;
			break ;
		}
	}
	main_alg_helper(ways, lem);
	return (ways);
}

void			ant_alg(t_lem *lem, t_way *first_way, char *map)
{
	t_ways	*ways;

	ft_putendl(map);
	if (is_one_path(lem))
		print_one_path_to_end(lem);
	else
	{
		ways = main_alg(lem, first_way);
		if (!ways)
			error_exit(lem, 1);
		print_ant_ways(lem, ways);
		fill_max_ants(lem, ways);
		print_full_moves(lem, ways);
		remove_ways(ways);
	}
}
