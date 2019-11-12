/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortirovochka_dlya_algoritma_lol.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:17:46 by cnikia            #+#    #+#             */
/*   Updated: 2019/11/09 17:17:48 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		*init_lenght_of_path(t_ways *ways, t_lem *lem)
{
	t_ways	*wst;
	int		*lenght_of_path;
	int		a;

	lenght_of_path = (int *)malloc(sizeof(int) * lem->way_count);
	wst = ways;
	a = -1;
	while (wst && a++ < lem->way_count - 1)
	{
		lenght_of_path[a] = wst->way->lenght;
		wst = wst->next;
	}
	return (lenght_of_path);
}

static int		*init_ant_count_on_path(t_lem *lem,
		int *lines_of_answer, int *ants)
{
	int		*ant_count_on_path;
	int		a;

	*lines_of_answer = 0;
	*ants = lem->ants;
	ant_count_on_path = (int *)malloc(sizeof(int) * lem->way_count);
	a = -1;
	while (a++ < lem->way_count - 1)
		ant_count_on_path[a] = 0;
	return (ant_count_on_path);
}

static int		exit_one(t_lem *lem, int **ant_count_on_path,
		int lines_of_answer, int **lenght_of_path)
{
	free(lem->ant_count_on_path);
	lem->ant_count_on_path = *ant_count_on_path;
	lem->lines_of_answer = lines_of_answer;
	free(*lenght_of_path);
	return (1);
}

static int		exit_zero(int **ant_count_on_path, int **lenght_of_path)
{
	free(*ant_count_on_path);
	free(*lenght_of_path);
	return (0);
}

int				find_lines_of_answer(t_lem *lem, t_ways *ways)
{
	int		*lenght_of_path;
	int		*ant_count;
	int		a;
	int		ants;
	int		lines_of_answer;

	lenght_of_path = init_lenght_of_path(ways, lem);
	ant_count = init_ant_count_on_path(lem, &lines_of_answer, &ants);
	while (ants > 0)
	{
		a = 0;
		while (a < lem->way_count)
		{
			if (lenght_of_path[a] + ant_count[a] < lines_of_answer)
			{
				ant_count[a]++;
				ants--;
			}
			a++;
		}
		lines_of_answer++;
	}
	if (lem->lines_of_answer > lines_of_answer || !(lem->lines_of_answer))
		return (exit_one(lem, &ant_count, lines_of_answer, &lenght_of_path));
	return (exit_zero(&ant_count, &lenght_of_path));
}
