/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:30:30 by ryaoi             #+#    #+#             */
/*   Updated: 2017/03/31 00:23:02 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char		**ft_readpiece(void)
{
	int		piece;
	static	int	l;
	char	**tetri;
	char	*line;
	char	*tmp;
	int		i;

	sleep(1);
	get_next_line(0, &line);
	ft_putstr_fd(line, 2);
	get_next_line(0, &tmp);
	ft_putstr_fd(tmp, 2);
	piece = ft_atoi(line + 6);
	ft_putstr_fd(ft_itoa(piece), 2);
	if (!(tetri = (char **)malloc(sizeof(char *) * piece + 1)))
		return (NULL);
	i = 0;
	ft_strdel(&line);
	while (i < piece)
	{
		get_next_line(0, &line);
		tetri[i] = ft_strdup(line);
		ft_strdel(&line);
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
	int		max;

	line = NULL;
	max = fil->line + 1;
	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * max + 1)))
		return (NULL);
	while (i < max)
	{
		get_next_line(0, &line);
		map[i] = ft_strdup(line);
		ft_strdel(&line);
		i++;
	}
	map[i] = 0;
//	printab(map);
	return (map);
}
