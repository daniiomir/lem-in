/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:24:44 by cnikia            #+#    #+#             */
/*   Updated: 2019/10/27 18:55:13 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		free_str(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

static int		first_line(t_lem *lem, char *str, int line_number)
{
	ssize_t num;

	num = ft_atoi(str);
	if (num <= 0 || num > 2147483647)
		error_exit(lem, 1);
	lem->ants = num;
	return (line_number + 1);
}

static void	fill_rooms(t_lem *lem, char **str, const int *start, const int *end)
{
	t_path	*prev;
	t_path	*new;
	char	**string;

	prev = NULL;
	string = ft_strsplit(*str, ' ');
	if (!string[0] || !string[1] || !string[2] || string[3])
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

void	start_end_errors(t_lem *lem, int start, int end)
{
	if (!start || !end || !lem->ants || !lem->way)
		error_exit(lem, 1);
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
	while ((ret = get_next_line(fd, &str)))
	{
		if (ret == -1)
			error_exit(lem, 1);
		if (!line_number)
			line_number = first_line(lem, str, line_number);
		if (ft_strequ("##start", str))
		{
			start++;
			if (start > 1)
				error_exit(lem, 1);
			free_str(&str);
			continue ;
		}
		else if (ft_strequ("##end", str))
		{
			end++;
			if (end > 1)
				error_exit(lem, 1);
			free_str(&str);
			continue ;
		}
		if (!ft_strchr(str, '-') && str[0] != '#' && str[0] != 'L' && line_number > 1)
			fill_rooms(lem, &str, &start, &end);
		if (ft_strchr(str, '-') && str[0] != '#' && str[0] != 'L' && line_number > 1)
			add_link(lem, str);
		line_number++;
		ft_putendl(str);
		free_str(&str);
	}
	start_end_errors(lem, start, end);
}
