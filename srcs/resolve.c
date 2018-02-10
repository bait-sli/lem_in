/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 03:38:08 by bait-sli          #+#    #+#             */
/*   Updated: 2018/02/09 04:10:51 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char			*ft_find(char *step, char *room1, char *room2)
{
	char			*ret;

	if (ft_strcmp(step, room1) == 0)
		ret = ft_strdup(room2);
	else
		ret = ft_strdup(room1);
	return (ret);
}

static void			node_validity(char *node, char *s, t_env *env, int index)
{
	if (index == 1)
	{
		add_to_path(node, &env->path);
		ft_explored_node(&env->map, node);
	}
	free(s);
	free(node);
}

static void			ft_backtracking(char *s, t_env *env, char *e, t_pipe **n)
{
	free(s);
	delete_one(&env->path);
	ft_recursive(e, env, n);
}

void				ft_recursive(char *end, t_env *env, t_pipe **network)
{
	t_pipe			*p;
	char			*s[2];

	s[0] = get_last_path_elem(&env->path, env);
	p = *network;
	while (p != NULL)
	{
		if ((ft_strcmp(s[0], p->room1) == 0 || ft_strcmp(s[0], p->room2) == 0))
		{
			s[1] = ft_find(s[0], p->room1, p->room2);
			if (ft_strcmp(end, s[1]) == 0)
			{
				node_validity(s[1], s[0], env, 0);
				return (add_to_path(s[1], &env->path));
			}
			else if (ft_strcmp(end, s[1]) != 0 && vcheck(&env->map, s[1]) == 1)
			{
				node_validity(s[1], s[0], env, 1);
				return (ft_recursive(end, env, network));
			}
			free(s[1]);
		}
		p = p->next;
	}
	ft_backtracking(s[0], env, end, network);
}
