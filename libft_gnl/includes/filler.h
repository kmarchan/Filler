/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_f.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 10:11:16 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/06 09:53:27 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include "get_next_line.h"

typedef struct	s_filler
{
	int			fd;
	int			player;
	int			mcol;
	int			mlin;
	int			pcol;
	int			plin;
	int			**hm;
	int			ret_col;
	int			ret_lin;
	char		me;
	char		em;
	char		**mp;
	char		**pp;
}				t_fil;
int				find_stars(t_fil *node);
int				start_row(t_fil *node);
int				start_col(t_fil *node);
void			divide_map(t_fil *node);
void			find_empty(t_fil *node);
void			get_symbol(t_fil *node);
void			read_player(t_fil *node);
void			heatmap(t_fil *node);
void			map(t_fil *node);
void			piece(t_fil *node);
void			ft_arrpop(int w, char **ret, char *str, char c);
void			**mapsize(t_fil *node);
void			**piecesize(t_fil *node);
char			**ft_strspliter(char *str, char c);
#endif
