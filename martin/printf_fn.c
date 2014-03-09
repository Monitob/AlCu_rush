/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_fn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 18:18:09 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/09 16:38:20 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "puissance4.h"
#include "libft.h"

int		print_draw(void)
{
	write(1, "No more chips, play again !\n", 28);
	return (0);
}

int		print_winner(char chip)
{
	if (chip == P_ONE) //ici
		write(1, "You won ! Thanks for playing !\n", 31);
	else
		write(1, "The computer won ! Shame om you !\n", 34);
	return (0);
}

void	print_map(t_map *s_map)
{
	int		i;

	i = 0;
	ft_putstr("\x11[\x1b[32mAl_Cu\x11]\x1b[0m \n");	
	while (i < s_map->line)
	{
		ft_putendl(s_map->map[i]);
		i++;
	}
	write(1, "\n", 1);
}
