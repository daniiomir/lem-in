/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 22:09:15 by cnikia            #+#    #+#             */
/*   Updated: 2019/11/09 22:09:17 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		fill_max_ants(t_lem *lem, t_ways *ways)
{
	t_ways	*wst;
	int 	max_ants;

	wst = ways;
	max_ants = 0;
	while (wst)
	{
		max_ants += wst->way->lenght - 1;
		wst = wst->next;
	}
	lem->max_ants = max_ants;
}

void		parse_true_lenght(t_ways *ways)
{
	t_ways	*wst;
	t_way	*parse;
	int 	a;

	wst = ways;
	while (wst)
	{
		a = 0;
		parse = wst->way;
		while (parse)
		{
			parse = parse->next;
			a++;
		}
		parse = wst->way;
		while (parse)
		{
			parse->lenght = a;
			parse = parse->next;
		}
		wst = wst->next;
	}
}