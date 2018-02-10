/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 03:28:49 by bait-sli          #+#    #+#             */
/*   Updated: 2018/02/09 03:33:10 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				path_cnt(t_path **path)
{
	t_path		*elem;
	int			count;

	count = 0;
	elem = *path;
	while (elem != NULL)
	{
		count++;
		elem = elem->next;
	}
	return (count);
}

static char		*get_start_end(t_vertice **map, int usage, t_env *env)
{
	t_vertice	*elem;

	elem = *map;
	while (elem != NULL)
	{
		if (elem->usage == usage)
			return (ft_strdup(elem->name));
		elem = elem->next;
	}
	ft_error(ERR, env);
	return (NULL);
}

static void		ft_bzero_tab(int *tab, int len)
{
	int			i;

	i = 0;
	while (i < len)
	{
		tab[i] = 0;
		i++;
	}
	tab[0] = 1;
}

void			ft_resolve(t_env *env)
{
	char		*start;
	char		*end;

	start = get_start_end(&env->map, 1, env);
	end = get_start_end(&env->map, 2, env);
	if (ft_strcmp(start, end) == 0)
		ft_error(ERR, env);
	add_to_path(start, &env->path);
	ft_explored_node(&env->map, start);
	ft_recursive(end, env, &env->network);
	free(start);
	free(end);
}

void			ft_print_result(t_path **path, int ants)
{
	int			*tab;

	if (!(tab = (int*)malloc(sizeof(int) * path_cnt(path) - 1)))
		return ;
	ft_bzero_tab(tab, path_cnt(path) - 1);
	step_one(path, tab, ants);
	step_two(path, tab, ants);
	free(tab);
}
