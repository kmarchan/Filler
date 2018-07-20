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

int		heat_diag(t_fil *node, int e, int i)
{
	while (e < node->mlin && i < node->mcol)
	{
		node->hm[e][i] = 5;
		e++;
		i++;
	}
	return (1);
}

void	diagonal(t_fil *node)
{
	int e;
	int i;

	if (node->mlin < 100 && node->player == 2)
		divide_map(node);
	else
	{
		if (node->mlin == 15)
		{
			e = 8;
			i = 2;
		}
		if (node->mlin == 24)
		{
			e = 4;
			i = 11;
		}
		if (node->mlin == 100)
		{
			e = 29;
			i = 30;
		}
		heat_diag(node, e, i);
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
	diagonal(node);
	find_em_me(node);
}
