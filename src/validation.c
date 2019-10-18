/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:24:44 by cnikia            #+#    #+#             */
/*   Updated: 2019/10/17 17:57:55 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	map_check(t_lem *lem)
{
	if (lem->ants < 0)
		error_exit(lem, 1);
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

static int		first_line(t_lem *lem, char *str, int line_number)
{
	lem->ants = ft_atoi(str);
	return (line_number + 1);
}

static void	fill_rooms(t_lem *lem, char *str, int *start, int *end)
{
	t_path	*prev;
	char	**string;

	prev = NULL;
	string = ft_strsplit(str, ' ');
	if (*start)
		lem->start = new_path(string[0], ft_atoi(string[1]), ft_atoi(string[2]));
	else if (*end)
		lem->end = new_path(string[0], ft_atoi(string[1]), ft_atoi(string[2]));
	if (!lem->way)
		lem->way = new_path(string[0], ft_atoi(string[1]), ft_atoi(string[2]));
	else
	{
		while (lem->way)
		{
			prev = lem->way;
			lem->way = lem->way->next;
		}
		lem->way = new_path(string[0], ft_atoi(string[1]), ft_atoi(string[2]));
		lem->way->prev = prev;
	}
	free(string[1]);
	free(string[2]);
}

void	parse_map(t_lem *lem, int ret, int fd)
{
	int 	start;
	int 	end;
	int 	line_number;
	char 	*str;

	start = 0;
	str = NULL;
	end = 0;
	line_number = 0;
	while (ret > 0)
	{
		while ((ret = get_next_line(fd, &str)))
		{
			if (digit_check(str) && !line_number)
				line_number = first_line(lem, str, line_number);
			if (ft_strequ("##start", str))
			{
				if (start)
					error_exit(lem, 1);
				start = 1;
				break ;
			}
			else if (ft_strequ("##end", str))
			{
				if (end)
					error_exit(lem, 1);
				end = 1;
				break ;
			}
			if (!ft_strchr(str, '-') && str[0] != '#' && str[0] != 'L' && line_number > 1)
				fill_rooms(lem, str, &start, &end);
			line_number++;
			if (str)
			{
				free(str);
				str = NULL;
			}
		}
	}
}
