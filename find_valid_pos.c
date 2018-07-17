/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_valid_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:29:37 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/10 06:45:24 by kmarchan         ###   ########.fr       */
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
	return (stars);
}

void	set_coordinate(t_fil *node, int lin, int col)
{
	node->ret_col = col;
	node->ret_lin = lin;
}

int		fst_star_lin(t_fil *node)
{
	int pc;
	int pl;

	pc = 0;
	pl = 0;
	while (pl < node->plin)
	{
		pc = 0;
		while(pc < node->pcol)
		{
			if (node->pp[pl][pc] == '*')
			{
				return (pl);
			}
			pc++;
		}	
		pl++;
	}
	return (pl);
}

int		fst_star_col(t_fil *node)
{
	int pc;
	int pl;
	int c;

	pc = 0;
	pl = 0;
	c = node->pcol;
	while (pl < node->plin)
	{
		pc = 0;
		while(pc < node->pcol)
		{
			if (node->pp[pl][pc] == '*')
				if (c < pc)
				{
					c = pc;
				}					
			pc++;
		}	
		pl++;
	}
	return (c);
}

int		star_count(t_fil *node, char **ar)
{
	int lin;
	int col;
	int count;

	lin = 0;
	col = 0;
	count = 0;
	while (lin < node->mlin)
	{
		col = 0;
		while (col < node->mcol)
		{
			if(ar[lin][col] == node->me ||
			ar[lin][col] == node->me - 32)
				count++;
			col++;
		}
		lin++;
	}
	return (count);
}

int 	count_em(t_fil *node, char **ar)
{
	int lin;
	int col;
	int count;

	lin = 0;
	col = 0;
	count = 0;
	while (lin < node->mlin)
	{
		col = 0;
		while (col < node->mcol)
		{
			if(ar[lin][col] == node->em ||
			ar[lin][col] == node->em - 32)
				count++;
			col++;
		}
		lin++;
	}
	return (count);
}

int		valid_pos(t_fil *node)
{
	int m;
	int em;
	int p;
	int count;

	count = 0;
	m = star_count(node, node->mp);
	count = star_count(node, node->tm);	
	p = find_stars(node);
	em = count_em(node, node->mp);
	if ((count == m + p - 1) && (em == count_em(node, node->tm)))
		return (1);
	else 
		return (0);
}

int		score(t_fil *node)
{
	int lin;
	int col;
	int score;

	lin = 0;
	col = 0;
	score = 0;
	while (lin !=  node->mlin)
	{
		col = 0;
		while (col !=  node->mcol)
		{
			if (node->tm[lin][col] == node->me ||
			node->tm[lin][col] == node->me - 32)
			{
				score = score+node->hm[lin][col];
			}	
			col++;
		}
		lin++;
	}
	if (score > node->score)
	{
		node->score = score;
		return (1);
	}
	else 
		return (0);
}

int		find_valid(t_fil *node)
{
	int col;
	int lin;
	col = 0;
	lin = 0;
	node->score = 0;
	while (lin < node->mlin)
	{
		col = 0;
		while(col < node->mcol)
		{
			if (valid_pos(node) == 1)
			{
				if(score(node))
				{
					set_coordinate(node, lin -1, col); 
					node->score = score(node);
				}
				bzero_array(node->tm, node->mlin);
			}
			col++;
		}
		lin++;
	}
	if (score == 0)
		node->valid = 0;
	return (1);
}
