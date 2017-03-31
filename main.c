/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 20:32:12 by ryaoi             #+#    #+#             */
/*   Updated: 2017/03/30 22:36:29 by ryaoi            ###   ########.fr       */
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
	ft_putstr_fd("End@@@@\n", 2);
}

int		main(void)
{
	t_fil	fil;
	char	**tab;

	ft_player(&fil);
	while (1)
	{
		ft_putstr_fd("whileeeeeeeeeeeeeeeeeee\n", 2);
		if (!(tab = ft_readmap(&fil)))
			exit (EXIT_FAILURE);
		first_move(&fil, tab);
		freetab(tab);
	}
	return (0);
}
