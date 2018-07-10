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

	maxstar = find_stars(node);
	l = 0;
	ovr = 0;
	count = 0;
	// ft_putchar_fd('w', 2);
	// ft_putnbr_fd(node->plin, 2);
	// ft_putchar_fd(' ', 2);
	// ft_putnbr_fd(node->pcol, 2);
	while (l < node->plin && lin + node->plin < node->mlin)
	{
		c = 0;
		while (c < node->pcol && col + node->pcol < node->mcol)
		{
			// ft_putchar_fd('c', 2);
			if (node->pp[l][c] == '*' && (node->mp[lin + l][col + c] == node->em || node->mp[lin + l][col + c] == node->em - 32))
			{
				return (0);
			}


			if (node->pp[l][c] == '*' && (node->mp[lin + l][col + c] == node->me || node->mp[lin +l][col + c] == node->me -32))
				ovr++;
			// ft_putchar_fd('m', 2);
			// if (ovr > 1)
			// 	return (0);

			if (node->pp[l][c] == '*' && (lin + l < node->mlin && lin + l > 0) && col + c < node->mcol && col + c > 0)
				count++;
			// ft_putchar_fd('v', 2);
			c++;
		}
		l++;
	}
	// ft_putchar_fd('v', 2);
	if (count == maxstar && ovr == 1)
		return (1);
	return (0);
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
	lin = 0;
	score = 0;
	x = 0;
	y = 0;
	// ft_putchar_fd('1', 2);
	while (lin < node->mlin)
	{
		// if (lin >= node->mlin)
		// 	break;
		// ft_putchar_fd('{', 2);
		// ft_putnbr_fd(lin, 2);
		// ft_putchar_fd('}', 2);
		// ft_putchar_fd('\n', 2);
		// ft_putchar_fd(' ', 2);
		// ft_putnbr_fd(lin, 2);
		
		// ft_putchar_fd('2', 2);
		col = 0;
		while (col < node->mcol)
		{
			if (col >= node->mcol)
				break;
			// ft_putchar_fd('\t', 2);
			// ft_putnbr_fd(node->mcol, 2);
			// ft_putchar_fd(' ', 2);
			// ft_putnbr_fd(col, 2);
			// ft_putchar_fd('\n', 2);
			if(check_locat(node, lin, col) == 1)
			{
				// ft_putchar_fd('5', 2);
				tscore = scorecheck(node, lin, col);
				// ft_putchar_fd('6', 2);
				if (tscore > score)
				{
					// ft_putchar_fd('7', 2);
					y = lin;
					x = col;
					score = tscore;
				}
				// ft_putchar_fd('1', 2);
			}
			// ft_putnbr_fd(col, 2);
			// ft_putnbr_fd(node->mcol, 2);
			// ft_putchar_fd('2', 2);
			col++;
			// ft_putchar_fd('2', 2);
		}
		// ft_putchar_fd('3', 2);
		// ft_putchar_fd('X', 2);
		lin++;
		// if (lin >= node->mlin)
		// 	break;
		// ft_putchar_fd('4', 2);
	}
	// node->ret_lin = 0;
	// node->ret_col = 0;
	set_coordinate(node, y, x);
	// ft_putchar_fd('[', 2);
	// ft_putnbr_fd(y, 2);
	// ft_putchar_fd(' ', 2);
	// ft_putnbr_fd(x, 2);
	// ft_putchar_fd(']', 2);
	// ft_putchar_fd('9', 2);
}