/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:28:01 by cnikia            #+#    #+#             */
/*   Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			add_link(t_lem *lem, char *str)
{
	char	**string;
	t_path	*curr;
	t_path	*plus;
	t_link	*wst;

	string = ft_strsplit(str, '-');
	if (!string[0] || !string[1] || string[2] || !lem->way)
		error_exit(lem, 1);
	curr = (*lem).way;
	while ((!ft_strequ(string[0], curr->name)) && curr->prev)
		curr = curr->prev;
	plus = (*lem).way;
	while ((!ft_strequ(string[1], plus->name)) && plus->prev)
		plus = plus->prev;
	if (!ft_strequ(string[0], curr->name) || !ft_strequ(string[1], plus->name))
		error_exit(lem, 1);
	if (!(curr->link))
		curr->link = new_link(plus);
	else
	{
		wst = curr->link;
		while (wst->next)
			wst = wst->next;
		wst->next = new_link(plus);
	}
	if (!(plus->link))
		plus->link = new_link(curr);
	else
	{
		wst = plus->link;
		while (wst->next)
			wst = wst->next;
		wst->next = new_link(curr);
	}
	free(string[0]);
	free(string[1]);
	free(string);
}

static int		check_equal_rooms(t_lem *lem, char *room_name)
{
	t_path	*check;

	check = lem->way;
	while (check)
	{
		if (ft_strequ(room_name, check->name))
			return (1);
		check = check->next;
	}
	return (0);
}

void			fill_rooms(t_lem *lem, char **str,
	const int *start, const int *end)
{
	t_path	*prev;
	t_path	*new;
	char	**string;

	prev = NULL;
	string = ft_strsplit(*str, ' ');
	if (!string[0] || !string[1] || !string[2] || string[3]
	|| check_equal_rooms(lem, string[0]))
		error_exit(lem, 1);
	new = new_path(string[0], ft_atoi(string[1]), ft_atoi(string[2]));
	if (*start && !lem->start)
		lem->start = new;
	else if (*end && !lem->end)
		lem->end = new;
	if (!lem->way)
		lem->way = new;
	else
	{
		while (lem->way)
		{
			prev = lem->way;
			lem->way = lem->way->next;
		}
		lem->way = new;
		prev->next = new;
	}
	lem->way->prev = prev;
	free(string[1]);
	free(string[2]);
	free(string);
}
