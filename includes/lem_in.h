/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:24:50 by bait-sli          #+#    #+#             */
/*   Updated: 2018/02/09 04:12:35 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"

# define STR "##start"
# define END "##end"
# define ERR "ERROR"

typedef struct			s_verif
{
	int					start_ok;
	int					end_ok;
	int					ants_ok;
	int					end_vertice;
}						t_verif;

typedef struct			s_pipe
{
	char				*room1;
	char				*room2;
	struct s_pipe		*next;
}						t_pipe;

typedef struct			s_vertice
{
	char				*name;
	int					usage;
	int					explored;
	int					x;
	int					y;
	struct s_vertice	*next;
}						t_vertice;

typedef struct			s_path
{
	char				*step;
	struct s_path		*next;
}						t_path;

typedef struct			s_env
{
	t_pipe				*network;
	t_vertice			*map;
	int					ants_nbr;
	t_path				*path;
	t_verif				verif;
}						t_env;

void					ft_parse(t_env *env);
int						ft_is_digit(char *line);
int						ft_is_cmd(char *line);
int						ft_is_pipe(char *line);
int						ft_is_vertice(char *line);
int						ft_add_vertice(t_vertice **map, char *line, t_env *env);
int						ft_add_pipe(t_pipe **network, char *line, t_env *env);
void					ft_resolve(t_env *env);
void					delete_one(t_path **path);
void					add_to_path(char *line, t_path **path);
void					ft_print_result(t_path **path, int ants);
void					ft_error(char *str, t_env *env);
void					free_network(t_pipe **network);
void					free_map(t_vertice **map);
void					free_path(t_path **path);
void					free_split(char **content);
void					free_env(t_env *env);
int						vcheck(t_vertice **map, char *format);
char					*get_last_path_elem(t_path **path, t_env *env);
void					ft_explored_node(t_vertice **map, char *format);
void					ft_recursive(char *end, t_env *env, t_pipe **network);
void					step_one(t_path **path, int *tab, int ants);
void					step_two(t_path **path, int *tab, int ants);
int						path_cnt(t_path **path);

#endif
