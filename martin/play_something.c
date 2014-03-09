/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_something.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 21:09:52 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/09 20:08:12 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "puissance4.h"

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

int		play_from_right(int i, t_map *s_map)
{
	while (i >= 0)
	{
		if (!is_play_ok(i, s_map))
			return (i);
		i--;
	}
	return (0);
}

int		play_from_left(t_map *s_map)
{
	int		i;

	i = 0;
	while (i < s_map->col)
	{
		if (!is_play_ok(i, s_map))
			return (i);
		i++;
	}
	return (0);
}

int		play_random(t_map *s_map)
{
	int		i;
	time_t	_rand;
	int		play;

	play = 0;
	_rand = time(NULL);
	srand(_rand + 100);
	i = rand();
	if (i % 2 == 0)
		play = play_from_right(s_map->col - 1, s_map);
	else
		play = play_from_left(s_map);
	return (play);
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
