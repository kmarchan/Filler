/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 08:37:30 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/20 08:37:35 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

int		start_emcol(t_fil *node)
{
	int	e;
	int	i;

	e = 0;
	while (e < node->mlin)
	{
		i = 0;
		while (node->mp[e][i] != '\0')
		{
			if (node->mp[e][i] == node->em ||
			node->mp[e][i] == node->em - 32)
			{
				return (i);
			}
			i++;
		}
		e++;
	}
	return (i);
}

int		start_emlin(t_fil *node)
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
				return (e);
			}
			i++;
		}
		e++;
	}
	return (e);
}

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
			if (node->mp[e][i] == node->me ||
			node->mp[e][i] == node->me - 32)
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
			if (node->mp[e][i] == node->me ||
			node->mp[e][i] == node->me - 32)
			{
				return (e);
			}
			i++;
		}
		e++;
	}
	return (e);
}
