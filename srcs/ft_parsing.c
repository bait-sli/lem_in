/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:24:09 by bait-sli          #+#    #+#             */
/*   Updated: 2018/02/09 03:19:59 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		check_cmd(char *s, t_env *env)
{
	if (ft_is_cmd(s) == 1 && env->verif.start_ok == 0 && env->verif.end_ok != 1)
		env->verif.start_ok = 1;
	if (ft_is_cmd(s) == 2 && env->verif.end_ok == 0 && env->verif.start_ok != 1)
		env->verif.end_ok = 1;
}

static int		check_line(char *line, t_env *env)
{
	if (ft_is_digit(line) == 1 && env->verif.ants_ok == 0)
	{
		env->ants_nbr = ft_atoi(line);
		env->verif.ants_ok = 1;
		return (1);
	}
	if (ft_is_vertice(line) == 1 && env->verif.end_vertice == 0)
	{
		if (ft_add_vertice(&env->map, line, env) == 1)
			return (1);
	}
	if (ft_is_cmd(line) != 0)
	{
		check_cmd(line, env);
		return (1);
	}
	if (ft_is_pipe(line))
	{
		env->verif.end_vertice = 1;
		if (ft_add_pipe(&env->network, line, env) == 1)
			return (1);
	}
	return (0);
}

void			ft_parse(t_env *env)
{
	char		*line;

	while (get_next_line(0, &line) > 0)
	{
		if (check_line(line, env) == 0)
		{
			free(line);
			return ;
		}
		ft_putendl(line);
		free(line);
	}
}
