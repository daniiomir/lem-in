/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 16:24:12 by swarner           #+#    #+#             */
/*   Updated: 2019/10/28 18:36:26 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "lem_in.h"

int		main(int argc, char **argv)
{
	int 	fd;
	int 	ret;
	char 	*map;
	t_lem	lem;
	t_way	*first_way;

	if (argc > 2)
		return (0);
	ret = 1;
	map = ft_strnew(0);
	init_lem(&lem);
	if (argc == 1)
		parse_map(&lem, ret, 0, &map);
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		parse_map(&lem, ret, fd, &map);
		close(fd);
	}
	first_way = map_check(&lem);
	ant_alg(&lem, first_way);
	ft_putstr(map);
	way_erase(first_way);
	error_exit(&lem, 0);
}
