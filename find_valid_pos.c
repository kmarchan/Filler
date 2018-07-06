/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_valid_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:29:37 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/06 09:53:24 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

int		valid(t_fil *node)
{
	int i;
	int l;
	int ovr;
	int stars;

	l = 0;
	ovr = 0;
	stars = 0;
	set_coordinate(node)
	
}

int		set_coordinate(t_fil *node)
{

}
