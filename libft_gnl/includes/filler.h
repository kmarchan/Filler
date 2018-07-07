/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_f.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 10:11:16 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/07 15:44:44 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include "get_next_line.h"

/*
typedef	struct s_pos
{
	int			col;
	int			lin;
}				t_pos;
*/

typedef struct	s_filler
{
	int			fd;
	int			player;
	int			score;
//	t_pos		*map;
	int			mcol;
	int			mlin;
//	t_pos		*piece;
	int			pcol;
	int			plin;
//	t_pos		*ret;
	int			ret_col;
	int			ret_lin;

	char		me;
	char		em;
	
	int			**hm;
	char		**tm;
	char		**mp;
	char		**pp;
}				t_fil;

int     place_pos(t_fil *node, int col, int lin);
int		find_valid(t_fil *node);
int     score(t_fil *node);
int     valid_pos(t_fil *node);
int     star_count(t_fil *node, char **ar);
int     fst_star_lin(t_fil *node);
int     fst_star_col(t_fil *node);
void    temp_map(t_fil *node);
void    set_coordinate(t_fil *node, int lin, int col);
int     find_stars(t_fil *node);
int				check_token_point(t_fil *node, int lin, int col);
int				find_stars(t_fil *node);
int				start_row(t_fil *node);
int				start_col(t_fil *node);
int				find_stars(t_fil *node);
void			temp_map(t_fil *node);
void			divide_map(t_fil *node);
void			find_empty(t_fil *node);
void			get_symbol(t_fil *node);
void			read_player(t_fil *node);
void			heatmap(t_fil *node);
void			map(t_fil *node);
void			piece(t_fil *node);
void			set_coordinate(t_fil *node, int lin, int col);
void			ft_arrpop(int w, char **ret, char *str, char c);
void			**mapsize(t_fil *node);
void			**piecesize(t_fil *node);
char			**ft_strspliter(char *str, char c);
#endif
