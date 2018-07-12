/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 13:56:21 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/10 06:23:42 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "filler.h"
#include <stdio.h>

void    placementoutput(int y, int x)
{
    char *ret;

    ret = ft_strjoin(ft_itoa(y), " ");
    ft_strcat(ret, ft_itoa(x));
    ft_putendl_fd(ret, 1);
    ft_putendl_fd(ret, 2);
    free(ret);
}

int		main()
{
	t_fil	*node;
	int l = 0;
	int m = 0;
	(void)l;
	(void)m;

	node = (t_fil*)ft_memalloc(sizeof(t_fil));
	node->mlin = 0;
	node->mcol = 0;
	node->fd = 0;//open("map_o2.txt", O_RDONLY);
	
	read_player(node);
	mapsize(node);
  	map(node);
	if (strstr(node->mp[0], "."))
		m = 1;
	piece(node);
	node->valid = 1;
	while (node->valid == 1)
	{
		heatmap(node);
		check_map(node);
		if (node->valid == 0)
			break ;
		placementoutput(node->ret_lin, node->ret_col);

		free(node->pp);
		node->plin = 0;
		node->pcol = 0;
		node->score = 0;

		update_map(node);
		//piecesize(node);
		piece(node);

		//ft_putnbr_fd(node->plin, 2);
		//ft_putchar_fd('X', 2);
		//ft_putnbr_fd(node->pcol, 2);
		//ft_putchar_fd('n', 2);
	}
	return (0);
}	
