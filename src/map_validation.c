/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:14:08 by cnikia            #+#    #+#             */
/*   Updated: 2019/10/21 17:14:09 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	map_check(t_lem *lem)
{
	t_path	*wst;

	if (lem->ants < 0)
		error_exit(lem, 1);
	ft_putstr((*lem).start->name);
	ft_putchar('\n');
	ft_putstr((*lem).end->name);
	ft_putchar('\n');
	wst = (*lem).way;
	while (wst)
	{
		ft_putstr(wst->name);
		ft_putchar('\n');
		wst = wst->prev;
	}
}