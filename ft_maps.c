/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 20:53:27 by ryaoi             #+#    #+#             */
/*   Updated: 2017/03/29 01:28:49 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	get_cord(char c, t_fil *fil, int col, int line)
{
	if (c == 'O')
	{
		if (fil->c == 'O')
		{
			fil->my_x = col;
			fil->my_y = line;
		}
		else
		{
			fil->enemy_x = col;
			fil->enemy_y = line;
		}
	}
	else
	{
		if (fil->c == 'X')
		{
			fil->my_x = col;
			fil->my_y = line;
		}
		else
		{
			fil->enemy_x = col;
			fil->enemy_y = line;
		}
	}
}

static void	insert_cord(char *str, t_fil *fil)
{
	int		col;
	int		line;
	char	*ptr;

	ptr = str;
	line = ft_atoi(ptr);
	col = 0;
	while (*ptr != '.')
		ptr++;
	while (*ptr != 'O' && *ptr != 'X')
	{
		ptr++;
		col++;
	}
/*
	ft_putstr_fd("\n\ngot:", 2);
	ft_putchar_fd(*ptr, 2);
	ft_putstr_fd("\n\nco:", 2);
	ft_putstr_fd(ft_itoa(col), 2);
	ft_putstr_fd(",line:", 2);
	ft_putstr_fd(ft_itoa(line), 2);
	ft_putchar_fd('\n', 2);
*/
	get_cord(*ptr, fil, col, line);
}

void		recup_cord(char **tab, t_fil *fil)
{
	int		i;
	int		l;

	i = 0;
	while (tab[i] != 0 && ft_strncmp(tab[i], "00", 2) != 0)
		i++;
	if (tab[i] == 0)
	{
		ft_putstr_fd("couldnt get the coord\n",2);
		exit (0);
	}
	while (tab[i] != 0)
	{
		l = 0;
		while (tab[i][l] != '\0')
		{
			if (tab[i][l] == 'O' || tab[i][l] == 'X')
				insert_cord(tab[i], fil);
			l++;
		}
		i++;
	}
}

char		**cutmap(char **tab, t_fil *fil)
{
	char	**ret;
	int		i;
	int		skip;

	skip = 0;
	i = 0;
	if (!(ret = (char **)malloc(sizeof(char *) * (fil->line + 1))))
	{
		ft_printf("failed malloc when adjusting the map\n");
		exit(EXIT_FAILURE);
	}
	while (ft_strncmp(tab[i], "00", 2) != 0)
	{
		i++;
		skip++;
	}
	while (i < fil->line + skip)
	{
		ret[i - skip] = ft_strsub(tab[i], 4, ft_strlen(tab[i]) - 4);
		i++;
	}
	ret[i - skip]  = 0;
	return (ret);
}
