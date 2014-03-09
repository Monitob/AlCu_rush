/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_col_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 20:02:21 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/09 20:04:36 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

static int		is_play_line(t_map *s_map, int line, int col, int add)
{
	if (can_i_play(s_map, line, col + 1))
		return (col + 1);
	else if (can_i_play(s_map, line, col - add))
		return (col - add);
	return (-1);
}

static int		check_flag(int flag, char c)
{
	if (c == P_TWO)
		return (flag + 1);
	return (0);
}

int				find_line(t_map *s_map, int nb)
{
	int		i;
	int		j;
	int		flag;
	int		play;

	i = 0;
	flag = 0;
	play = -1;
	while (i < s_map->line)
	{
		j = 0;
		while (j < s_map->col)
		{
			flag = check_flag(flag, s_map->map[i][j]);
			if (flag == nb)
			{
				if ((play = is_play_line(s_map, i, j, nb)) > -1)
					return (play);
			}
			j++;
		}
		i++;
	}
	return (play);
}

static int		is_play_col(t_map *s_map, int line, int col, int add)
{
	if ((line - add) >= 0 && s_map->map[line - add][col] == EMPTY
		&& s_map->map[line - (add - 1)][col] != EMPTY)
		return (col);
	return (-1);
}

int				find_col(t_map *s_map, int nb)
{
	int		i;
	int		j;
	int		flag;
	int		play;

	j = 0;
	flag = 0;
	play = -1;
	while (j < s_map->col)
	{
		i = 0;
		while (i < s_map->line)
		{
			flag = check_flag(flag, s_map->map[i][j]);
			if (flag == nb)
			{
				if ((play = is_play_col(s_map, i, j, nb)) > -1)
					return (play);
			}
			i++;
		}
		j++;
	}
	return (play);
}
