/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_symbol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 07:43:13 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/05 13:03:45 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

void	get_symbol(t_fil *node)
{
	if (node->player == 1)
	{
		node->me = 'o';
		node->em = 'x';
	}
	else if (node->player == 2)
	{
		node->me = 'x';
		node->em = 'o';
	}
}

void	straight_up(t_fil *node)
{
	int e;
	int i;

	if (node->mlin == 15)
	{
		e = 0;
		i = 14;
	}
	if (node->mlin == 24)
	{
		e = 0;
		i = 27;
	}
	while (e < node->mlin)
	{
		node->hm[e][i] = 10;
		e++;
	}
}

void	straight_across(t_fil *node)
{
	int e;
	int i;

	if (node->mlin == 15)
	{
		e = 12;
		i = 0;
	}
	if (node->mlin == 24)
	{
		e = 19;
		i = 0;
	}
	while (i < node->mcol)
	{
		node->hm[e][i] = 10;
		i++;
	}
}

int		divide_map(t_fil *node)
{
	straight_up(node);
	straight_across(node);
	return (1);
}
