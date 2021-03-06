/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:43:11 by mle-roy           #+#    #+#             */
/*   Updated: 2013/11/25 17:21:46 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		t;

	i = 0;
	t = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[t] != '\0')
	{
		s1[i] = s2[t];
		i++;
		t++;
	}
	s1[i] = '\0';
	return (s1);
}
