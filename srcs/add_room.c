/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:23:36 by bait-sli          #+#    #+#             */
/*   Updated: 2018/02/09 02:54:39 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_verif(char *str, t_vertice **map)
{
	t_vertice	*elem;

	elem = *map;
	while (elem != NULL)
	{
		if (ft_strcmp(str, elem->name) == 0)
			return (1);
		elem = elem->next;
	}
	return (0);
}

static void		put_data(t_vertice *vertice, char *line, t_env *env)
{
	char		**tmp;

	tmp = ft_strsplit(line, ' ');
	vertice->usage = 0;
	if (env->verif.start_ok == 1)
	{
		vertice->usage = 1;
		env->verif.start_ok = 2;
	}
	if (env->verif.end_ok == 1)
	{
		vertice->usage = 2;
		env->verif.end_ok = 2;
	}
	vertice->explored = 0;
	vertice->name = ft_strdup(tmp[0]);
	vertice->x = ft_atoi(tmp[1]);
	vertice->y = ft_atoi(tmp[2]);
	free_split(tmp);
	free(tmp);
}

int				ft_add_vertice(t_vertice **map, char *line, t_env *env)
{
	t_vertice	*elem;

	if (!(elem = (t_vertice*)malloc(sizeof(t_vertice) * 1)))
		return (0);
	put_data(elem, line, env);
	if (ft_verif(elem->name, &env->map) == 0)
	{
		if (map)
		{
			if (elem)
				elem->next = *map;
			*map = elem;
		}
		else
		{
			*map = elem;
			elem->next = NULL;
		}
		return (1);
	}
	ft_memdel((void**)elem);
	return (0);
}
