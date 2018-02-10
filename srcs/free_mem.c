/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 03:08:47 by bait-sli          #+#    #+#             */
/*   Updated: 2018/02/09 03:14:44 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			free_split(char **content)
{
	int			index;

	if (!content)
		return ;
	index = 0;
	while (content[index])
	{
		free(content[index]);
		index++;
	}
}

void			free_network(t_pipe **network)
{
	t_pipe		*elem;
	t_pipe		*save;

	if (!network)
		return ;
	elem = *network;
	while (elem)
	{
		save = elem->next;
		free(elem->room1);
		free(elem->room2);
		free(elem);
		elem = save;
	}
}

void			free_map(t_vertice **map)
{
	t_vertice	*elem;
	t_vertice	*save;

	if (!map)
		return ;
	elem = *map;
	while (elem)
	{
		save = elem->next;
		free(elem->name);
		free(elem);
		elem = save;
	}
}

void			free_path(t_path **path)
{
	t_path		*save;
	t_path		*elem;

	if (!path)
		return ;
	elem = *path;
	while (elem)
	{
		save = elem->next;
		free(elem->step);
		free(elem);
		elem = save;
	}
}
