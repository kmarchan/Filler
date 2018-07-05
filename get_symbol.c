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
	if (node->mcol == 50)
	{
		if (node->me == 'x')
		{
			node->me = 'o';
			node->em = 'x';
		}
		if (node->me == 'o')
		{
			node->me = 'x';
			node->em = 'o';
		}
	}
}
