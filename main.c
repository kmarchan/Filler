/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 13:56:21 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/21 13:26:54 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"
#include <stdio.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void	placementoutput(int y, int x)
{
	char *ret;

	ret = ft_strjoin(ft_itoa(y), " ");
	ft_strcat(ret, ft_itoa(x));
	ft_putendl_fd(ret, 1);
	free(ret);
}

void	printmap(t_fil *node)
{
	int lin;
	int col;

	lin = 0;
	while (lin < node->mlin)
	{
		col = 0;
		while (col < node->mcol)
		{
			ft_putnbr_fd(node->hm[lin][col], 2);
			col++;
		}
		lin++;
		ft_putchar_fd('\n', 2);
	}
	ft_putchar_fd('\n', 2);
}

void	my_printmap(t_fil *node)
{
	int lin;
	int col;

	lin = 0;
	while (lin < node->mlin)
	{
		col = 0;
		while (col < node->mcol)
		{
			if (node->mp[lin][col] == node->em ||
			node->mp[lin][col] == node->em - 32)
				ft_putstr_fd(RED "X", 2);
			else if (node->mp[lin][col] == node->me ||
			node->mp[lin][col] == node->me - 32)
				ft_putstr_fd(GRN "X", 2);
			else
				ft_putstr_fd(RESET ".", 2);
			col++;
		}
		lin++;
		ft_putstr_fd(RESET "\n", 2);
	}
	ft_putchar_fd('\n', 2);
}

int		reset(t_fil *node)
{
	free(node->pp);
	node->score = 0;
	update_map(node);
//	my_printmap(node);
	piece(node);
	return (1);
}

int		main(void)
{
	t_fil	*node;
	int		l;
	int		m;

	l = 0;
	m = 0;
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
		check_map(node);
		placementoutput(node->ret_lin, node->ret_col);
		reset(node);
	}
	return (0);
}
