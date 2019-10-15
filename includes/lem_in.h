/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 16:21:30 by swarner           #+#    #+#             */
/*   Updated: 2019/10/06 16:21:33 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H

# include "libft.h"

typedef struct		s_link
{
	struct s_path	*path;
	struct s_link	*next;
}					t_link;
​
typedef struct		s_path
{
	char			*name;
	struct s_link	*link;
	struct s_path	*next;
	struct s_path	*prev;
}					t_path;
​
typedef struct		s_lem
{
	struct s_path	*way;
	struct s_path	*start;
	struct s_path	*end;
	int				ants;
}					t_lem;

#endif
