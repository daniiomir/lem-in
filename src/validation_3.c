/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:55:55 by cnikia            #+#    #+#             */
/*   Updated: 2019/11/12 18:58:45 by cnikia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_str(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

int		first_line(t_lem *lem, char *str, int line_number)
{
	ssize_t num;

	num = ft_atoi(str);
	if (num <= 0 || num > 2147483647)
		error_exit(lem, 1);
	lem->ants = num;
	return (line_number + 1);
}

void	start_end_errors(t_lem *lem, int start, int end)
{
	if (!start || !end || !lem->ants || !lem->way)
		error_exit(lem, 1);
}

void	add_map(char **map, char *str)
{
	*map = ft_strjoin_free(*map, str);
	*map = ft_strjoin_free(*map, "\n");
}
