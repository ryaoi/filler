/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 22:38:30 by ryaoi             #+#    #+#             */
/*   Updated: 2017/03/29 22:24:07 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check_line(char **tab, t_fil *fil, int l, int line)
{
	int		i;

	i = 0;
	while (tab[line][i] != '\0')
	{
		if (l == 0 && tab[line][i] == fil->enemy_c)
			return (1);
		if (l == 1 && tab[line][i] == fil->c)
			return (1);
		if (l == 2)
		{
			if (tab[line][i] == fil->c || tab[line][i] == fil->enemy_c)
				return (1);
		}
		i++;
	}
	return (0);
}

static int	check_side(char **tab, t_fil *fil, int l, int side)
{
	int		i;
	int		lim;

	if (side == 0)
		lim = 0;
	else
		lim = fil->col - 1;
	i = 0;
	while (i < fil->line - 1)
	{
		if (l == 0 && tab[i][lim] == fil->enemy_c)
			return (1);
		if (l == 1 && tab[i][lim] == fil->c)
			return (1);
		if (l == 2)
		{
			if (tab[i][lim] == fil->c || tab[i][lim] == fil->enemy_c)
				return (1);
		}
		i++;
	}
	return (0);
}

static void	puttetri(char **tab, char **tetri, t_fil *fil)
{
	int		i;
	t_tetri	tet;

	tet.tetri = tetri;
	tet.tetri_y = 0;
	while (tet.tetri[tet.tetri_y] != 0)
		tet.tetri_y++;
	tet.tetri_x = 0;
	while (tet.tetri[0][tet.tetri_x] != '\0')
		tet.tetri_x++;
	tet.map = cutmap(tab, fil);

	i = 0;
/*
	ft_putstr_fd("\n@@@@clean map\n", 2);
	while (tet.map[i] != 0)
	{
		ft_putstr_fd(tet.map[i], 2);
		ft_putstr_fd("\n", 2);
		i++;
	}
	ft_putstr_fd("\n@@@showed map\n", 2);
*/
	if (fil->c == 'X')
	{

		if (tet.map[0][0] == '.' && (check_line(tet.map, fil, 0, fil->line / 3) == 0)
				&& (check_line(tet.map, fil, 1, ((fil->line * 2) / 3)) == 0))
		{
			if (topright(tet.map, tetri, fil) == 0)
			{
				ft_printf("0 0\n");
				exit (0);
			}
		}
		else if ((check_side(tet.map, fil, 1, 0) == 1) && check_line(tet.map, fil, 2, 0) == 1)
		{
			if (virusup(tet.map, tet.tetri, fil) == 0)
			{
				if (bottomright(tet.map, tet.tetri, fil) == 0)
				{
					ft_putstr_fd("hell no\n", 2);
					ft_printf("0 0\n");
					exit (0);
				}
			}
		}
		else if (tet.map[fil->line - 1][0] == '.' && (check_side(tet.map, fil, 0, 0) == 0)
				 && tet.tetri_x > tet.tetri_y)
		{
			if (middlebottomleft(tet.map, tet.tetri, fil) == 0)
			{
				if (bottomleft(tet.map, tet.tetri, fil) == 0)
				{
					if (topright(tet.map, tet.tetri, fil) == 0) //top right
					{
						ft_putstr_fd("damn\n", 2);
						ft_printf("0 0\n");
						exit (0);
					}
				}
			}
		}
		else if (tet.map[0][fil->col - 1] == '.' && (check_line(tet.map, fil, 2, 0) == 0))
		{
			if (topright(tet.map, tet.tetri, fil) == 0)
			{
				if (topleft(tet.map, tet.tetri, fil) == 0)
				{
					ft_putstr_fd("lel\n", 2);
					ft_printf("0 0\n");
					exit (0);
				}
			}
		}
/*
		else if (tet.map[0][0] == '.')
		{
			if (topleft(tet.map, tet.tetri, fil) == 0)
			{
				if (topright(tet.map, tet.tetri, fil) == 0)
				{
					if (bottomright(tet.map, tet.tetri, fil) == 0)
					{
						ft_putstr_fd("wtf\n", 2);
						ft_printf("0 0\n", 2);
						exit (0);
					}
				}
			}
		}
*/
		else if (tet.map[fil->line - 1][fil->col - 1] == '.')
		{
			if (bottomright(tet.map, tet.tetri, fil) == 0)
			{
				ft_putstr_fd("hell yeah\n", 2);
				ft_printf("0 0\n");
				exit (0);
			}
		}
		else if (topleft(tet.map, tet.tetri, fil) == 0)
		{
			ft_printf("0 0\n");
			exit (0);
		}
	}
	else
	{
		if (check_surroundx(tet.map, fil) == 1 && check_line(tet.map, fil, 1, fil->line - 1) == 1)
		{
			if (virusdown(tet.map, tet.tetri, fil) == 1)
				return ;
		}
		if (check_line(tet.map, fil, 1, 0) == 1)
		{
			if (bottomright(tet.map, tet.tetri, fil) == 1)
				return ;
		}
		if (check_line(tet.map, fil, 1, fil->line / 4) == 0)
		{
			if (gotomiddlefromo(tet.map, tet.tetri, fil) == 1)
			return ;
		}
		if (tet.map[0][fil->col - 1] == '.' && tet.tetri_x >= tet.tetri_y) //wit helse
		{
			if (topright(tet.map, tet.tetri, fil) == 0)
			{
				if (bottomright(tet.map, tet.tetri, fil) == 0)
				{
					ft_printf("0 0\n");
					exit (0);
				}
			}
		}
		else if (tet.map[fil->line - 1][0] == '.')
		{
			if (bottomleft(tet.map, tet.tetri, fil) == 0)
			{
				ft_printf("0 0 \n");
				exit (0);
			}
		}
		else if (middletotopright(tet.map, tet.tetri, fil) == 0)
		{
			if (bottomright(tet.map, tet.tetri, fil) == 0)
			{
				if (topleft(tet.map, tet.tetri, fil) == 0)
				{
					if (bottomleft(tet.map, tet.tetri, fil) == 0)
					{
						ft_printf("0 0\n");
						exit (0);
					}
				}
			}
		}
	}
	freetab(tet.map);
}

void		first_move(t_fil *fil, char **tab)
{
	char	**tetri;
	int		i;
	int		l;
	int		x;
	int		y;
	char	*ptr;

	i = 0;
	while (ft_strncmp(tab[i], "Piece", 5) != 0)
		i++;
	ptr = tab[i];
	while (!(ft_isdigit(*ptr)))
		ptr++;
	y = ft_atoi(ptr);
	while ((ft_isdigit(*ptr)))
		ptr++;
	while (!(ft_isdigit(*ptr)))
		ptr++;
	x = ft_atoi(ptr);
	tetri = malloc(sizeof(char **) * (y + 1));
	i++;
	l = 0;
	while (tab[i] != 0)
	{
		tetri[l] = ft_strdup(tab[i]);
		i++;
		l++;
	}
	tetri[l] = 0;
	puttetri(tab, tetri, fil);
}
