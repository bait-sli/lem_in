/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:23:44 by bait-sli          #+#    #+#             */
/*   Updated: 2017/12/14 17:23:46 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void delete_one(t_path **path)
{
  t_path *tmp;
  t_path *rmv;

  if(!path || path == NULL)
    return ;
  rmv = *path;
  if(rmv)
  {
    tmp = rmv->next;
    ft_memdel((void**)rmv);
    *path = tmp;
  }
}

void add_to_path(char *line, t_path **path)
{
  t_path *elem;

  elem = (t_path*)malloc(sizeof(t_path) * 1);
  elem->step = ft_strdup(line);
  if(path)
  {
    if(elem)
      elem->next = *path;
    *path = elem;
  }
  else
    *path = elem;
}
