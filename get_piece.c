/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 13:46:58 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/09 06:40:21 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void	**piecesize(t_fil *node)
{
	int		ret;
	char	**ptr2;
	char	*piece;

	ret = 0;
	(void)ret;
	node->plin = 0;
	node->pcol = 0;
	ret = (get_next_line(node->fd, &piece));
	while (ft_strstr(piece, "Piece") == NULL && ret != 0)
	{
		ret = (get_next_line(node->fd, &piece));
	}
	ptr2 = ft_strspliter(piece, ' ');
	node->plin = (ft_atoi(ptr2[1]));
	node->pcol = (ft_atoi(ptr2[2]));
	return(0);
}

void	piece(t_fil *node)
{
	int		ret;
	int		line;
	char	*read;

	(void)ret;
	piecesize(node);
	node->pp = (char **)ft_memalloc(sizeof(char *) * node->plin);
	line = 0;
	while (line < node->plin)
	{
		ret = get_next_line(node->fd, &read);
		node->pp[line] = ft_strdup(read);
		line++;
		ft_strdel(&read);
	}
}

