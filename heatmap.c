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

// int		start_emcol(t_fil *node)
// {
// 	int	e;
// 	int	i;

// 	e = 0;
// 	while (e < node->mlin)
// 	{
// 		i = 0;
// 		while (node->mp[e][i] != '\0')
// 		{
// 			if (node->mp[e][i] == node->em ||
// 			node->mp[e][i] == node->em - 32)
// 			{
// 				return (i);
// 			}
// 			i++;
// 		}
// 		e++;
// 	}
// 	return (i);
// }

// int		start_emlin(t_fil *node)
// {
// 	int e;
// 	int i;

// 	e = 0;
// 	while (e < node->mlin)
// 	{
// 		i = 0;
// 		while (node->mp[e][i] != '\0')
// 		{
// 			if (node->mp[e][i] == node->em ||
// 			node->mp[e][i] == node->em - 32)
// 			{
// 				return (e);
// 			}
// 			i++;
// 		}
// 		e++;
// 	}
// 	return (e);
// }

// int		start_col(t_fil *node)
// {
// 	int e;
// 	int i;

// 	e = 0;
// 	while (e < node->mlin)
// 	{
// 		i = 0;
// 		while (node->mp[e][i] != '\0')
// 		{
// 			if (node->mp[e][i] == node->me ||
// 			node->mp[e][i] == node->me - 32)
// 			{
// 				return (i);
// 			}
// 			i++;
// 		}
// 		e++;
// 	}
// 	return (i);
// }

// int		start_row(t_fil *node)
// {
// 	int e;
// 	int i;

// 	e = 0;
// 	while (e < node->mlin)
// 	{
// 		i = 0;
// 		while (node->mp[e][i] != '\0')
// 		{
// 			if (node->mp[e][i] == node->me ||
// 			node->mp[e][i] == node->me - 32)
// 			{
// 				return (e);
// 			}
// 			i++;
// 		}
// 		e++;
// 	}
// 	return (e);
// }

// void	divide_map(t_fil *node)
// {
// 	int e;
// 	int i;
// 	int c;
// 	int r;

// 	e = 0;
// 	r = start_row(node);
// 	c = start_col(node);
// 	while (e < node->mlin)
// 	{
// 		i = 0;
// 		while (node->mp[e][i] != '\0')
// 		{
// 			if ((e == r || i == c) && node->hm[e][i] != 1)
// 				node->hm[e][i] = 3;
// 			i++;
// 		}
// 		e++;
// 	}
// }

// void	heat_back(t_fil *node, int lin, int col)
// {
// 	int v;
// 	int c;
// 	v = 9;
// 	c = 1;
// 	while(v > 1 && col - c > 0)
// 	{
// 		if (node->mp[lin][col-c] == '.' && node->hm[lin][col-c] < v)
// 		{
// 			node->hm[lin][col-c] = v;	
// 		}
// 		c++;
// 		v--;
// 	}
// }

// void	heat_forward(t_fil *node, int lin, int col)
// {
// 	int v;
// 	int c;
// 	v = 9;
// 	c = 1;
// 	while(v > 1 && col + c < node->mcol)
// 	{
// 		if (node->mp[lin][col + c] == '.' && node->hm[lin][col+c] < v)
// 		{
// 			node->hm[lin][col + c] = v;
// 		}
// 		c++;
// 		v--;
// 	}
// }

// void	heat_up(t_fil *node, int lin, int col)
// {
// 	int v;
// 	int l;
// 	v = 9;
// 	l = 1;
// 	while(v > 1 && lin - l > 0)
// 	{
// 		if (node->mp[lin - l][col] == '.' && node->hm[lin-l][col] < v)
// 		{
// 			node->hm[lin - l][col] = v;
// 		}
// 		l++;
// 		v--;
// 	}
// }

// void	heat_down(t_fil *node, int lin, int col)
// {
// 	int v;
// 	int l;
// 	v = 9;
// 	l = 1;
// 	while(v > 1 && lin + l < node->mlin)
// 	{
// 		if (node->mp[lin + l][col] == '.' && node->hm[lin+l][col] < v)
// 		{
// 			node->hm[lin + l][col] = v;
// 		}
// 		l++;
// 		v--;
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

			if (node->mp[e][i] == node->em ||
			node->mp[e][i] == node->em - 32)
			{
				heat_it(node, e, i);
				node->hm[e][i] = -1;
			}
			if (node->mp[e][i] == '.' && node->hm[e][i] == 0)
				node->hm[e][i] = 2;
			if (node->mp[e][i] == node->me ||
			node->mp[e][i] == node->me - 32)
				node->hm[e][i] = 1;
			i++;
		}
		e++;
	}
}

// void	straight_up(t_fil *node)
// {
// 	int e;
// 	int i;
// 	if (node->mlin == 15)
// 	{
		
// 		e = 0;
// 		i = 14;
// 	}
// 	if (node->mlin == 24)
// 	{
// 		e = 0;
// 		i = 27;
// 	}
// 	while (e < node->mlin)
// 	{
// 				node->hm[e][i] = 10;
// 		e++;
// 	}
// }

void	diagonal(t_fil *node)
{
	int e;
	int i;
	if (node->mlin < 100 && node->player == 2)
		straight_up(node);
	if (node->mlin == 100)
	{
		e = 29;
		i = 30;
		while (e < node->mlin && i < node->mcol)
		{
			node->hm[e][i] = 5;
			e++;
			i++;
		}
	}
}

void	clear_map(t_fil *node)
{
	int e;
	int i;
	e = 0;
	while (e < node->mlin)
	{
		i = 0;
		while (i < node->mcol)
		{
			node->hm[e][i] = 2;
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
	clear_map(node);
	// if (node->mlin > 20)
	diagonal(node);
	// else
		// divide_map(node);
	find_em_me(node);
	// diagonal(node);
}
