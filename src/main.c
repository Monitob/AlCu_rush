/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 20:34:53 by jbernabe          #+#    #+#             */
/*   Updated: 2014/03/07 22:02:37 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

void	error_command(char *s)
{
	ft_putstr_fd(s, 2);
	write(2,  "\n", 1);
	return ;
}

void	ft_init_map(t_map **map)
{
	if (!(*map = (t_map *)malloc(sizeof(t_map))))
		return ;
	(*map)->map = NULL;
	(*map)->col = 0;
	(*map)->line = 0;
}

void	ft_fill_grid(t_map **s_map)
{
	int	i;

	if (!((*s_map)->map = (char **)malloc(sizeof(char *) * (*s_map)->line)))
		return ;
	(*s_map)->map[(*s_map)->line] = NULL;
	i = 0;
	while ((*s_map)->map[i] != NULL)
	{
		(*s_map)->map[i] = ft_strnew((*s_map)->col);
		i++;
	}
}

void	ft_get_dimentions(char *x, char *y, t_map **s_map)
{
	int	ver;

	ft_init_map(s_map);
	(*s_map)->col = ft_atoi(x);
	(*s_map)->line = ft_atoi(y);
	ver = ((*s_map)->col * (s_map)->line) % 2;
	if ((*s_map)->col < 7 || (*s_map)->line < 6)
	{
		error_command("minimun size x : 7 y  : 6");
		return ;
	}
	if ((*s_map)->col > 2000 || (*s_map)->line > 2000) 
	{
		error_command("maximun size 2000 x 2000");
		return ;
	}
	if (ver != 0)
	{
		error_command("bad dimensions");
		return ;
	}
	ft_fill_grid(s_map);
}

int	main(int ac, char **av)
{
	t_map *map;

	if (ac != 3)
	{
		error_command("Usage: ./Puissance4 x y");
		return (0);
	}
	else
	{
		ft_get_dimentions(av[1], av[2], &map);
		return (0);
	}
	return (0);
}

