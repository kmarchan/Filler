/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 07:08:28 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/10 07:08:30 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#include <stdio.h>

int		find_stars(t_fil *node)
{
	int i;
	int l;
	int stars;

	stars = 0;
	i = 0;
	l = 0;
	while (l < node->plin)
	{
		i = 0;
		while (i <= node->pcol)
		{
			if (node->pp[l][i] == '*')
			{
				stars++;
			}
			i++;
		}
		l++;
	}
	// ft_putchar_fd('S', 2);
	return (stars);
}

int check_locat(t_fil *node, int lin, int col)
{
	int l;
	int c;
	int count;
	int ovr;
	int maxstar;
	int ovrl;
	int ovrc;

	ovrl = lst_star_lin(node);
	ovrc = lst_star_col(node);
	maxstar = find_stars(node);
	l = 0;
	ovr = 0;
	count = 0;
	while (l < node->plin && lin + node->plin < node->mlin + ovrl)
	{
		c = 0;
		while (c < node->pcol && col + node->pcol < node->mcol + ovrc)
		{
			if (node->pp[l][c] == '*')
			{
				if ((node->mp[lin + l][col + c] == node->em ||
				node->mp[lin + l][col + c] == node->em - 32))
				{
					return (0);
				}
				if ((node->mp[lin + l][col + c] == node->me ||
				node->mp[lin +l][col + c] == node->me -32))
					ovr++;
				if ((lin + l < node->mlin && lin + l >= 0) &&
				col + c < node->mcol && col + c >= 0)
					count++;
			}
			c++;
		}
		l++;
	}
	if (count != maxstar || ovr != 1)
		return (0);
	return (1);
}

int scorecheck(t_fil *node, int lin, int col)
{
	int l;
	int c;
	int score;

	l = 0;
	score = 0;
	while (l < node->plin)
	{
		c = 0;
		while (c < node->pcol)
		{
			if(node->pp[l][c] == '*')
				score = score + node->hm[lin + l][col + c];
			c++;
		}
		l++;
	}
	return (score);
}

void	set_coordinate(t_fil *node, int lin, int col)
{
	node->ret_col = col;
	node->ret_lin = lin;
}

void	check_map(t_fil *node)
{
	int lin;
	int col;
	int x;
	int y;
	int tscore;
	int	score;

	node->score = 0;
	lin = 0 - fst_star_lin(node);
	tscore = 0;
	score = 0;
	tscore = 0;
	x = 0;
	y = 0;
//	int sl = lst_star_lin(node);
//	int sc = lst_star_col(node);
//	ft_putchar_fd('{', 2);
//	ft_putnbr_fd(sl, 2);
//	ft_putchar_fd(' ', 2);
//	ft_putnbr_fd(sc, 2);
//	ft_putchar_fd('}', 2);
	while (lin < node->mlin)
	{
		col = 0 - fst_star_col(node);
		while (col < node->mcol)
		{
			if (col >= node->mcol)
				break;
			{
				if (check_locat(node, lin, col) == 1)
					tscore = scorecheck(node, lin, col);
				if (tscore > score)
				{
					y = lin;
					x = col;
					score = tscore;
				}
			}
			col++;
		}
		lin++;
	}
	if (score == 0)
		node->valid = 0;
	set_coordinate(node, y, x);
}
