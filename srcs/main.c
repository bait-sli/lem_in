/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:24:25 by bait-sli          #+#    #+#             */
/*   Updated: 2017/12/14 17:24:27 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void ft_init(t_env *env)
{
  env->network = NULL;
  env->map = NULL;
  env->path = NULL;
  env->ants_nbr = 0;
  env->start_ants = 0;
  env->end_ants = 0;
  env->verif.ants_ok = 0;
  env->verif.start_ok = 0;
  env->verif.end_ok = 0;
  env->verif.end_vertice = 0;
  env->matched = 0;
}

static void print_vertice(t_vertice **map)
{
  t_vertice *elem;

  elem = *map;
  while(elem != NULL)
  {
    printf("name: %s usage %d\n", elem->name, elem->usage);
    elem = elem->next;
  }
}

static void print_path(t_path **path)
{
  t_path *elem;

  elem = *path;
  while(elem != NULL)
  {
    printf("SOLUTION: %s\n", elem->step);
    elem = elem->next;
  }
}

static void print_network(t_pipe **network)
{
  t_pipe *elem;

  elem = *network;
  while(elem != NULL)
  {
    printf("room1: %s room2 %s\n", elem->room1, elem->room2);
    elem = elem->next;
  }
}
int main(void)
{
  t_env env;

  ft_init(&env);
  ft_parse(&env);
  printf("ANTS NBR: %d\n", env.ants_nbr);
  print_vertice(&env.map);
  print_network(&env.network);
  ft_resolve(&env);
  print_path(&env.path);
  return(0);
}
