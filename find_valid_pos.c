/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_valid_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:29:37 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/09 12:30:29 by kmarchan         ###   ########.fr       */
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

//    if (!node->tm)
  //  {
//        node->tm = (char **)ft_memalloc(sizeof(char *) * node->mlin);
//    }
//   if (!node->mp)
//        return ;
	line = 0;
	ft_putchar_fd('1', 2);
	while (line < node->mlin)
	{
        	ft_strcpy(node->tm[line], node->mp[line]);
		ft_putchar_fd('2', 2);
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
//	printf("map= %d, piece=%d\n", m, p);
//	printf("count= %d, target=%d\n", count, m + p - 1);
//	ft_putstr_fd("count", 2);
//	ft_putnbr_fd(count, 2);
//	ft_putchar_fd(' ', 2);
//	ft_putstr_fd("target", 2);
//	ft_putnbr_fd(m + p - 1, 2);
//	ft_putchar_fd('\n', 2);
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
			//	printf("isetscore= %d\n", score);
			}	
		//	printf("hm %d\n", node->hm[lin][col]);
		//	printf("col=%d\n", col);
			col++;
		}
//		printf("lin =%d\n", lin);
		lin++;
	}
	if (score > node->score)
	{
		node->score = score;
//		printf("score= %d\n", score);
		return (1);
	}
	else 
		return (0);
}

int		place_pos(t_fil *node, int col, int lin)
{
	int pc;
	int pl;
	int h;
	int s;

	s = find_stars(node);
	pl = 0;//fst_star_lin(node);
	pc = 0;//fst_star_col(node);
	h = col;
	(void)h;
//	temp_map(node);
//	printf("placelin%d\n", lin);
//	printf("placecol%d\n", col);
//	printf("test 6\n");
	while(s--)
	{
		ft_putstr_fd("pos1\n", 2);
		while (pl < node->plin && lin < node->mlin - (node->plin - pl))
		{
			ft_putstr_fd("pos2\n", 2);
			pc = 0; 
			col = h;
			while (pc < node->pcol && col < node->mcol - (node->pcol - pc))
			{
				ft_putstr_fd("pos3\n", 2);
				if (node->pp[pl][pc] == '*')
				{
				//	printf("m%d:%d\np%d:%d\n", lin, col, pl, pc);
					node->tm[lin][col] = node->me;
					ft_putstr_fd("pos4\n", 2);
				}
				pc++;
				col++;	
			}
			pl++;
			lin++;
		}
	}
	int i = 0;
	int l = 0;
	while (l <  node->mlin)
	{
		i = 0;
		while (i < node->mcol)
		{
		        ft_putchar_fd(node->tm[l][i], 2);
		        i++;
		}
		ft_putchar_fd('\n', 2);
		l++;
	}	
	return (0);
}

int		find_valid(t_fil *node)
{
	int col;
	int lin;
	col = 0;
	lin = 0;
	while (lin < node->mlin)
	{
		col = 0;
		while(col < node->mcol)
		{
//			printf("findcol%d\n", col);
			ft_putchar_fd('H', 2);
			place_pos(node, col, lin);
			ft_putchar_fd('h', 2);
			if (valid_pos(node))
			{
				ft_putchar_fd('I', 2);
//				printf("test 4\n");
				if(score(node))
				{
					ft_putchar_fd('J', 2);
//					printf("test 5\n");
					set_coordinate(node, lin -1, col); 
					node->score = score(node);
				}
			}
			col++;
		}
		lin++;
	}
	return (1);
}
