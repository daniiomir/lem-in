/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 16:24:12 by swarner           #+#    #+#             */
/*   Updated: 2019/10/17 18:01:03 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "lem_in.h"

static int		first_line(t_lem *lem, char *str, int line_number)
{
	lem->ants = ft_atoi(str);
	return (line_number + 1);
}

static void	fill_rooms(t_lem *lem, char *str, int *start, int *end)
{
	char **string;

	string = ft_strsplit(str, ' ');
	if (*start)
	{
		*start = 0;
		lem->start->name = string[0];
		lem->start->coords[0] = ft_atoi(string[1]);
		lem->start->coords[1] = ft_atoi(string[2]);
	}
	if (*end)
	{
		*end = 0;
		lem->end->name = string[0];
		lem->end->coords[0] = ft_atoi(string[1]);
		lem->end->coords[1] = ft_atoi(string[2]);
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
	end = 0;
	line_number = 0;
	while (ret > 0)
	{
		while ((ret = get_next_line(fd, &str)))
		{
			if (digit_check(str) && !line_number)
				line_number = first_line(lem, str, line_number);
			if (ft_strequ("##start", str) && !start)
			{
				start = 1;
				break ;
			}
			else if (ft_strequ("##end", str) && !end)
			{
				end = 1;
				break ;
			}
			if (!ft_strchr(str, '-') && !ft_strchr(str, '#'))
				fill_rooms(lem, str, &start, &end);
//			else if (str[0] != '#' && !ft_strchr(str, '-') && str[0] != 'L' && line_number > 1)
//				room_fill(str, lem);
			line_number++;
		}
	}
}

int		main(int argc, char **argv)
{
	int 	fd;
	int 	ret;
	t_lem	lem;

	ret = 1;
	init_lem(&lem);
	if (argc == 1)
		parse_map(&lem, ret, 0);
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		parse_map(&lem, ret, fd);
		close(fd);
	}
}
