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

void	find_empty(t_fil *node)
{
	int e;
	int i;

	e = 0;
	i = 0;
	while (e < node->mlin)
	{
		i = 0;
		while (node->mp[e][i] != '\0')
		{
			if (node->mp[e][i] == '.')
				node->hm[e][i] = 2;
			if (node->mp[e][i] == node->me || node->mp[e][i] == node->me - 32)
				node->hm[e][i] = 1;
			if (node->mp[e][i] == node->em || node->mp[e][i] == node->em - 32)
				node->hm[e][i] = 0;
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
		node->hm = (int **)ft_memalloc(sizeof(int *) * node->mlin);
	while (e <= node->mlin)
	{
		node->hm[e] = (int *)ft_memalloc(sizeof(int) * node->mcol);
		e++;
	}
	get_symbol(node);
	find_empty(node);
	divide_map(node);
}
