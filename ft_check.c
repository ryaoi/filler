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

int			valid_put(char **tab, char **tetri, int i, int l, t_fil *fil)
{
	int		x;
	int		y;
	int		touched;

	touched = 0;
	y = 0;
	while (tetri[y] != 0)
	{
		x = 0;
		while (tetri[y][x] != '\0')
		{
			if (i + y >= fil->line || l + x >= fil->col)
			{
				clean_map(tab);
				return (0);
			}
			if (tetri[y][x] == '.')
			{
				x++;
				continue ;
			}
			if (tab[i + y][l + x] == fil->c ||
				tab[i + y][l + x] == fil->c + 32)
				touched++;
			if (touched == 2 || tab[i + y][l + x] == fil->enemy_c
				|| tab[i + y][l + x] == fil->enemy_c + 32)
			{
				clean_map(tab);
				return (0);
			}
			if (tab[i + y][l + x] == '.')
				tab[i + y][l + x] = tetri[y][x];
			x++;
		}
		y++;
	}
	if (touched != 1)
	{
		clean_map(tab);
		return (0);
	}
	ft_putstr_fd(&fil->c, 2);
	ft_putstr_fd("yay gonna return something\n", 2);
	x = 0;
	while (tab[x] != 0)
	{
		ft_putstr_fd(tab[x], 2);
		ft_putstr_fd("\n", 2);
		x++;
	}
	ft_printf("%d %d\n", i, l);
	return (1);
}
