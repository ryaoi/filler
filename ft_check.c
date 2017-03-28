/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 23:07:35 by ryaoi             #+#    #+#             */
/*   Updated: 2017/03/28 02:22:25 by ryaoi            ###   ########.fr       */
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

static int	check_interact(char **tab, t_fil *fil)
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
			{
				if (fil->c == 'O' && ((i > 0 && (tab[i - 1][l] == 'O'))
					|| (tab[i + 1] != '\0' && tab[i + 1][l] == 'O')
					|| (l > 0 && tab[i][l - 1] == 'O')
					|| tab[i][l + 1] == 'O'))
					return (1);
				else if (fil->c == 'X' && ((i > 0 && (tab[i - 1][l] == 'X'))
					|| ( tab[i + 1] != '\0' && tab[i + 1][l] == 'X')
					|| (l > 0 && tab[i][l - 1] == 'X')
					|| tab[i][l + 1] == 'X'))
					return (1);
			}
			l++;
		}
		i++;
	}
	return (0);
}

static int	valid_put(char **tab, char **tetri, int i, int l, t_fil *fil)
{
	int		x;
	int		y;

	y = 0;
	while (tetri[y] != 0)
	{
		x = 0;
		while (tetri[y][x] != '\0')
		{
			if (tab[i + y][l + x] != '.')
			{
				clean_map(tab);
				return (0);
			}
			tab[i + y][l + x] = tetri[y][x];
			x++;
		}
		y++;
	}
	if (!(check_interact(tab, fil)))
	{
		clean_map(tab);
		return (0);
	}
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

int			can_put(char **tab, char **tetri, t_fil *fil)
{
	int		i;
	int		l;

	i = 0;
	while (tab[i] != 0)
	{
		l = 0;
		while (tab[i][l] != '\0')
		{
			if (tab[i][l] == '.')
			{
				if (valid_put(tab, tetri, i, l, fil) == 1)
					return (1);
			}
			l++;
		}
		i++;
	}
	return (0);
}
