/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 03:07:38 by bait-sli          #+#    #+#             */
/*   Updated: 2018/02/09 03:08:19 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_env(t_env *env)
{
	free_network(&env->network);
	free_map(&env->map);
	free_path(&env->path);
}

void	ft_error(char *str, t_env *env)
{
	free_env(env);
	ft_putendl(str);
	exit(EXIT_FAILURE);
}
