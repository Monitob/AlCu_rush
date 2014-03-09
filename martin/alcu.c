/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 15:38:06 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/09 19:50:52 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "puissance4.h"
#include "libft.h"
#include "get_next_line.h"

void				error_command(char *s)
{
	ft_putstr_fd(s, 2);
	write(2, "\n", 1);
	return ;
}

static void			lets_play(int flag, t_map *s_map)
{
	int				finish;
	char			chip;

	finish = -1;
	while (finish)
	{
		print_map(s_map, flag);
		if (flag)
		{
			chip = P_ONE;
			human_turn(s_map, chip);
			flag = 0;
		}
		else
		{
			chip = P_TWO;
			cmp_turn(s_map, chip);
			flag = 1;
		}
		finish = is_finish(s_map, chip);
	}
}

static void			start_game(t_map *s_map)
{
	int				player_one;
	time_t			_time;
	int				flag;

	flag = 0;
	_time = time(NULL);
	srand(_time);
	player_one = rand();
	if (player_one % 2 == 0)
		flag = 1;
	lets_play(flag, s_map);
	print_map(s_map, 3);
}

static void			free_map(t_map *s_map)
{
	ft_tabfree(&(s_map->map));
	free(s_map);
}

int					main(int argc, char **argv)
{
	t_map			*s_map;

	if (argc != 3)
	{
		error_command("Usage: ./puissance4 col(int) line(int)");
		return (0);
	}
	else
	{
		s_map = get_map(argv[1], argv[2]);
		if (s_map == NULL || s_map->map == NULL)
			return (0);
		start_game(s_map);
		free_map(s_map);
	}
	return (0);
}
