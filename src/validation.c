/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:24:44 by cnikia            #+#    #+#             */
/*   Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr       */
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

void			start_end_errors(t_lem *lem, int start, int end)
{
	if (!start || !end || !lem->ants || !lem->way)
		error_exit(lem, 1);
}

void			add_map(char **map, char *str)
{
	*map = ft_strjoin_free(*map, str);
	*map = ft_strjoin_free(*map, "\n");
}

static void		first_part_check(t_lem *lem, char *str,
	int *line_number, int ret)
{
	if (ret == -1)
		error_exit(lem, 1);
	if (!*line_number)
		*line_number = first_line(lem, str, *line_number);
}

static void		start_end_instructions(t_lem *lem, int *start,
	char *str, char **map)
{
	(*start)++;
	if (*start > 1)
		error_exit(lem, 1);
	add_map(map, str);
	free_str(&str);
}

static void		for_links(t_lem *lem, char *str, int *line_number, char **map)
{
	if (ft_strchr(str, '-') && str[0] != '#'
		&& str[0] != 'L' && *line_number > 1)
		add_link(lem, str);
	(*line_number)++;
	add_map(map, str);
	if (str)
		free(str);
}

void			fuck_this_shit_im_done(int *start, char **str,
	int *end, int *line_number)
{
	*start = 0;
	*str = NULL;
	*end = 0;
	*line_number = 0;
}

void			parse_map(t_lem *lem, int ret, int fd, char **map)
{
	int		start;
	int		end;
	int		line_number;
	char	*str;

	fuck_this_shit_im_done(&start, &str, &end, &line_number);
	while ((ret = get_next_line(fd, &str)))
	{
		first_part_check(lem, str, &line_number, ret);
		if (ft_strequ("##start", str))
		{
			start_end_instructions(lem, &start, str, map);
			continue ;
		}
		else if (ft_strequ("##end", str))
		{
			start_end_instructions(lem, &end, str, map);
			continue ;
		}
		if (!ft_strchr(str, '-') && str[0] != '#'
		&& str[0] != 'L' && line_number > 1)
			fill_rooms(lem, &str, &start, &end);
		for_links(lem, str, &line_number, map);
	}
	start_end_errors(lem, start, end);
}
