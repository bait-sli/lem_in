/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:23:52 by bait-sli          #+#    #+#             */
/*   Updated: 2018/02/09 03:07:05 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_cnt_parts(const char *s, char c)
{
	int			cnt;
	int			in_substring;

	in_substring = 0;
	cnt = 0;
	while (*s != '\0')
	{
		if (in_substring == 1 && *s == c)
			in_substring = 0;
		if (in_substring == 0 && *s != c)
		{
			in_substring = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

int				ft_is_digit(char *line)
{
	int			i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

int				ft_is_cmd(char *line)
{
	if (ft_strcmp(line, STR) == 0)
		return (1);
	if (ft_strcmp(line, END) == 0)
		return (2);
	if (line[0] == '#' && (ft_strcmp(line, STR) != 0) &&
			(ft_strcmp(line, END) != 0))
		return (3);
	return (0);
}

int				ft_is_pipe(char *line)
{
	if (ft_cnt_parts(line, '-') == 2)
		return (1);
	return (0);
}

int				ft_is_vertice(char *line)
{
	char		**tmp;

	tmp = ft_strsplit(line, ' ');
	if (line[0] != 'L' && line[0] != '#' && ft_cnt_parts(line, ' ') == 3)
	{
		if ((ft_is_digit(tmp[1]) == 1) && (ft_is_digit(tmp[2]) == 1))
		{
			free_split(tmp);
			free(tmp);
			return (1);
		}
	}
	free_split(tmp);
	free(tmp);
	return (0);
}
