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

void	room_fill()
{
	ft_putchar('a');
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
			room_fill();
	}
}