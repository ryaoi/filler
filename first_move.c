/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 22:38:30 by ryaoi             #+#    #+#             */
/*   Updated: 2017/03/29 02:27:59 by ryaoi            ###   ########.fr       */
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
	char	**map;
	int		i;
	int		tetri_y;
	int		tetri_x;

	tetri_y = 0;
	while (tetri[tetri_y] != 0)
		tetri_y++;
	tetri_x = 0;
	while (tetri[0][tetri_x] != '\0')
		tetri_x++;
	map = cutmap(tab, fil);
	i = 0;
	ft_putstr_fd("\n@@@@clean map\n", 2);
	while (map[i] != 0)
	{
		ft_putstr_fd(map[i], 2);
		ft_putstr_fd("\n", 2);
		i++;
	}
// mvoe the O and X till half or 1/3 of y then spread it to the angle
// create a checker to detect if it touched top then need tot ouch bottom.
// keep the coord and if tetri_x > tetri_y stick it to the left
// else top
	ft_putstr_fd("\n@@@showed map\n", 2);
	if (fil->my_y > fil->enemy_y && fil->my_x > fil->enemy_x)
	{
		if (map[0][0] == '.' && (check_line(tab, fil, 0, fil->line / 3) == 0)
			&& (check_line(tab, fil, 1, ((fil->line * 2) / 3)) == 0))
		{
			if (topleft(map, tetri, fil) == 0)
			{
				ft_printf("0 0\n");
				exit (0);
			}
		}
		else if (map[fil->line - 1][0] == '.' && (check_side(tab, fil, 0, 0) == 0))
		{
			if (middlebottomleft(map, tetri, fil) == 0)
			{
				if (bottomleft(map, tetri, fil) == 0)
				{
					if (topright(map, tetri, fil) == 0)
					{
						ft_printf("0 0\n");
						exit (0);
					}
				}
			}
		}
		else if (map[0][fil->col - 1] == '.')
		{
			if (topright(map, tetri, fil) == 0)
			{
				ft_printf("0 0\n");
				exit (0);
			}
		}
		else if (map[fil->line - 1][fil->col - 1] == '.')
		{
			if (bottomright(map, tetri, fil) == 0)
			{
				ft_printf("0 0\n");
				exit (0);
			}
		}
		else if (bottomright(map, tetri, fil) == 0)
		{
			ft_printf("0 0\n");
			exit (0);
		}
	}
	else
	{
		if (map[0][fil->col - 1] == '.')
		{
			if (topright(map, tetri, fil) == 0)
			{
				ft_printf("0 0\n");
				exit (0);
			}
		}
		else if (bottomleft(map, tetri, fil) == 0)
		{
//			if (bottomright(map, tetri, fil) == 0)
//			{
//				if (topleft(map, tetri, fil) == 0)
//				{
					ft_printf("0 0\n");
					exit (0);
//				}
//			}
		}
	}
	freetab(map);
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
