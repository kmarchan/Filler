/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_heat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:44:05 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/19 14:44:33 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

void	heat_back(t_fil *node, int lin, int col)
{
	int v;
	int c;

	v = 9;
	c = 1;
	while (v > 1 && col - c > 0)
	{
		if (node->mp[lin][col - c] == '.' && node->hm[lin][col - c] < v)
		{
			node->hm[lin][col - c] = v;
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
	while (v > 1 && col + c < node->mcol)
	{
		if (node->mp[lin][col + c] == '.' && node->hm[lin][col + c] < v)
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
	while (v > 1 && lin - l > 0)
	{
		if (node->mp[lin - l][col] == '.' && node->hm[lin - l][col] < v)
		{
			node->hm[lin - l][col] = v;
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
	while (v > 1 && lin + l < node->mlin)
	{
		if (node->mp[lin + l][col] == '.' && node->hm[lin + l][col] < v)
		{
			node->hm[lin + l][col] = v;
		}
		l++;
		v--;
	}
}

void	heat_it(t_fil *node, int e, int i)
{
	heat_up(node, e, i);
	heat_down(node, e, i);
	heat_back(node, e, i);
	heat_forward(node, e, i);
}
