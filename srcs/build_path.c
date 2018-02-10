/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:23:44 by bait-sli          #+#    #+#             */
/*   Updated: 2018/02/09 03:01:08 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			delete_one(t_path **path)
{
	t_path		*tmp;
	t_path		*rmv;

	if (!path || path == NULL)
		return ;
	rmv = *path;
	if (rmv)
	{
		tmp = rmv->next;
		free(rmv->step);
		free(rmv);
		*path = tmp;
	}
}

void			ft_explored_node(t_vertice **map, char *format)
{
	t_vertice	*elem;

	elem = *map;
	while (elem != NULL)
	{
		if (ft_strcmp(format, elem->name) == 0)
		{
			elem->explored = 1;
			break ;
		}
		elem = elem->next;
	}
}

char			*get_last_path_elem(t_path **path, t_env *env)
{
	t_path		*elem;

	elem = *path;
	if (!elem || !elem->step)
		ft_error(ERR, env);
	return (ft_strdup(elem->step));
}

int				vcheck(t_vertice **map, char *format)
{
	t_vertice	*elem;

	elem = *map;
	while (elem != NULL)
	{
		if (ft_strcmp(format, elem->name) == 0 && elem->explored == 0)
			return (1);
		elem = elem->next;
	}
	return (0);
}

void			add_to_path(char *line, t_path **path)
{
	t_path		*elem;

	if (!(elem = (t_path*)malloc(sizeof(t_path) * 1)))
		return ;
	elem->step = ft_strdup(line);
	if (path)
	{
		if (elem)
			elem->next = *path;
		*path = elem;
	}
	else
	{
		*path = elem;
		elem->next = NULL;
	}
}
