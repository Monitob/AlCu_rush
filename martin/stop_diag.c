/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_diag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 19:51:48 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/09 19:54:26 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

static int		stop_right_diag(t_map *s_map, int line, int col)
{
	int		i;
	int		j;
	int		flag;
	int		play;

	i = line;
	j = col;
	flag = 0;
	play = -1;
	while (i < s_map->line && j < s_map->col && i < (line + 3) && j < (col + 3))
	{
		if (s_map->map[i][j] == P_ONE)
			flag++;
		i++;
		j++;
	}
	if (flag == 3)
	{
		if (can_i_play(s_map, (line - 1), (col - 1)))
			play = col - 1;
		else if (can_i_play(s_map, (line + 3), (col + 3)))
			play = col + 3;
	}
	return (play);
}

static int		stop_left_diag(t_map *s_map, int line, int col)
{
	int		i;
	int		j;
	int		flag;
	int		play;

	i = line;
	j = col;
	flag = 0;
	play = -1;
	while (i < s_map->line && j >= 0 && i < (line + 3) && j > (col - 3))
	{
		if (s_map->map[i][j] == P_ONE)
			flag++;
		i++;
		j--;
	}
	if (flag == 3)
	{
		if (can_i_play(s_map, (line - 1), (col + 1)))
			play = col - 1;
		else if (can_i_play(s_map, (line + 3), (col - 3)))
			play = col + 3;
	}
	return (play);
}

int				stop_diag(t_map *s_map)
{
	int		i;
	int		j;
	int		play;

	i = 0;
	play = -1;
	while (i < s_map->line)
	{
		j = 0;
		while (j < s_map->col)
		{
			if (s_map->map[i][j] == P_ONE)
			{
				if ((play = stop_right_diag(s_map, i, j)) > -1)
					;
				else
					play = stop_left_diag(s_map, i, j);
			}
			if (play != -1)
				return (play) ;
			j++;
		}
		i++;
	}
	return (play);
}
