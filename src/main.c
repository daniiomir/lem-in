/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 16:24:12 by swarner           #+#    #+#             */
/*   Updated: 2019/11/01 15:25:34 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int argc, char **argv)
{
	int		ret;
	char	*map;
	t_lem	lem;
	t_way	*first_way;

	if (argc > 1 && argv[1])
		exit(0);
	else
	{
		ret = 1;
		map = ft_strnew(0);
		init_lem(&lem);
		if (argc == 1)
			parse_map(&lem, ret, 0, &map);
		first_way = map_check(&lem);
		ant_alg(&lem, first_way, map);
		error_exit(&lem, 0);
	}
}
