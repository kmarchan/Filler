/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 07:08:28 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/19 14:30:22 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_values(t_l *val, t_fil *node)
{
	val->ovrl = lst_star_lin(node);
	val->ovrc = lst_star_col(node);
	val->maxstar = find_stars(node);
	val->l = 0;
	val->ovr = 0;
	val->count = 0;
}

int		check_locat(t_fil *node, int lin, int col)
{
	t_l val;

	set_values(&val, node);
	while (val.l < node->plin && lin + node->plin < node->mlin + val.ovrl)
	{
		val.c = 0;
		while (val.c < node->pcol && col + node->pcol < node->mcol + val.ovrc)
		{
			if (node->pp[val.l][val.c] == '*')
			{
				if ((node->mp[lin + val.l][col + val.c] == node->em ||
				node->mp[lin + val.l][col + val.c] == node->em - 32))
					return (0);
				if ((node->mp[lin + val.l][col + val.c] == node->me ||
				node->mp[lin + val.l][col + val.c] == node->me - 32))
					val.ovr++;
				if ((lin + val.l < node->mlin && lin + val.l >= 0) &&
				col + val.c < node->mcol && col + val.c >= 0)
					val.count++;
			}
			val.c++;
		}
		val.l++;
	}
	return (((val.count != val.maxstar || val.ovr != 1)) ? 0 : 1);
}

int		scorecheck(t_fil *node, int lin, int col)
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
			if (node->pp[l][c] == '*')
				score = score + node->hm[lin + l][col + c];
			c++;
		}
		l++;
	}
	return (score);
}

int		set_coordinate(t_fil *node, int lin, int col)
{
	node->ret_col = col;
	node->ret_lin = lin;
	return (1);
}

void	check_map(t_fil *node)
{
	int lin;
	int col;
	int tscore;

	lin = 0 - fst_star_lin(node);
	tscore = 0;
	while (lin < node->mlin)
	{
		col = 0 - fst_star_col(node);
		while (col < node->mcol)
		{
			if (col >= node->mcol)
				break ;
			{
				(check_locat(node, lin, col)) &&
				(tscore = scorecheck(node, lin, col));
				if (tscore > node->score)
				{
					(set_coordinate(node, lin, col) && (node->score = tscore));
				}
			}
			col++;
		}
		lin++;
	}
}
