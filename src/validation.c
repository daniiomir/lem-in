/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:24:44 by cnikia            #+#    #+#             */
/*   Updated: 2019/10/16 16:24:46 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		room_check(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != ' ')
			return (0);
		str++;
	}
	return (1);
}

void	room_fill(char *str, t_lem *lem)
{
	int 	a;
	int 	coords[2];
	char 	*name;
	t_path	*new;
	t_path	*curr;

	a = 0;
	b = 0;
	while (str[a] != ' ' && str[a])
		a++;
	if (!str[a])
		error(lem, "invalid room parameter.");
	if (!(name = (char *)maloc(sizeof(char) * a)))
		error(lem, "malloc error.");
	name[a] = '\0';
	a = 0;
	while (str[a] != ' ')
	{
		name[a] = str[a];
		a++;
	}
	a++;
	if (!room_check(str + a))
		error(lem, "invalid room parameter.");
	coords[0] = ft_atoi(str + a);
	while (ft_isdigit(str[a]) && str[a])
		a++;
	if (!str[a])
		error(lem, "invalid room parameter.");
	coords[1] = ft_atoi(str + a);
	new = new_path(name, coords[0], coords[1]);
	if (lem->way)
	{
		curr = lem->way;
		while (curr->next)
		{
			curr = curr->next;
		}
		curr->next = new;
	}
	else
		lem->way = new;
}

int		digit_check(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	read_map(t_lem *lem)
{
	char	*str;
	int 	wst;

	str = NULL;
	wst = 0;
	while (get_next_line(0, str))
	{
		if (digit_check(str) && wst == 0)
		{
			wst = 1;
			lem->ants = ft_atoi(str);
		}
		if (str[0] != '#' && !ft_strchr(str, '-') && str[0] != 'L')
			room_fill(str, lem);
	}
}