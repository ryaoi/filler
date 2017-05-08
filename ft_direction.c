/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 22:54:05 by ryaoi             #+#    #+#             */
/*   Updated: 2017/03/29 23:08:16 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			topleft(t_tetri tet, t_fil *fil)
{
	int		i;
	int		l;

	i = 0;
	while (i < fil->line)
	{
		l = 0;
		while (l < fil->col)
		{
			if (valid_put(tet, i, l, fil) == 1)
				return (1);
			l++;
		}
		i++;
	}
	return (0);
}

int			topright(t_tetri tet, t_fil *fil)
{
	int		i;
	int		l;

	i = 0;
	while (i < fil->line)
	{
		l = fil->col - 1;
		while (l >= 0)
		{
			if (valid_put(tet, i, l, fil) == 1)
				return (1);
			l--;
		}
		i++;
	}
	return (0);
}

int			bottomright(t_tetri tet, t_fil *fil)
{
	int		i;
	int		l;

	i = fil->line - 1;
	while (i >= 0)
	{
		l = fil->col - 1;
		while (l >= 0)
		{
			if (valid_put(tet, i, l, fil) == 1)
				return (1);
			l--;
		}
		i--;
	}
	return (0);
}

int			middlebottomleft(t_tetri tet, t_fil *fil)
{
	int		i;
	int		l;

	i = ((fil->line - 1) * 4) / 5; // 2 and 3
	while (i >= 0)
	{
		l = 0;
		while (l < fil->col)
		{
			if (valid_put(tet, i, l, fil) == 1)
				return (1);
			l++;
		}
		i--;
	}
	return (0);
}

int			testleft(t_tetri tet, t_fil *fil)
{
	int		i;
	int		l;

	i = 0;
	while (i < fil->col)
	{
		l = 0;
		while (l < fil->line)
		{
			if (valid_put(tet, i, l, fil) == 1)
				return (1);
			l++;
		}
		i++;
	}
	return (0);
}

int			fromoriginy(t_tetri tet, t_fil *fil)
{
	int		l;

	l = 0;
	while (l < fil->col)
	{
		if (valid_put(tet, fil->my_y, l, fil) == 1)
			return (1);
		l++;
	}
	return (0);
}

int			fromoriginx(t_tetri tet, t_fil *fil)
{
	int		l;

	l = 0;
	while (l < fil->line)
	{
		if (valid_put(tet, l, fil->my_x, fil) == 1)
			return (1);
		l++;
	}
	return (0);
}

int			fromoriginxdown(t_tetri tet, t_fil *fil)
{
	int		l;

	l = fil->line - 1;
	while (l >= 0)
	{
		if (valid_put(tet, l, fil->my_x, fil) == 1)
			return (1);
		l--;
	}
	return (0);

}

int			fromoriginydown(t_tetri tet, t_fil *fil)
{
	int		l;

	l = fil->col - 1;
	while (l >= 0)
	{
		if (valid_put(tet, fil->my_y, l, fil) == 1)
			return (1);
		l--;
	}
	return (0);

}

int			bottomleft(t_tetri tet, t_fil *fil)
{
	int		i;
	int		l;

	i = fil->line - 1;
	while (i >= 0)
	{
		l = 0;
		while (l < fil->col)
		{
			if (valid_put(tet, i, l, fil) == 1)
				return (1);
			l++;
		}
		i--;
	}
	return (0);
}
