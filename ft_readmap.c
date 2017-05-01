/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:30:30 by ryaoi             #+#    #+#             */
/*   Updated: 2017/05/01 17:14:05 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char		**ft_readpiece(void)
{
	int		piece;
	static	int	l;
	char	**tetri;
	char	*line;
	int		i;

	ft_putstr_fd("Inside ft_readpiece\n", 2);
	ft_putstr_fd("1st gnl!!!!\n", 2);
	get_next_line(0, &line);
	ft_putstr_fd(line, 2);
	ft_putstr_fd("\nPiece is:\n", 2);
	piece = ft_atoi(line + 6);
	ft_putstr_fd(ft_itoa(piece), 2);
	if (!(tetri = (char **)malloc(sizeof(char *) * piece + 1)))
		return (NULL);
	i = 0;
	ft_strdel(&line);
	ft_putstr_fd("\nbefore while\n", 2);
	while (i < piece)
	{
		get_next_line(0, &line);
		if (line != NULL)
		{
			tetri[i] = ft_strdup(line);
			ft_strdel(&line);
		}
		i++;
	}
	tetri[i] = 0;
	ft_putstr_fd("tetri piece that i got\n", 2);
	printab(tetri);
	return (tetri);
}

char		**ft_readmap(t_fil *fil)
{
	int		i;
	char	**map;
	char	*line;
	static int	max = 0;

	line = NULL;
	if (max == 0)
		max = fil->line + 1;
	else
		max = fil->line + 2;
	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * max + 1)))
		return (NULL);
	ft_putstr_fd("\nmax is:", 2);
	ft_putstr_fd(ft_itoa(max), 2); //debug
	while (i < max)
	{
		get_next_line(0, &line);
		if (line != NULL)
		{
			map[i] = ft_strdup(line);
			ft_strdel(&line);
		}
		i++;
	}
	map[i] = 0;
	printab(map);
	return (map);
}
