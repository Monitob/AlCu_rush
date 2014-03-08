/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_something.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 21:09:52 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/08 22:02:44 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "puissance4.h"


int		is_map_empty(t_map *s_map)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	flag = 0;
	while (i < s_map->line)
	{
		j = 0;
		while (j < s_map->col)
		{
			if (s_map->map[i][j] != EMPTY)
				flag++;
			j++;
		}
		i++;
	}
	return (flag);
}

int		is_play_line(t_map *s_map, int line, int col, int add)
{
	if (can_i_play(s_map, line, col + 1))
		return (col + 1);
	else if (can_i_play(s_map, line, col - add))
		return (col - add);
	return (-1);
}

int		find_line(t_map *s_map, int nb)
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
			if (s_map->map[i][j] == P_TWO)
				flag++;
			else if (s_map->map[i][j] != P_TWO)
				flag = 0;
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

int		is_play_col(t_map *s_map, int line, int col, int add)
{
	if ((line - add) >= 0 && s_map->map[line - add][col] == EMPTY
		&& s_map->map[line - (add - 1)][col] != EMPTY)
		return (col);
	return (-1);
}

int		find_col(t_map *s_map, int nb)
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
			if (s_map->map[i][j] == P_TWO)
				flag++;
			else
				flag = 0;
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

int		play_right_diag(t_map *s_map, int line, int col, int add)
{
	int		i;
	int		j;
	int		flag;
	int		play;

	i = line;
	j = col;
	flag = 0;
	play = -1;
	while (i < s_map->line && j < s_map->col && i < (line + add) && j < (col + add))
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

int		play_left_diag(t_map *s_map, int line, int col, int add)
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
		if (can_i_play(s_map, (line - 1), (col + 1)))
			play = col - 1;
		else if (can_i_play(s_map, (line + add), (col - add)))
			play = col + add;
	}
	return (play);
}


int		find_diag(t_map *s_map, int nb)
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

int		find_chip(t_map *s_map, int nb)
{
	int		play;

	play = -1;
	if ((play = find_line(s_map, nb)) > -1)
		return (play);
	if ((play = find_col(s_map, nb)) > -1)
		return (play);
	if ((play = find_diag(s_map, nb)) > -1)
		return (play);
	return (-1);
}
/*
int		find_one_chip(t_map *s_map)
{
	int		play;

	play = -1;
	if ((play = find_line(s_map, 1)) > -1)
		return (play);
	if ((play = find_col(s_map, 1)) > -1)
		return (play);
	if ((play = find_diag(s_map, 1)) > -1)
		return (play);
}
*/

int		play_random(t_map *s_map)
{
	int		i;
	int		j;
	time_t	_rand;

	_rand = time(NULL);
	srand(_rand);
	i = rand();
	j = rand();
	if (i <= j)
	{
		i = (s_map->col - 1);
		while (i >= 0)
		{
			if (is_play_ok(i, s_map))
				return (i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < s_map->col)
		{
			if (is_play_ok(i, s_map))
				return (i);
			i++;
		}
	}
	return (0);
}

int		play_something(t_map *s_map)
{
	int		play;

	play = -1;
	if (!is_map_empty(s_map))
		return (s_map->col / 2);
	if ((play = find_chip(s_map, 2)) > -1)
		return (play);
	if ((play = find_chip(s_map, 1)) > -1)
		return (play);
	play = play_random(s_map);
	return (play);
}
