/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 20:32:12 by ryaoi             #+#    #+#             */
/*   Updated: 2017/03/29 17:15:54 by ryaoi            ###   ########.fr       */
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
	ft_putstr_fd("get inside the while\n", 2);
	while (1)
	{
		ft_putstr_fd("go for the move\n", 2);
		first_move(&fil, tab);
		ft_putstr_fd("finished the move?\n", 2);
		freetab(tab);
		if (!(tab = read_map()))
		{
			ft_putstr_fd("get out!!!\n", 2);
			exit (0);
		}
	}
	freetab(tab);
	return (0);
}
