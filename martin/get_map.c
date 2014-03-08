/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 18:08:22 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/08 19:40:32 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "puissance4.h"
#include "libft.h"

static int			ft_verify_dimension(int x, int y)
{
//	int	ver;

//	ver = (x * y) % 2;
	if (x < 7 || y < 6)
	{
		error_command("Puissance4:\nminimum col = 7\nminimum line = 6");
		return(-1);
	}
	if (x > 2000 || y > 2000) 
	{
		error_command("maximum size 2000 x 2000");
		return(-1);
	}
//	if (ver != 0)
//	{
//		error_command("Puissance4: map is too big !");
//		return(-1);
//	}
	return (0);
}

static t_map		*init_map(void)
{
	t_map	*new;

	if ((new = (t_map *)malloc(sizeof(*new))) == NULL)
		return (NULL);
	new->map = NULL;
	new->col = 0;
	new->line = 0;
	return (new);
}

static char			**init_tab(int col, int line)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((map = (char **)malloc(sizeof(char *) * (line + 1))) == NULL)
		return (NULL);
	map[line] = NULL;
	while (i < line)
	{
		map[i] = ft_strnew(col);
		i++;
	}
	while (j < line)
	{
		i = 0;
		while (i < col)
		{
			map[j][i] = EMPTY; //ici
			i++;
		}
		j++;
	}
	return (map);
}


t_map				*get_map(char *col, char *line)
{
	t_map	*s_map;
	
	if ((s_map = init_map()) == NULL)
		return (NULL);
	s_map->col = ft_atoi(col);
	s_map->line = ft_atoi(line);
	if (ft_verify_dimension(s_map->col, s_map->line))
	{
		free(s_map);
		return (NULL);
	}
	s_map->map = init_tab(s_map->col, s_map->line);
	return (s_map);
}
