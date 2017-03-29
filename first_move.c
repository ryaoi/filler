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

static void	puttetri(char **tab, char **tetri, t_fil *fil)
{
	char	**map;
	int		i;

	map = cutmap(tab, fil);
	i = 0;
	ft_putstr_fd("\n@@@@clean map\n", 2);
	while (map[i] != 0)
	{
		ft_putstr_fd(map[i], 2);
		ft_putstr_fd("\n", 2);
		i++;
	}
	ft_putstr_fd("\n@@@showed map\n", 2);
	if (fil->my_y > fil->enemy_y && fil->my_x > fil->enemy_x)
	{
		ft_putstr_fd("im farest\n", 2);
		if (map[0][0] == '.')
		{
			if (topleft(map, tetri, fil) == 0)
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
		else if (map[fil->line - 1][0] == '.' && map[0][0] == fil->c)
		{
			if (bottomleft(map, tetri, fil) == 0)
			{
				ft_printf("0 0\n");
				exit (0);
			}
		}
		else if (map[fil->line - 1][0] == '.' && map[0][0] == fil->enemy_c)
		{
			if (topright(map, tetri, fil) == 0)
			{
				ft_printf("0 0\n");
				exit (0);
			}
		}
		else if (topright(map, tetri, fil) == 0)
		{
			ft_printf("0 0\n");
			exit (0);
		}
	}
	else
	{
//		ft_putstr_fd("im nearest from O\ngonna check the map right top side\t", 2);
//		ft_putchar_fd(map[0][fil->col - 1], 2);
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
