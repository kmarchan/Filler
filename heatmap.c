/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 12:58:40 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/08 12:48:37 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdio.h>

int		start_col(t_fil *node)
{
	int e;
	int i;

	e = 0;
	while (e < node->mlin)
	{
		i = 0;
		while (node->mp[e][i] != '\0')
		{
			if (node->mp[e][i] == node->me || node->mp[e][i] == node->me - 32)
			{
				return (i);
			}
			i++;
		}
		e++;
	}
	return (i);
}

int		start_row(t_fil *node)
{
	int e;
	int i;

	e = 0;
	while (e < node->mlin)
	{
		i = 0;
		while (node->mp[e][i] != '\0')
		{
			if (node->mp[e][i] == node->me || node->mp[e][i] == node->me - 32)
			{
				return (e);
			}
			i++;
		}
		e++;
	}
	return (e);
}

void	get_heat(t_fil *node, int lin, int col)
{
	// int hl;
	// int hc;
	int v;
	int l;
	int c;
	v = 9;
	l = 1;
	c = 1;
	while (v > 1 &&lin + l < node->mlin && lin - l > 0 && col + c < node->mcol && col - c > 0)
	// {
	// 	col = 0;
		// while ()
		{
			// if (node->mp[lin][col] == node->em)
			// {
				// if (node->hm[lin - l][col] != 1 && node->hm[lin - l][col] != 0) 
					node->hm[lin-l][col-c] = v;
					node->hm[lin-l][col] = v;
					node->hm[lin-l][col+c] = v;
				// if (node->hm[lin][col-c] != 1 && node->hm[lin][col-c] != 0)
					node->hm[lin][col-c] = v;
				// if (node->hm[lin][col+c] != 1 && node->hm[lin][col+c] != 0)
					node->hm[lin][col+c] = v;
					node->hm[lin+l][col-c] = v;
				// if (node->hm[lin+l][col] != 1 && node->hm[lin + l][col] != 0)
					node->hm[lin+l][col] = v;
				// node->hm[lin+l][col+c] = v;
				v--;
				l++;
				c++;
			// }

		}
		// lin++;
	// }
}

void	divide_map(t_fil *node)
{
	int e;
	int i;
	int c;
	int r;

	e = 0;
	r = start_row(node);
	c = start_col(node);
	while (e < node->mlin)
	{
		i = 0;
		while (node->mp[e][i] != '\0')
		{
			if ((e == r || i == c) && node->hm[e][i] != 1)
				node->hm[e][i] = 3;
			i++;
		}
		e++;
	}
}

void	heat_back(t_fil *node, int lin, int col)
{
	int v;
	int c;
	v = 9;
	c = 1;
	while(v > 1 && col - c > 0)
	{
		if (node->mp[lin][col-c] == '.')//(node->mp[lin][col-c] != node->me || node->mp[lin][col-c] != node->me - 32 || node->mp[lin][col-c] != node->em || node->mp[lin][col-c] != node->em -32)
		{
			node->hm[lin][col-c] = v;	
		}
		c++;
		v--;
	}
}

void	heat_forward(t_fil *node, int lin, int col)
{
	int v;
	int c;
	v = 9;
	c = 1;
	while(v > 1 && col + c < node->mcol)
	{
		if (node->mp[lin][col + c] == '.')//(node->mp[lin][col + c] != node->me || node->mp[lin][col+c] != node->me - 32 || node->mp[lin][col+c] != node->em || node->mp[lin][col+c] != node->em -32)
		{
			node->hm[lin][col + c] = v;
		}
		c++;
		v--;
	}
}

void	heat_up(t_fil *node, int lin, int col)
{
	int v;
	int l;
	v = 9;
	l = 1;
	while(v > 1 && lin - l > 0)
	{
		if (node->mp[lin - l][col] == '.')//(node->mp[lin - l][col] != node->me || node->mp[lin - l][col] != node->me - 32 ||	node->mp[lin - l][col] != node->em || node->mp[lin - l][col] != node->em -32)
		{
			node->hm[lin - l][col] = v;
			// ft_putendl_fd("THE ENEMY", 2);
		}
		l++;
		v--;
	}
}

void	heat_down(t_fil *node, int lin, int col)
{
	int v;
	int l;
	v = 9;
	l = 1;
	while(v > 1 && lin + l < node->mlin)
	{
		if (node->mp[lin + l][col] == '.')//(node->mp[lin +l][col] != node->me || node->mp[lin+l][col] != node->me - 32 || node->mp[lin+l][col] != node->em || node->mp[lin+l][col] != node->em -32)
		{
			node->hm[lin + l][col] = v;
		}
		l++;
		v--;
	}
}

// void	set_heat(t_fil, int lin, int col)
// {
// 	int v;
// 	v = 9;
// 	int l;
// 	int c;
// 	l = lin -v;
// 	c = col -v;
// 	while (v-- && lin -v > 0 && lin + v < node->mlin)
// 	{

// 	}
// }

void	find_em_me(t_fil *node)
{
	int e;
	int i;

	e = 0;
	while (e < node->mlin)
	{
		i = 0;
		while (node->mp[e][i] != '\0')
		{

			if (node->mp[e][i] == node->em || node->mp[e][i] == node->em - 32)
			{
				heat_up(node, e, i);
				heat_down(node, e, i);
				heat_back(node, e, i);
				heat_forward(node, e, i);// get_heat(node, e, i);
				node->hm[e][i] = -1;
			}
			if (node->mp[e][i] == '.' && node->hm[e][i] == 0)
				node->hm[e][i] = 2;
			if (node->mp[e][i] == node->me || node->mp[e][i] == node->me - 32)
				node->hm[e][i] = 1;
			// if (node->hm[e][i] == 1 )//|| node->mp[e][i] == node->em - 32)
			// {
				// get_heat(node, e, i);
				// node->hm[e][i] = 1;
			// }
			// if (node->mp[e][i] == node->me || node->mp[e][i] == node->me - 32)
			// 	node->hm[e][i] = 1;
			
			i++;
		}
		e++;
	}
}

void	heatmap(t_fil *node)
{
	int e;

	e = 0;
	if (!node->hm)
	{
		node->hm = (int **)ft_memalloc(sizeof(int *) * node->mlin);
		while (e <= node->mlin)
		{
			node->hm[e] = (int *)ft_memalloc(sizeof(int) * node->mcol);
			e++;
		}
	}
	get_symbol(node);
	// get_heat(node);
	// do_heat_map(node);
	// divide_map(node);
	find_em_me(node);
	// divide_map(node);
}
