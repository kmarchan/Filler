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
	// ft_putendl_fd("boo", 2);
	ret = (get_line(node->fd, &piece));
//	printf("{%s}\n", piece);
	// ft_putchar_fd('R', 2);
	// ft_putendl_fd(piece, 2);
	while (ft_strstr(piece, "Piece") == NULL)
	{
	//	printf("piecesize");
		// ft_putchar_fd('r', 2);
		// ft_putendl_fd(piece, 2);
		ret = (get_next_line(node->fd, &piece));
	}
//	printf("{%s}", piece);
	// ft_putendl_fd("booB", 2);
	ptr2 = ft_strspliter(piece, ' ');
	node->plin = (ft_atoi(ptr2[1]));
	node->pcol = (ft_atoi(ptr2[2]));
	// ft_putnbr_fd(node->plin, 2);
	// ft_putnbr_fd(node->pcol, 2);
//	printf("plin%d, pcol%d\n", node->plin, node->pcol);
	return(0);
}

void	update_piece(t_fil *node)
{
	int		ret;
	int		line;
	char	*read;
	line = 0;
	ret = 0;
	(void)ret;
	node->pp = (char **)ft_memalloc(sizeof(char *) * node->plin);
	while (line < node->plin)
	{
		
		ret = get_next_line(node->fd, &read);
		node->pp[line] = ft_strdup(read);
		// ft_putendl_fd("bop", 2);
		// ft_putendl_fd(node->pp[line], 2);
		line++;
		ft_strdel(&read);
	}
}

void	piece(t_fil *node)
{
	int		ret;
	int		line;
	char	*read;

	(void)ret;
	// ft_putendl_fd("PIECE", 2);
	node->pp = (char **)ft_memalloc(sizeof(char *) * node->plin);
	piecesize(node);
	line = 0;
	while (line < node->plin)
	{
		// ft_putendl_fd("bop", 2);
		ret = get_next_line(node->fd, &read);
		node->pp[line] = ft_strdup(read);
		// ft_putendl_fd(node->pp[line], 2);
		line++;
		ft_strdel(&read);
	}
}

