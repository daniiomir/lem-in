/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:05:17 by swarner           #+#    #+#             */
/*   Updated: 2019/10/15 17:05:19 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
​
t_path	*new_path(char *name)
{
	t_path	*new;
	if ((new = (t_path *)malloc(sizeof(t_path))))
	{
		new->link = NULL;
		new->next = NULL;
		new->name = name;
	}
	return (new);
}
​
t_link	*new_link(t_path *room)
{
	t_link	*new;
​
	if ((new = (t_link *)malloc(sizeof(t_link))))
	{
		new->path = room;
		new->next = NULL;
	}
	return (new);
}
