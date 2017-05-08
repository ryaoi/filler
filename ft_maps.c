/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 20:53:27 by ryaoi             #+#    #+#             */
/*   Updated: 2017/03/29 01:28:49 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	get_cord(t_fil *fil, char **map)
{
	int		i;
	int		l;

	i = 0;
	if (fil->start == 0)
	{
		while (map[i] != 0)
		{
			l = 0;
			while (map[i][l] != '\0')
			{
				if (map[i][l] == fil->c)
					fil->start = i;
				l++;
			}
			i++;
		}
	}
}

char		**cutmap(char **tab, t_fil *fil)
{
	char	**ret;
	int		i;
	int		skip;

	skip = 0;
	i = 0;
	if (!(ret = (char **)malloc(sizeof(char *) * (fil->line + 1))))
	{
		ft_printf("failed malloc when adjusting the map\n");
		exit(EXIT_FAILURE);
	}
	while (ft_strncmp(tab[i], "00", 2) != 0)
	{
		i++;
		skip++;
	}
	while (i < fil->line + skip)
	{
		ret[i - skip] = ft_strsub(tab[i], 4, ft_strlen(tab[i]) - 4);
		i++;
	}
	ret[i - skip]  = 0;
	get_cord(fil, ret);
	return (ret);
}
