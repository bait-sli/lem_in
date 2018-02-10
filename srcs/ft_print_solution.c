/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_solution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 03:20:34 by bait-sli          #+#    #+#             */
/*   Updated: 2018/02/09 03:28:33 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*get_current_room(t_path **path, int index)
{
	char	*ret;
	t_path	*elem;
	int		i;

	ret = NULL;
	i = 0;
	elem = *path;
	while (i <= index && elem != NULL)
	{
		if (i == index)
		{
			ret = ft_strdup(elem->step);
			break ;
		}
		i++;
		elem = elem->next;
	}
	return (ret);
}

static void	display_ants(t_path **path, int *tab)
{
	int		i;
	char	*ret;

	ret = NULL;
	i = 0;
	ft_putchar('\n');
	while (i < path_cnt(path) - 1)
	{
		if (tab[i] > 0)
		{
			ft_putchar('L');
			ft_putnbr(tab[i]);
			ft_putchar('-');
			ret = get_current_room(path, i + 1);
			ft_putstr(ret);
			ft_putchar(' ');
			free(ret);
		}
		i++;
	}
}

static int	ft_ants_max(int *tab, int len, int ants)
{
	int		i;

	i = -1;
	while (++i < len)
	{
		if (tab[i] == ants)
			return (i);
	}
	return (-1);
}

void		step_one(t_path **path, int *tab, int ants)
{
	int		i;
	int		j;

	i = -1;
	display_ants(path, tab);
	while (++i < ants - 1)
	{
		j = -1;
		while (++j < path_cnt(path) - 1)
		{
			if (tab[j] != 0)
				tab[j] = tab[j] + 1;
			else
			{
				tab[j] = 1;
				break ;
			}
		}
		display_ants(path, tab);
	}
}

void		step_two(t_path **path, int *tab, int ants)
{
	int		i;
	int		j;

	i = -1;
	while (++i < path_cnt(path) - 1)
	{
		j = ft_ants_max(tab, path_cnt(path) - 1, ants);
		while (j < path_cnt(path) - 1)
		{
			if (tab[j] == ants)
				tab[j] = 0;
			else if (tab[j] != 0 && tab[j] < ants)
				tab[j] = tab[j] + 1;
			else
			{
				tab[j] = 1;
				break ;
			}
			j++;
		}
		display_ants(path, tab);
	}
}
