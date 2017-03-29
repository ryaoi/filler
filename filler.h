/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 20:32:29 by ryaoi             #+#    #+#             */
/*   Updated: 2017/03/29 01:03:24 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

typedef	struct		s_fil
{
	int				col;
	int				line;
	char			c;
	char			enemy_c;
	int				touched;
	int				enemy_x;
	int				enemy_y;
	int				my_y;
	int				my_x;
}					t_fil;

char	**read_player(t_fil *fil);
void	check_plateau(char *str, t_fil *fil);
char	**read_map(void);
void	freetab(char **tab);
void	recup_cord(char **tab, t_fil *fil);
char	**cutmap(char **tab, t_fil *fil);
void	first_move(t_fil *fil, char **tab);
int		valid_put(char **tab, char **tetri, int i, int l, t_fil *fil);
int		bottomright(char **tab, char **tetri, t_fil *fil);
int		bottomleft(char **tab, char **tetri, t_fil *fil);
int		topright(char **tab, char **tetri, t_fil *fil);
int		topleft(char **tab, char **tetri, t_fil *fil);


#endif
