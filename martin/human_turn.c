/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   human_turn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 18:16:16 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/08 18:17:12 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "puissance4.h"
#include "get_next_line.h"
#include "libft.h"

void	human_turn(t_map *s_map, char chip)
{
	char	*buf;
	int		play;
	int		ok;

	ok = -1;
	while (ok)
	{
		get_next_line(0, &buf);
		play = ft_atoi(buf);
		free(buf);
		if ((ok = is_play_ok(play, s_map)) == 1)
			write(1, "play again, incorrect value:\n", 29);
	}
	make_play(play, s_map, chip);
}
