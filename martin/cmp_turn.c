/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_turn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 19:40:29 by jbernabe          #+#    #+#             */
/*   Updated: 2014/03/08 23:15:17 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "puissance4.h"

static int	can_i_play_in_line(t_map *s_map, int line, int col)
{
	if (line < s_map->line && col < s_map->col &&
			s_map->map[line][col] == EMPTY
			&& ((line + 1) == s_map->line
				|| s_map->map[line - 1][col] != EMPTY))
		return (1);
	return (0);
}

static int	check_line_to_win(t_map *s_map)
{
	int		i;
	int		line;
	int		flag;

	line = 0;
	i = 0;
	flag = 0;
	while (i < s_map->col)
	{
		if (s_map->map[line][i] == P_TWO)
			flag++;
		line++;
		i++;
	}
	if (flag == 3)
	{
		i = 0;
		while (s_map->map[line][i] != '\0')
		{
			if (s_map->map[line][i] == EMPTY
					|| can_i_play_in_line(s_map, line, i))
				return (i);
			i++;
		}
	}
	return (-1);
}

static int	check_col_to_win(t_map *s_map)
{
	int		i;
	int		flag;
	int		line;
	int		play;

	i = 0;
	flag = 0;
	play = -1;
	while (i < s_map->col)
	{
			line = 0;
			while (line < s_map->line)
			{
				if (s_map->map[line][i] == P_TWO)
					flag++;
				else
					flag = 0;
				if (flag == 3)
				{
					if ((play = is_play_col(s_map, line, i, 3)) > -1)
						return (play);
				}
				line++;
			}
		i++;
	}
	return (play);
}

int		can_i_win(t_map *s_map)
{
	int	pos;

	pos = -1;
/*	if ((pos = find_chip(s_map, 3)) > -1)
		return (pos);*/
	if ((pos = check_line_to_win(s_map)) > -1)
		return (pos);
	if ((pos = check_col_to_win(s_map)) > -1)
		return (pos);
/*	if (pos = check_diag_right_to_win(s_map))
		return (pos);
	if (check_left_to_win(s_map))
		return (pos);*/
	return (-1);
}
