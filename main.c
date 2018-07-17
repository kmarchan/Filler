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

void	printmap(t_fil *node)
{
	int lin = 0;
	while (lin < node->mlin)
	{
		ft_putchar_fd('{', 2);
		int col = 0;
		while (col < node->mcol)
		{
			ft_putnbr_fd(node->hm[lin][col], 2);
			col++;
		}
		ft_putchar_fd('}', 2);
		lin++;
		ft_putchar_fd('\n', 2);
	}
	ft_putchar_fd('\n', 2);
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
	node->fd = 0;
	
	read_player(node);
	mapsize(node);
  	map(node);
	piece(node);
	node->valid = 1;
	while (1)
	{
		heatmap(node);
		 // printmap(node);
		check_map(node);
		placementoutput(node->ret_lin, node->ret_col);
		free(node->pp);
		node->score = 0;
		update_map(node);
		piece(node);
	}
	return (0);
}
