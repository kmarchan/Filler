/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_f.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 10:11:16 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/19 17:50:53 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include "get_next_line.h"

typedef struct	s_filler
{
	int			valid;
	int			fd;
	int			player;
	int			score;
	int			mcol;
	int			mlin;
	int			pcol;
	int			plin;
	int			ret_col;
	int			ret_lin;
	char		me;
	char		em;
	int			**hm;
	char		**tm;
	char		**mp;
	char		**pp;
}				t_fil;

typedef struct	s_l
{
	int			l;
	int			c;
	int			count;
	int			ovr;
	int			maxstar;
	int			ovrl;
	int			ovrc;
}				t_l;

int				start_emcol(t_fil *node);
int				start_emlin(t_fil *node);
int				start_col(t_fil *node);
int				start_row(t_fil *node);
int				find_stars(t_fil *node);
int				check_token_point(t_fil *node, int lin, int col);
int				find_stars(t_fil *node);
int				start_row(t_fil *node);
int				start_col(t_fil *node);
int				find_stars(t_fil *node);
int				get_line(int fd, char **line);
int				place_pos(t_fil *node, int col, int lin);
int				find_valid(t_fil *node);
int				score(t_fil *node, int lin, int col);
int				valid_pos(t_fil *node);
int				star_count(t_fil *node, char **ar);
int				fst_star_lin(t_fil *node);
int				fst_star_col(t_fil *node);
int				lst_star_lin(t_fil *node);
int				lst_star_col(t_fil *node);
int				set_coordinate(t_fil *node, int lin, int col);
void			straight_across(t_fil *node);
void			update_piece(t_fil *node);
void			straight_up(t_fil *node);
void			heat_up(t_fil *node, int e, int i);
void			heat_down(t_fil *node, int e, int i);
void			heat_back(t_fil *node, int e, int i);
void			heat_forward(t_fil *node, int e, int i);
void			heat_it(t_fil *node, int e, int i);
void			find_em_me(t_fil *node);
void			check_map(t_fil *node);
void			bzero_array(char **ar, int n);
void			update_map(t_fil *node);
void			malloc_temp(char **ar, t_fil *node);
void			temp_map(t_fil *node);
int				divide_map(t_fil *node);
void			find_em_me(t_fil *node);
void			get_symbol(t_fil *node);
void			read_player(t_fil *node);
void			heatmap(t_fil *node);
void			map(t_fil *node);
void			piece(t_fil *node);
void			ft_arrpop(int w, char **ret, char *str, char c);
void			mapsize(t_fil *node);
void			piecesize(t_fil *node);
char			**ft_strspliter(char *str, char c);
#endif
