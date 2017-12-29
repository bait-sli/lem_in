/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:24:50 by bait-sli          #+#    #+#             */
/*   Updated: 2017/12/14 17:24:52 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define STR "##start"
# define END "##end"
# define ERR "Error"
# define WARNING "USAGE: bad line was detected parse abort!"

# define DEBUG() printf("USAGE: OK!\n");

typedef double t_dec;

typedef struct s_verif
{
  int start_ok;
  int end_ok;
  int ants_ok;
  int end_vertice;
}              t_verif;

typedef struct s_pipe
{
  char *room1;
  char *room2;
  t_dec length;
  int call;
  struct s_pipe *next;
}               t_pipe;

typedef struct s_vertice
{
  char *name;
  int usage;
  int x;
  int y;
  struct s_vertice *next;
}               t_vertice;

typedef struct s_path
{
  char *step;
  struct s_path *next;
}             t_path;

typedef struct s_env
{
  t_pipe *network;
  t_vertice *map;
  int ants_nbr;
  int start_ants;
  int end_ants;
  t_path *path;
  t_verif verif;
  int *matched;
}             t_env;

void ft_parse(t_env *env);
int ft_is_digit(char *line);
int ft_is_cmd(char *line);
int ft_is_pipe(char *line);
int ft_is_vertice(char *line);

void ft_add_vertice(t_vertice **map, char *line, t_env *env);
void ft_add_pipe(t_pipe **network, char *line, t_env *env);
void ft_resolve(t_env *env);

void delete_one(t_path **path);
void add_to_path(char *line, t_path **path);

#endif
