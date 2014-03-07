/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 20:36:14 by jbernabe          #+#    #+#             */
/*   Updated: 2014/03/07 22:01:48 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE_H
# define PUISSANCE_H

# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <stdio.h>
# include "libft.h"

typedef struct	s_map
{
	char		**map;
	int			col;
	int			line;
}				t_map;

void	error_command(char *s);
void	ft_init_map(t_map **map);
void	ft_fill_grid(t_map **s_map);

#endif /* !PUISSANCE_H */

