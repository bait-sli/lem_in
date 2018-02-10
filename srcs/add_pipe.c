/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:22:53 by bait-sli          #+#    #+#             */
/*   Updated: 2018/02/09 02:50:08 by bait-sli         ###   ########.fr       */
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

static void		put_data(t_pipe *connect, char *line)
{
	char		**tmp;

	tmp = ft_strsplit(line, '-');
	connect->room1 = ft_strdup(tmp[0]);
	connect->room2 = ft_strdup(tmp[1]);
	free_split(tmp);
	free(tmp);
}

int				ft_add_pipe(t_pipe **network, char *line, t_env *env)
{
	t_pipe		*elem;

	if (!(elem = (t_pipe*)malloc(sizeof(t_pipe) * 1)))
		return (0);
	put_data(elem, line);
	if (ft_verif(elem->room1, &env->map) == 1 && ft_verif(elem->room2,
				&env->map) == 1 && ft_strcmp(elem->room1, elem->room2) != 0)
	{
		if (network)
		{
			if (elem)
				elem->next = *network;
			*network = elem;
		}
		else
		{
			*network = elem;
			elem->next = NULL;
		}
		return (1);
	}
	ft_memdel((void**)elem);
	return (0);
}
