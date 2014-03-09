/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 15:38:06 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/09 16:38:12 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "puissance4.h"
#include "libft.h"
#include "get_next_line.h"

#include <stdio.h> //nononon

void	error_command(char *s)
{
	ft_putstr_fd(s, 2);
	write(2, "\n", 1);
	return ;
}

void	cmp_turn(t_map *s_map, char chip)
{
	int		play;

	play = -1;
	if ((play = can_i_win(s_map)) > -1)
		;
	if ((play = can_i_stop(s_map)) > -1) //else au debut
		;
	else
		play = play_something(s_map);
	make_play(play, s_map, chip);
	return ;
}

void	lets_play(int flag, t_map *s_map)
{
	int		finish;
	char	chip;

	finish = -1;
//	chip = '.';
	while (finish)
	{
		print_map(s_map);
		if (flag)
		{
			chip = P_ONE; //ici
			human_turn(s_map, chip);
			flag = 0;
		}
		else
		{
			chip = P_TWO; //ici
//			human_turn(s_map, chip);
			cmp_turn(s_map, chip); //a faire
			flag = 1;
		}
		finish = is_finish(s_map, chip);
	}
}

void	start_game(t_map *s_map)
{
	int		player_one;
	int		player_cmp;
	time_t	_time;
	int		flag;

	flag = 0;
	_time = time(NULL);
	srand(_time);
	player_one = rand();
	player_cmp = rand();
	if (player_one >= player_cmp)
		flag = 1;
	lets_play(flag, s_map);
	print_map(s_map);
}

void	free_map(t_map *s_map)
{
	ft_tabfree(&(s_map->map));
	free(s_map);
}

int		main(int argc, char **argv)
{
	t_map	*s_map;

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
