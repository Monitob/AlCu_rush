/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_turn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 19:40:29 by jbernabe          #+#    #+#             */
/*   Updated: 2014/03/09 19:56:04 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int					check_stop_flag(int flag, char c)
{
	if (c == P_ONE)
		return (flag + 1);
	return (0);
}

int					can_i_play(t_map *s_map, int line, int col)
{
	if (line < s_map->line && col < s_map->col &&
		s_map->map[line][col] == EMPTY
		&& ((line + 1) == s_map->line || s_map->map[line + 1][col] != EMPTY))
	{
		return (1);
	}
	return (0);
}

static int			can_i_win(t_map *s_map)
{
	int		pos;

	pos = -1;
	if ((pos = find_chip(s_map, 3)) > -1)
		return (pos);
	return (-1);
}

void				cmp_turn(t_map *s_map, char chip)
{
	int		play;

	play = -1;
	if ((play = can_i_win(s_map)) > -1)
		;
	else if ((play = can_i_stop(s_map)) > -1)
		;
	else
		play = play_something(s_map);
	make_play(play, s_map, chip);
	return ;
}
