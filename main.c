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

int		main(void)
{
	t_fil	fil;
	char	**tab;

	tab = read_player(&fil);
	if (fil.c == 'O')
		first_move(&fil, tab);
	ft_strdel(tab);
	while (1)
	{
		tab = read_map();
		if (fil.c == 'O')
			move_p1(&fil, tab);
		else
			move_p2(&fil, tab);
//		ft_printf("0 0\n");
		freetab(tab);
	}
	return (0);
}
