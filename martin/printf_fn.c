/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_fn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 18:18:09 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/09 17:59:25 by mle-roy          ###   ########.fr       */
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
	if (chip == P_ONE)
		write(1, "You won ! Thanks for playing !\n", 31);
	else
		write(1, "The computer won ! Shame om you !\n", 34);
	return (0);
}

void	ft_print_alcu(char *str)
{
	while (*str)
	{
		write(1, "\033[1;34;40m|\033[0m", 15);
		if (*str == P_ONE)
			write(1, "\033[1;31;40m@\033[0m", 15);
		else if (*str == P_TWO)
			write(1, "\033[1;33;40m@\033[0m", 15);
		else
			write(1, str, 1);
		str++;
	}
	write(1, "\033[1;34;40m|\033[0m", 15);
	write(1, "\n", 1);
}

void	print_map(t_map *s_map, int flag)
{
	int		i;

	i = 0;
	ft_putstr("\x1b\x1b[32m[Al_Cu\x11]\x1b[0m\n");
	if (flag == 1)
		write(1, "\033[0;31;40mPlayer One:\033[0m\n", 26);
	else if (flag == 0)
		write(1, "\033[0;33;40mComputer:\033[0m\n", 25);
	while (i < s_map->line)
	{
		ft_print_alcu(s_map->map[i]);
		i++;
	}
	write(1, "\n", 1);
}
