/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:28:01 by cnikia            #+#    #+#             */
/*   Updated: 2019/10/25 15:00:28 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_link(t_lem *lem, char *str)
{
	char	**string;
	t_path	*curr;
	t_path	*plus;
	t_link	*wst;

	string = ft_strsplit(str, '-');
	if (!string[0] || !string[1] || string[2])
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