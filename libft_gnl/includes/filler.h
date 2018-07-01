/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_f.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 10:11:16 by kmarchan          #+#    #+#             */
/*   Updated: 2018/06/20 10:42:28 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include "get_next_line.h"

typedef struct	s_filler
{
	int		fd;
	int		player;
	int		mcol;
	int		mlin;
	int		pcol;
	int		plin;
	int		**hm;
	char		me;
	char		them;
	char		**mp;
	char		**pp;
}			t_fil;

void		get_symbol(t_fil *node);
void            read_player(t_fil *node);
void		heatmap(t_fil *node);
void	**mapsize(t_fil *node);
void    map(t_fil *node);
void    **piecesize(t_fil *node);
void    piece(t_fil *node);
void    ft_arrpop(int w,char **ret, char *str, char c);
char    **ft_strspliter(char *str, char c);
#endif
