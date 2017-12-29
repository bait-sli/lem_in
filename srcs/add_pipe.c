/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:22:53 by bait-sli          #+#    #+#             */
/*   Updated: 2017/12/14 17:23:03 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void put_data(t_pipe *connect, char *line)
{
  char **tmp;

  tmp = ft_strsplit(line, '-');
  connect->room1 = ft_strdup(tmp[0]);
  connect->room2 = ft_strdup(tmp[1]);
  connect->call = 0;
  free(tmp);
}

static int ft_ok(char *str, t_vertice **map)
{
  t_vertice *elem;

  elem = *map;
  while(elem != NULL)
  {
    if(ft_strcmp(str, elem->name) == 0)
      return(1);
    elem = elem->next;
  }
  return(0);
}

void ft_add_pipe(t_pipe **network, char *line, t_env *env)
{
  t_pipe *elem;

  elem = (t_pipe*)malloc(sizeof(t_pipe) * 1);
  put_data(elem, line);
  if(ft_ok(elem->room1, &env->map) == 1 && ft_ok(elem->room2, &env->map) == 1 && ft_strcmp(elem->room1, elem->room2) != 0)
  {
    if(network)
    {
      if(elem)
        elem->next = *network;
      *network = elem;
    }
  }
}
