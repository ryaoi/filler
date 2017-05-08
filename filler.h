/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 20:32:29 by ryaoi             #+#    #+#             */
/*   Updated: 2017/03/30 20:00:57 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

typedef	struct		s_tetri
{
	int				tetri_x;
	int				tetri_y;
	char			**tetri;
	char			**map;
}					t_tetri;

typedef	struct		s_fil
{
	int				col;
	int				line;
	char			c;
	char			enemy_c;
	int				enemy_x;
	int				enemy_y;
	int				my_y;
	int				my_x;
	int				start;
}					t_fil;


// delete
void	printab(char **tab);
//
void	ft_player(t_fil *fil);
char	**ft_readpiece(void);
char	**ft_readmap(t_fil *fil);
void	freetab(char **tab);
void    failure(void);
char	**cutmap(char **tab, t_fil *fil);
void	first_move(t_fil *fil, char **tab);
void    strat_up(t_fil *fil, t_tetri tet);
int		valid_put(char **tab, char **tetri, int i, int l, t_fil *fil);
int		check_line(char **tab, t_fil *fil, int l, int line);
int		check_side(char **tab, t_fil *fil, int l, int line);
int		bottomright(char **tab, char **tetri, t_fil *fil);
int		bottomleft(char **tab, char **tetri, t_fil *fil);
int		topright(char **tab, char **tetri, t_fil *fil);
int		topleft(char **tab, char **tetri, t_fil *fil);
int		middlebottomleft(char **tab, char **tetri, t_fil *fil);
int		testleft(char **tab, char **tetri, t_fil *fil);
int		fromoriginy(char **tab, char **tetri, t_fil *fil);
int		fromoriginx(char **tab, char **tetri, t_fil *fil);
int		fromoriginxdown(char **tab, char **tetri, t_fil *fil);
int		fromoriginydown(char **tab, char **tetri, t_fil *fil);
int		gotomiddlefromo(char **tab, char **tetri, t_fil *fil);
int		middletotopright(char **tab, char **tetri, t_fil *fil);
int		virusdown(char **tab, char **tetri, t_fil *fil);
int		virusup(char **tab, char **tetri, t_fil *fil);
int		surroundx(char **tab, char **tetri, t_fil *fil);
int		check_surroundx(char **map, t_fil *fil);

#endif
