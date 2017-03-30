/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_odirections.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 23:03:51 by ryaoi             #+#    #+#             */
/*   Updated: 2017/03/30 02:24:07 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				gotomiddlefromo(char **tab, char **tetri, t_fil *fil)
{
		int		i;
		int		l;

	i = (fil->line - 1) / 3;
	while (i >= 0)
	{
		l = (fil->col - 1) / 3;
		while (l >= 0)
		{
			if (valid_put(tab, tetri, i, l, fil) == 1)
				return (1);
			l--;
		}
		i--;
	}
	return (0);
}
int			middletotopright(char **tab, char **tetri, t_fil *fil)
{
	int		i;
	int		l;

	i = fil->col - 1;
	while (i >= 0)
	{
		l = fil->line - 1;
		while (l >= 0)
		{
			if (valid_put(tab, tetri, l, i, fil) == 1)
				return (1);
			l--;
		}
		i--;
	}
	return (0);
}

int			virusdown(char **tab, char **tetri, t_fil *fil)
{
	int		i;
	int		l;

	i = fil->col - 1;
	while (i >= 0)
	{
		l = 0;
		while (l < fil->line - 1 && tab[l][i] == '.')
			l++;
		while (l < fil->line - 1)
		{
			if (valid_put(tab, tetri, l, i, fil) == 1)
				return (1);
			l++;
		}
		i--;
	}
	return (0);
}

int			virusup(char **tab, char **tetri, t_fil *fil)
{
	int		i;
	int		l;

	i = 0;
	while (i < fil->col - 1)
	{
		l = 0;
		while (l < fil->line - 1 && tab[l][i] == '.')
			l++;
		while (l < fil->line - 1 && tab[l][i] == 'X')
			l++;
		while (l < fil->line - 1)
		{
			if (valid_put(tab, tetri, l, i, fil) == 1)
				return (1);
			l++;
		}
		i++;
	}
	return (0);
}

int			surroundx(char **tab, char **tetri, t_fil *fil)
{
	int		i;
	int		l;

	i = fil->line - 1;
	while (i >= 0)
	{
		l = 0;
		while (tab[i][l] == '.' && l < fil->col - 1)
			l++;
		while (l < fil->col - 1)
		{
			if (valid_put(tab, tetri, i, l, fil) == 1)
				return (1);
			l++;
		}
		i--;
	}
	return (0);
}
