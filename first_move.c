/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 22:38:30 by ryaoi             #+#    #+#             */
/*   Updated: 2017/03/28 02:07:44 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	puttetri(char **tab, char **tetri, t_fil *fil)
{
	char	**map;
	int		i;

	map = cutmap(tab, fil);
	i = 0;
	ft_putstr_fd("@@@@clean map\n", 2);
	while (map[i] != 0)
	{
		ft_putstr_fd(map[i], 2);
		ft_putstr_fd("\n", 2);
		i++;
	}
	ft_putstr_fd("@@@showed map\n", 2);
	if (can_put(map, tetri, fil) == 0)
		ft_printf("0 0\n");
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
	ft_putstr_fd("@@@@@@y:", 2);
	ft_putstr_fd(ft_itoa(y), 2);
	ft_putstr_fd("and x:", 2);
	ft_putstr_fd(ft_itoa(x), 2);
	tetri = malloc(sizeof(char **) * (y + 1));
	i++;
	l = 0;
	ft_putstr_fd("\nthis is the piece\n", 2);
	while (tab[i] != 0)
	{
		tetri[l] = ft_strdup(tab[i]);
		ft_putstr_fd(tetri[l], 2);
		ft_putstr_fd("\n", 2);
		i++;
		l++;
	}
	ft_putstr_fd("this was the piece\n", 2);
	tetri[l] = 0;
	puttetri(tab, tetri, fil);
}
