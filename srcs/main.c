/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:24:25 by bait-sli          #+#    #+#             */
/*   Updated: 2018/02/09 04:41:43 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_init(t_env *env)
{
	env->network = NULL;
	env->map = NULL;
	env->path = NULL;
	env->ants_nbr = 0;
	env->verif.ants_ok = 0;
	env->verif.start_ok = 0;
	env->verif.end_ok = 0;
	env->verif.end_vertice = 0;
}

static void		reverse(t_path **l)
{
	t_path		*inv;
	t_path		*head;

	inv = *l;
	if (inv && inv->next)
	{
		head = inv->next;
		reverse(&(inv->next));
		head->next = inv;
		*l = inv->next;
		head->next->next = NULL;
	}
}

int				main(void)
{
	t_env		env;

	ft_init(&env);
	ft_parse(&env);
	if (env.ants_nbr <= 0)
		ft_error(ERR, &env);
	ft_resolve(&env);
	reverse(&env.path);
	ft_print_result(&env.path, env.ants_nbr);
	free_env(&env);
	return (0);
}
