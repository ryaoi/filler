/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 20:32:12 by ryaoi             #+#    #+#             */
/*   Updated: 2017/03/28 02:21:58 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	printab(char **tab)
{
	int		i;

	i = 0;
	ft_putstr_fd("\nBegin@@@@\n", 2);
	while (tab[i] != 0)
	{
		ft_putstr_fd(tab[i], 2);
		ft_putchar_fd('\n', 2);
		i++;
	}
	ft_putstr_fd("\nEnd@@@@\n", 2);
}

int		main(void)
{
	t_fil	fil;
	char	**tab;

	ft_putstr_fd("LOOOOOL", 2);
	fil.line = 0;
	if (!(tab = read_player(&fil)))
	{
		ft_putstr_fd("EXIT EXIT EXIT\n", 2);
		exit (EXIT_FAILURE);
	}
	if (fil.c == 'O')
		first_move(&fil, tab);
	freetab(tab);
	while (1)
	{
		if (!(tab = read_map()))
		{
			ft_putstr_fd("still reading\n", 2);
			continue ;
		}
		printab(tab);
		ft_putstr_fd("10 3\n", 1);
//		if (fil.line == 0)
//		{
//			check_plateau(tab[0], &fil);
//			recup_cord(tab, &fil);
//		}
//		cutmap(&tab, &fil);
//		printab(tab);
/*
		if (fil.c == 'O')
			move_p1(&fil, tab);
		else
			move_p2(&fil, tab);
*/
		freetab(tab);
	}
		return (0);
}
