/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   human_turn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 18:16:16 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/08 19:40:34 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "puissance4.h"
#include "get_next_line.h"

int					verify_letter(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]))
		{
			error_command("Only numbers please");
			return (0);
		}
		i++;
	}
	return (1);
}

void	human_turn(t_map *s_map, char chip)
{
	char	*buf;
	int		play;
	int		ok;

	ok = -1;
	while (ok)
	{
		get_next_line(0, &buf);
		if (buf[0] != '\0' && verify_letter(buf) != 0)
		{
			play = ft_atoi(buf);
			if ((ok = is_play_ok(play, s_map)) == 1)
				write(1, "play again, incorrect value:\n", 29);
		}
		free(buf);
	}
	make_play(play, s_map, chip);
}
