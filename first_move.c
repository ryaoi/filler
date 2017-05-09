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

int			check_line(char **tab, t_fil *fil, int l, int line)
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

int			check_side(char **tab, t_fil *fil, int l, int side)
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
	t_tetri	tet;

	tet.tetri = tetri;
	tet.tetri_y = 0;
	while (tet.tetri[tet.tetri_y] != 0)
		tet.tetri_y++;
	tet.tetri_x = 0;
	while (tet.tetri[0][tet.tetri_x] != '\0')
		tet.tetri_x++;
	tet.map = cutmap(tab, fil);
	if (fil->start > fil->line  / 2 + fil->line / 10)
	{
		/*
		if (check_surroundo(tet.map, fil) == 1 && check_line(tet.map, fil, 1, 0) == 1) //surround
		{//need a checker from bottom line to the top then col - 1
			ft_putstr_fd("Inject virus!!!!\n", 2);
			if (virusup(tet, fil) == 1) // if only we cover their pieces on upper side
				return ;
		}
		if (check_line(tet.map, fil, 1, 0) == 0)
		{
			ft_putstr_fd("inject gotomiddlefromo!!!!\n", 2);
			if (gotomiddlefromo(tet, fil) == 1)
			return ;
		}
		if (check_line(tet.map, fil, 1, 0) == 1)
		{
			ft_putstr_fd("inject topleft!!!!\n", 2);
			if (topleft(tet, fil) == 1)
				return ;
		}
		if (tet.map[fil->line - 1][0] == '.')
	    {
	        if (bottomleft(tet, fil) == 1)
				return ;
	    }
		if (tet.map[0][fil->col - 1] == '.' && tet.tetri_x >= tet.tetri_y)
		{
			if (topright(tet, fil) == 0)
			{
				ft_putstr_fd("virus down!!!\n", 2);
				if (virusdown(tet, fil) == 0)
				{
					ft_printf("0 0\n");
					exit (0);
				}
			}
		}
		else if (topleft(tet, fil) == 0) //?
		{
			if (bottomright(tet, fil) == 0)
			{
				if (topleft(tet, fil) == 0)
				{
					if (bottomleft(tet, fil) == 0)
					{
						ft_printf("0 0\n");
						exit (0);
					}
				}
			}
		}
		*/
		strat_down(fil, tet);
	}
	else
		strat_up(fil, tet);
	freetab(tet.map);
}

void		first_move(t_fil *fil, char **tab)
{
	char	**tetri;

	if (!(tetri = ft_readpiece()))
		exit (EXIT_FAILURE);
	puttetri(tab, tetri, fil);
	freetab(tetri);
}
