/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 18:22:13 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/08 18:31:11 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

static int		is_map_full(t_map *s_map)
{
	int		i;
	int		j;

	i = 0;
	while (i < s_map->line)
	{
		j = 0;
		while (j < s_map->col)
		{
			if (s_map->map[i][j] == EMPTY) //ici
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int				is_finish(t_map *s_map, char chip)
{
	int		i;
	int		j;

	i = 0;
	while (i < s_map->line)
	{
		j = 0;
		while (j < s_map->col)
		{
			if (s_map->map[i][j] == chip)
			{
				if (check_four(s_map, i, j, chip))
					return (print_winner(chip));
			}
			j++;
		}
		i++;
	}
	if (is_map_full(s_map))
		return (print_draw());
	return (1);
}
