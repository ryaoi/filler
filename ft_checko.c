/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checko.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 00:24:43 by ryaoi             #+#    #+#             */
/*   Updated: 2017/03/30 00:30:24 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			check_surroundx(char **map, t_fil *fil)
{
	int		i;
	int		l;

	i = 0;
	while (map[i] != 0)
	{
		l = 0;
		while (map[i][l] != '\0')
		{
			if (map[i][l] == 'X')
				return (0);
			if (map[i][l] == 'O')
				break ;
			l++;
		}
		i++;
	}
	return (1);
}
