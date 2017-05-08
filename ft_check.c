/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 23:07:35 by ryaoi             #+#    #+#             */
/*   Updated: 2017/04/01 03:28:30 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	clean_map(char **tab)
{
	int		i;
	int		l;

	i = 0;
	while (tab[i] != 0)
	{
		l = 0;
		while (tab[i][l] != '\0')
		{
			if (tab[i][l] == '*')
				tab[i][l] = '.';
			l++;
		}
		i++;
	}
}

static int  final_return_value(char **tab, int touched, int i, int l)
{
	if (touched != 1)
	{
		clean_map(tab);
		return (0);
	}
	ft_printf("%d %d\n", i, l);
	return (1);
}

int			valid_put(t_tetri tet, int i, int l, t_fil *fil)
{
	int		x;
	int		y;
	int		touched;

	touched = 0;
	y = 0;
	while (tet.tetri[y] != 0)
	{
		x = 0;
		while (tet.tetri[y][x] != '\0')
		{
			if (i + y >= fil->line || l + x >= fil->col)
			{
				clean_map(tet.map);
				return (0);
			}
			if (tet.tetri[y][x] == '.')
			{
				x++;
				continue ;
			}
			if (tet.map[i + y][l + x] == fil->c ||
				tet.map[i + y][l + x] == fil->c + 32)
				touched++;
			if (touched == 2 || tet.map[i + y][l + x] == fil->enemy_c
				|| tet.map[i + y][l + x] == fil->enemy_c + 32)
			{
				clean_map(tet.map);
				return (0);
			}
			if (tet.map[i + y][l + x] == '.')
				tet.map[i + y][l + x] = tet.tetri[y][x];
			x++;
		}
		y++;
	}
	return (final_return_value(tet.map, touched, i, l));
}
