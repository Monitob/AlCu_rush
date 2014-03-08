/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 20:34:53 by jbernabe          #+#    #+#             */
/*   Updated: 2014/03/08 14:55:15 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

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
	int	j;

	if (!((*s_map)->map = (char **)malloc(sizeof(char *) * (*s_map)->line + 1)))
		return ;
	(*s_map)->map[(*s_map)->line] = NULL;
	i = 0;
	while ((*s_map)->map[i] != NULL)
	{
		(*s_map)->map[i] = ft_strnew((*s_map)->col);
		i++;
	}
	j = 0;
	while (j < (*s_map)->line)
	{
		i = 0;
		while (i < (*s_map)->col)
		{
			(*s_map)->map[j][j] = '.';
			i++;
		}
		j++;
	}
}

void	ft_get_dimentions(char *x, char *y, t_map **s_map)
{
	ft_init_map(s_map);
	(*s_map)->col = ft_atoi(x);
	(*s_map)->line = ft_atoi(y);
	if (ft_verify_dimentions((*s_map)->col, (*s_map)->line) == -1)
		return ;
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

