/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_valid_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:29:37 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/07 15:44:42 by kmarchan         ###   ########.fr       */
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
	l =0;
	while (l < node->plin)
	{
		i = 0;
		while (i < node->pcol)
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

//int		check_token_point(t_fil *node, int lin, int col)
//{
//	int	count;
//	int tc;
//	int tl;
//
//	count = 0;
//	tc = node->ret_col;
//	tl = node->ret_lin;
//	if (node->pp[lin][col] == '*' && (tl + lin >= 0 && tc + col >= 0) &&
//			(tl = lin < node->mlin && tc + col < node->mcol))
//		count++;
//	return (count);
//}

void    temp_map(t_fil *node)
{
    int     line;

    if (!node->tm)
    {
        node->tm = (char **)ft_memalloc(sizeof(char *) * node->mlin);
    }
    if (!node->mp)
        return ;
    line = 0;
    while (line < node->mlin)
    {
        node->tm[line] = ft_strdup(node->mp[line]);
        line++;
    }
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
			if(ar[lin][col] == node->me || ar[lin][col] == node->me - 32)
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
	int p;
	int count;

	count = 0;
	m = star_count(node, node->mp);
	count = star_count(node, node->tm);	
	p = find_stars(node);
	printf("count= %d, target=%d\n", count, m + p - 1);
	if (count == m + p - 1)
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
	while (lin < node->mlin)
	{
		while (col < node->mcol)
		{
			if (node->tm[lin][col] == node->me || node->tm[lin][col] == node->me - 32)
			{
				score += node->hm[lin][col];
			}	
			col++;
		}
		lin++;
	}
	if (score > node->score)
	{
		node->score = score;
		printf("score= %d\n", score);
		return (1);
	}
	else 
		return (0);
}

int		place_pos(t_fil *node, int col, int lin)
{
	int pc;
	int pl;

	pl = fst_star_lin(node);
	pc = fst_star_col(node);
	temp_map(node);
	while (pl <= node->plin)
	{
		pc = 0;
		while (pc <= node->pcol)
		{
			if (node->pp[pl][pc] == '*')
			{
				printf("hello\n");
				node->tm[lin][col] = node->me;
			}
			pc++;
			col++;	
		}
		pl++;
		lin++;
	}

	return (0);
}

int		find_valid(t_fil *node)
{
	int col;
	int lin;
	printf("test 6\n");
	col = 0;
	lin = 0;
	while (lin < node->mlin)
	{
		while(col < node->mcol)
		{
			place_pos(node, col, lin);
			if (valid_pos(node))
				if(score(node))
				{
					printf("test 7\n");
					set_coordinate(node, lin - node->plin, col - node->pcol); 
					node->score = score(node);
				}
			col++;
		}
		lin++;
	}
	return (1);
}
