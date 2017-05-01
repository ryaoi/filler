/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:18:05 by ryaoi             #+#    #+#             */
/*   Updated: 2017/04/01 03:27:10 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		check_player(char *str, char *name)
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

static void		check_plateau(char *str, t_fil *fil)
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

void		ft_player(t_fil *fil)
{
	char		*line;
	int			ret;

	line = NULL;
	ret = get_next_line(0, &line);
	ft_putstr_fd(line, 2); //delete
	if (check_player(line, "p1") == 1)
	{
		fil->c = 'O';
		fil->enemy_c = 'X';
	}
	else
	{
		fil->c = 'X';
		fil->enemy_c = 'O';
	}
	ft_strdel(&line);
	ret = get_next_line(0, &line);
	ft_putstr_fd(line, 2); //delete
	check_plateau(line, fil);
	ft_strdel(&line);
}
