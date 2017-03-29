/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 22:54:05 by ryaoi             #+#    #+#             */
/*   Updated: 2017/03/28 23:00:41 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			topleft(char **tab, char **tetri, t_fil *fil)
{
	int		i;
	int		l;

	i = 0;
	while (i < fil->line)
	{
		l = 0;
		while (l < fil->col)
		{
			if (valid_put(tab, tetri, i, l, fil) == 1)
				return (1);
			l++;
		}
		i++;
	}
	return (0);
}

int			topright(char **tab, char **tetri, t_fil *fil)
{
	int		i;
	int		l;

	i = 0;
	while (i < fil->line)
	{
		l = fil->col - 1;
		while (l >= 0)
		{
			if (valid_put(tab, tetri, i, l, fil) == 1)
				return (1);
			l--;
		}
		i++;
	}
	return (0);
}

int			bottomright(char **tab, char **tetri, t_fil *fil)
{
	int		i;
	int		l;

	i = fil->line - 1;
	while (i >= 0)
	{
		l = fil->col - 1;
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

int			bottomleft(char **tab, char **tetri, t_fil *fil)
{
	int		i;
	int		l;

	i = fil->line - 1;
	while (i >= 0)
	{
		l = 0;
		while (l < fil->col)
		{
			if (valid_put(tab, tetri, i, l, fil) == 1)
				return (1);
			l++;
		}
		i--;
	}
	return (0);
}
