/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <cnikia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:55:19 by cnikia            #+#    #+#             */
/*   Updated: 2019/11/01 14:36:22 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

typedef struct		s_link
{
	struct s_path	*path;
	int				lock;
	struct s_link	*next;
}					t_link;

typedef struct		s_path
{
	char			*name;
	int				coords[2];
	int				lock;
	int				range;
	int				block_range;
	struct s_link	*link;
	struct s_path	*next;
	struct s_path	*prev;
}					t_path;

typedef struct		s_lem
{
	struct s_path	*way;
	struct s_path	*start;
	struct s_path	*end;
	int				ants;
	int				way_count;
	int				*ant_count_on_path;
	int				lines_of_answer;
	int				max_ants;
}					t_lem;

typedef struct		s_way
{
	struct s_path	*room;
	struct s_link	*prev_link;
	int				lenght;
	struct s_way	*prev;
	struct s_way	*next;
}					t_way;

typedef struct		s_ways
{
	struct s_way	*way;
	int				num;
	int				delete;
	struct s_ways	*next;
	struct s_ways	*prev;
}					t_ways;

typedef struct		s_ant
{
	int				number;
	int				reached_end;
	struct s_way	*way;
}					t_ant;

t_path				*new_path(char *name, int x, int y);
t_link				*new_link(t_path *room);
t_way				*new_way(void);
t_ways				*new_ways(t_way *way, t_ways *prev);
t_ant				*create_ant(int ant_number, t_way *way);
t_ant				**create_ant_table(t_lem *lem, t_ways *way);
void				remove_ant_table(t_lem *lem, t_ant **ant_table);
void				init_lem(t_lem *lem);

void				error_exit(t_lem *lem, int error);
void				remove_ways(t_ways *ways);
void				way_erase(t_way *way);
void				remove_only_one_ways(t_ways *ways);
void				remove_only_ways(t_ways *ways);

t_way				*way_parse(t_lem *lem);
void				find_way(t_way *way);
t_way				*way_saving(t_way *way, t_lem *lem);
void				way_free_lock(t_lem *lem);
void				ways_re_lock(t_lem *lem, t_ways *ways);

void				parse_map(t_lem *lem, int ret, int fd, char **map);
void				free_str(char **str);
int					first_line(t_lem *lem, char *str, int line_number);
void				start_end_errors(t_lem *lem, int start, int end);
void				add_map(char **map, char *str);
void				add_link(t_lem *lem, char *str);
void				fill_rooms(t_lem *lem, char **str,
						const int *start, const int *end);
t_way				*map_check(t_lem *lem);

int					find_cross_ways(t_ways **ways, t_lem *lem);
void				remove_same_edge(t_ways *ways);
void				parse_true_lenght(t_ways *ways);
void				fill_serial_number(t_ways *ways);
int					find_lines_of_answer(t_lem *lem, t_ways *ways);
void				delete_un_optimal(t_ways **ways, t_lem *lem);
void				sort_by_lenght(t_ways **ways);

void				fill_max_ants(t_lem *lem, t_ways *ways);
void				print_moves(int ant_number, char *room);
void				print_full_moves(t_lem *lem, t_ways *ways);
void				print_one_path_to_end(t_lem *lem);
int					is_one_path(t_lem *lem);
int					all_ants_done(t_ant **ant_table, t_lem *lem);
void				print_full_moves(t_lem *lem, t_ways *ways);
void				moves_many_ways_part(t_lem *lem, t_ant **ant_table);

void				ant_alg(t_lem *lem, t_way *first, char *map);
void				print_ant_ways(t_lem *lem, t_ways *ways);

#endif
