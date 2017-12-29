/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:23:36 by bait-sli          #+#    #+#             */
/*   Updated: 2017/12/14 17:23:39 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void put_data(t_vertice *vertice, char *line, t_env *env)
{
  char **tmp;

  tmp = ft_strsplit(line, ' ');
  if(env->verif.start_ok == 1)
  {
    vertice->usage = 1;
    env->verif.start_ok = 2;
  }
  if(env->verif.end_ok == 1)
  {
    vertice->usage = 2;
    env->verif.end_ok = 2;
  }
  vertice->name = ft_strdup(tmp[0]);
  vertice->x = ft_atoi(tmp[1]);
  vertice->y = ft_atoi(tmp[2]);
  free(tmp);
}

void ft_add_vertice(t_vertice **map, char *line, t_env *env)
{
  t_vertice *elem;

  elem = (t_vertice*)malloc(sizeof(t_vertice) * 1);
  put_data(elem, line, env);
  if(map)
  {
    if(elem)
      elem->next = *map;
    *map = elem;
  }
}
