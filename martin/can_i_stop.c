/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_i_stop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 19:51:45 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/08 20:58:29 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"
#include "libft.h" //?

//verifier le retour de play

int		can_i_play(t_map *s_map, int line, int col)
{
	if (line < s_map->line && col < s_map->col &&
		s_map->map[line][col] == EMPTY
		&& ((line + 1) == s_map->line || s_map->map[line - 1][col] != EMPTY))
		return (1);
	return (0);
}
/*
int		is_stop_line(t_map *s_map, int line, int col)
{
	if ((col + 1) < s_map->col && s_map->map[line][col + 1] == EMPTY
			&& (line + 1) <= s_map->line && ((line + 1) == s_map->line
			|| s_map->map[line + 1][col + 1] != EMPTY))
		return (col + 1);
	else if ((col - 3) >= 0 && s_map->map[line][col - 3] == EMPTY
			&& (line + 1) <= s_map->line && ((line + 1) == s_map->line
			|| s_map->map[line + 1][col - 3] != EMPTY))
		return (col - 3);
	return (-1);
}
*/

int		is_stop_line(t_map *s_map, int line, int col)
{
	if (can_i_play(s_map, line, col + 1))
		return (col + 1);
	else if (can_i_play(s_map, line, col - 3))
		return (col - 3);
	return (-1);
}

int		stop_line(t_map *s_map)
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
			if (s_map->map[i][j] == P_ONE)
				flag++;
			else if (s_map->map[i][j] == P_TWO || s_map->map[i][j] == EMPTY)
				flag = 0;
			if (flag == 3)
			{
				if (play = is_stop_line(s_map, i, j) > -1)
					return (play);
			}
			j++;
		}
		i++;
	}
	return (play);
}

int		is_stop_col(t_map *s_map, int line, int col)
{
	if ((line - 3) >= 0 && s_map[line - 3][col] == EMPTY
		&& s_map[line - 2][col] != EMPTY)
		return (col);
	return (-1);
}

int		stop_col(t_map *s_map)
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
			if (s_map->map[i][j] == P_ONE)
				flag++;
			else
				flag = 0;
			if (flag == 3)
			{
				if (play = is_stop_col(s_map, i, j) > -1)
					return (play);
			}
			i++;
		}
		j++;
	}
	return (play);
}

int		stop_right_diag(t_map *s_map, int line, int col)
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
		else (can_i_play(s_map, (line + 3), (col + 3)))
			play = col + 3;
	}
	return (play);
}

int		stop_left_diag(t_map *s_map, int line, int col)
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
		else (can_i_play(s_map, (line + 3), (col - 3)))
			play = col + 3;
	}
	return (play);
}

int		stop_diag(t_map *s_map)
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

int		can_i_stop(t_map *s_map)
{
	int		play;

	play = -1;
	if ((play = stop_line(s_map)) > -1)
		return (play);
	if ((play = stop_col(s_map)) > -1)
		return (play);
	if ((play = stop_diag(s_map)) > -1)
		return (play);
	return (play);
}
