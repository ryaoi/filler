/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 20:32:12 by ryaoi             #+#    #+#             */
/*   Updated: 2017/03/28 22:49:11 by ryaoi            ###   ########.fr       */
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
	if (!(tab = read_player(&fil)))
		exit (EXIT_FAILURE);
	first_move(&fil, tab);
	freetab(tab);
	tab = NULL;
	ft_putstr_fd("get inside the while\n", 2);
	while (1)
	{
		if (!(tab = read_map()))
		{
			ft_putstr_fd("get out!!!\n", 2);
//			exit (0);
		}
		else
		{
			first_move(&fil, tab);
			freetab(tab);
		}
//		printab(tab);
/*
		if (fil.c == 'O')
			move_p1(&fil, tab);
		else
			move_p2(&fil, tab);
*/
	}
	return (0);
}
