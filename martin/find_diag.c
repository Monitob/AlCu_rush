/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_diag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 19:59:15 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/09 20:09:36 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

static int		play_right_diag(t_map *s_map, int line, int col, int add)
{
	int		i;
	int		j;
	int		flag;
	int		play;

	i = line;
	j = col;
	flag = 0;
	play = -1;
	while (i < s_map->line && j < s_map->col && i < (line + add)
		&& j < (col + add))
	{
		if (s_map->map[i][j] == P_TWO)
			flag++;
		i++;
		j++;
	}
	if (flag == add)
	{
		if (can_i_play(s_map, (line - 1), (col - 1)))
			play = col - 1;
		else if (can_i_play(s_map, (line + add), (col + add)))
			play = col + add;
	}
	return (play);
}

static int		play_left_diag(t_map *s_map, int line, int col, int add)
{
	int		i;
	int		j;
	int		flag;
	int		play;

	i = line;
	j = col;
	flag = 0;
	play = -1;
	while (i < s_map->line && j >= 0 && i < (line + add) && j > (col - add))
	{
		if (s_map->map[i][j] == P_TWO)
			flag++;
		i++;
		j--;
	}
	if (flag == add)
	{
		if (can_i_play(s_map, (line + add), (col - add)))
			play = col - add;
		else if (can_i_play(s_map, (line - 1), (col + 1)))
			play = col + 1;
	}
	return (play);
}

int				find_diag(t_map *s_map, int nb)
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
			if (s_map->map[i][j] == P_TWO)
			{
				if ((play = play_right_diag(s_map, i, j, nb)) > -1)
					;
				else
					play = play_left_diag(s_map, i, j, nb);
			}
			if (play != -1)
				return (play) ;
			j++;
		}
		i++;
	}
	return (play);
}
