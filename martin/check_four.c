/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_four.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 18:01:53 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/08 18:06:02 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

static int		check_line(t_map *s_map, int line, int col, char chip)
{
	int		i;
	int		flag;

	i = col;
	flag = 0;
	while (i < s_map->col && i < col + 4)
	{
		if (s_map->map[line][i] == chip)
			flag++;
		i++;
	}
	if (flag == 4)
		return (1);
	return (0);
}

static int		check_col(t_map *s_map, int line, int col, char chip)
{
	int		i;
	int		flag;

	i = line;
	flag = 0;
	while (i < s_map->line && i < line + 4)
	{
		if (s_map->map[i][col] == chip)
			flag++;
		i++;
	}
	if (flag == 4)
		return (1);
	return (0);
}

static int		check_diag_right(t_map *s_map, int line, int col, char chip)
{
	int		i;
	int		j;
	int		flag;

	i = line;
	j = col;
	flag = 0;
	while (i < s_map->line && j < s_map->col && i < (line + 4) && j < (col + 4))
	{
		if (s_map->map[i][j] == chip)
			flag++;
		i++;
		j++;
	}
	if (flag == 4)
		return (1);
	return (0);
}

static int		check_diag_left(t_map *s_map, int line, int col, char chip)
{
	int		i;
	int		j;
	int		flag;

	i = line;
	j = col;
	flag = 0;
	while (i < s_map->line && j > 0 && i < (line + 4) && j > (col - 4))
	{
		if (s_map->map[i][j] == chip)
			flag++;
		i++;
		j--;
	}
	if (flag == 4)
		return (1);
	return (0);
}

int				check_four(t_map *s_map, int line, int col, char chip)
{
	if (check_line(s_map, line, col, chip))
		return (1);
	if (check_col(s_map, line, col, chip))
		return (1);
	if (check_diag_right(s_map, line, col, chip))
		return (1);
	if (check_diag_left(s_map, line, col, chip))
		return (1);
	return (0);
}
