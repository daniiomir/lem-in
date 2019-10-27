/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 19:04:43 by swarner           #+#    #+#             */
/*   Updated: 2019/10/27 19:55:56 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ant_algorythm(t_lem *lem)
{
	if (is_one_path(lem))
		print_one_path(lem);
	else
		ft_putstr("\nSyyrballe will be here soon\n");
}
