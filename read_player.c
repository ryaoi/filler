/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 17:34:00 by ryaoi             #+#    #+#             */
/*   Updated: 2017/03/29 01:29:55 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check_player(char *str, char *name)
{
	char		*ptr;

	ptr = str;
	while (*ptr != '\0')
	{
		if (ft_strncmp(ptr, name, ft_strlen(name)) == 0)
			return (1);
		ptr++;
	}
	return (0);
}

void		check_plateau(char *str, t_fil *fil)
{
	char		*ptr;
	int			i;

	i = 0;
	ptr = str;
	while (*ptr)
	{
		if (ft_isdigit(*ptr))
		{
			if (i == 0)
			{
				fil->line = ft_atoi(ptr);
				i = 1;
			}
			else
				fil->col = ft_atoi(ptr);
			while (ft_isdigit(*ptr))
				ptr++;
		}
		else
			ptr++;

	}
}

char		**read_player(t_fil *fil)
{
	char		**tab;
	
	if (!(tab = read_map()))
		return (NULL);
	if ((check_player(tab[0], "p1")) == 1)
	{
		fil->c = 'O';
		fil->enemy_c = 'X';
		check_plateau(tab[1], fil);
		recup_cord(tab, fil);
	}
	else
	{
		fil->c = 'X';
		fil->enemy_c = 'O';
		check_plateau(tab[1], fil);
		recup_cord(tab, fil);

	}
	return (tab);
}

char		**read_map(void)
{
	char		buf[4096];
	char		*str;
	char		**tab;
	int			ret;

	str = ft_strnew(0);
	ft_bzero(buf, 4096);
	ft_putstr_fd("waiting for read\n", 2);
	usleep(200 * 500);
	if ((ret = (read(0, buf, 4096))) > 0)
	{
		ft_putstr_fd(ft_itoa(ret), 2);
		buf[ret] = '\0';
		if (ft_strlen(str) == 0)
			str = ft_strdup(buf);
		else
			str = ft_strjoini(str, buf, 1);
		ft_bzero(buf, 4096);
	}
	ft_putstr_fd("end of read\n", 2);
	if (ret == -1)
	{
		ft_putstr_fd("something went wrong while reading\n", 2);
		exit(EXIT_FAILURE);
	}
	if (ret == 0 && ft_strlen(str) == 0)
	{
		ft_putstr_fd("str is NULL\n", 2);
		return (NULL);
	}
//	ft_putstr_fd("@@@@@@@@@@@@@@@@@@@@@@@\n", 2);
//	ft_putstr_fd(str, 2);
//	ft_putstr_fd("@@@@@@@@@@@@@@@@@@@@@@@\n", 2);
	if (ret != 4096)
	{
		tab = ft_strsplit(str, '\n');
		ft_strdel(&str);
		return (tab);
	}
	return (NULL);
}
