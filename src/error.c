/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 14:52:29 by jbernabe          #+#    #+#             */
/*   Updated: 2014/03/08 17:54:36 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

void	error_command(char *s)
{
	ft_putstr_fd(s, 2);
	write(2,  "\n", 1);
	return ;
}

int		ft_verify_dimentions(int x, int y)
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
