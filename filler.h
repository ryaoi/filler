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
	int				x;
	int				y;
	int				touched;
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


void	ft_player(t_fil *fil);
char	**ft_readpiece(void);
char	**ft_readmap(t_fil *fil);
void	freetab(char **tab);
void    failure(void);
char	**cutmap(char **tab, t_fil *fil);
void	first_move(t_fil *fil, char **tab);
void    strat_up(t_fil *fil, t_tetri tet);
int		valid_put(t_tetri tet, int i, int l, t_fil *fil);
int		check_line(char **tab, t_fil *fil, int l, int line);
int		check_side(char **tab, t_fil *fil, int l, int line);
int		bottomright(t_tetri tet, t_fil *fil);
int		bottomleft(t_tetri tet, t_fil *fil);
int		topright(t_tetri tet, t_fil *fil);
int		topleft(t_tetri tet, t_fil *fil);
int		middlebottomleft(t_tetri tet, t_fil *fil);
int		testleft(t_tetri tet, t_fil *fil);
int		fromoriginy(t_tetri tet, t_fil *fil);
int		fromoriginx(t_tetri tet, t_fil *fil);
int		fromoriginxdown(t_tetri tet, t_fil *fil);
int		fromoriginydown(t_tetri tet, t_fil *fil);
int		gotomiddlefromo(t_tetri tet, t_fil *fil);
int		middletotopright(t_tetri tet, t_fil *fil);
int		virusdown(t_tetri tet, t_fil *fil);
int		virusup(t_tetri tet, t_fil *fil);
int		surroundx(t_tetri tet, t_fil *fil);
int		check_surroundx(char **map, t_fil *fil);

#endif
