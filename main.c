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
		ft_putstr_fd(node->mp[lin], 2);
		ft_putchar_fd('}', 2);
		lin++;
		ft_putchar_fd('\n', 2);
	}
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
printmap(node);
	piece(node);
	node->valid = 1;
	ft_putendl_fd("A", 2);
	while (1)
	{
		ft_putendl_fd("B", 2);
		heatmap(node);
		ft_putendl_fd("C", 2);
		check_map(node);
		ft_putendl_fd("D", 2);
		// if (node->valid == 0)
			// break ;
		ft_putendl_fd("E", 2);
		placementoutput(node->ret_lin, node->ret_col);
		ft_putendl_fd("F", 2);
		free(node->pp);
		node->score = 0;
		ft_putendl_fd("G", 2);
		update_map(node);
		printmap(node);
		ft_putendl_fd("H", 2);
		//piecesize(node);
		piece(node);
		
		//ft_putnbr_fd(node->plin, 2);
		//ft_putchar_fd('X', 2);
		//ft_putnbr_fd(node->pcol, 2);
		//ft_putchar_fd('n', 2);
	}
	return (0);
}	

