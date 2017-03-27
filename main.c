/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 20:32:12 by ryaoi             #+#    #+#             */
/*   Updated: 2017/03/26 22:09:11 by ryaoi            ###   ########.fr       */
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

	fil.line = 0;
	tab = read_player(&fil);
	printab(tab);
	ft_printf("9 2\n");
//	if (fil.c == 'O')
//		first_move(&fil, tab);
	freetab(tab);
	while (1)
	{
//		tab = read_map();
//		printab(tab);
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
		freetab(tab);
*/
		ft_printf("0 0\n");
	}
	return (0);
}
