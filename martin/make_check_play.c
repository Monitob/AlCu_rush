/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_check_play.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 18:12:29 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/09 19:32:59 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

static int		is_valid(int col, t_map *s_map)
{
	int		i;

	i = 0;
	while (i < s_map->line)
	{
		if (s_map->map[i][col] == EMPTY)
			return (0);
		i++;
	}
	return (1);
}

int				is_play_ok(int play, t_map *s_map)
{
	if (play < 0 || play >= s_map->col)
		return (1);
	if (is_valid(play, s_map))
		return (1);
	return (0);
}

void			make_play(int play, t_map *s_map, char chip)
{
	int		i;

	i = 0;
	while (i < s_map->line)
	{
		if (s_map->map[i][play] != EMPTY)
			break ;
		i++;
	}
	s_map->map[i - 1][play] = chip;
}
