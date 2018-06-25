/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 13:46:58 by kmarchan          #+#    #+#             */
/*   Updated: 2018/06/24 13:47:35 by kmarchan         ###   ########.fr       */
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
	ret = (get_next_line(node->fd, &piece));
	while (ft_strstr(piece, "Piece") == NULL && ret != 0)
	{
		ret = (get_next_line(node->fd, &piece));
	}
	ptr2 = ft_strspliter(piece, ' ');
	node->plin = (ft_atoi(ptr2[1]));
	node->pcol = (ft_atoi(ptr2[2]));
	return (0);
}


void	piece(t_fil *node)
{
	int ret;
	int line;
	char *read;
	(void)ret;

	if (!node->pp)
	{
		node->pp = (char **) ft_memalloc(sizeof(char *) * node->plin);
		piecesize(node);
	}
	if (!node->pp)
		return ;
	line = 0;
	ft_putendl("p");
	while (line < node->plin)
	{
		ft_putendl("R");
		ret = get_next_line(node->fd, &read);
		
		node->pp[line] = ft_strdup(read);
//		ft_putendl(node->pp[line]);
		line++;
		ft_strdel(&read);
	}
}


