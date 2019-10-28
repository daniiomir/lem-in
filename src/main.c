/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 16:24:12 by swarner           #+#    #+#             */
/*   Updated: 2019/10/27 19:45:36 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "lem_in.h"

int		main(int argc, char **argv)
{
	int 	fd;
	int 	ret;
	t_lem	lem;
	t_way	*first_way;

	if (argc > 2)
		return (0);
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
	first_way = map_check(&lem);
	ant_algorythm(&lem, first_way);
	way_erase(first_way);
	error_exit(&lem, 0);
}
