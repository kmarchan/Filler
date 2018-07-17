/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_stars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:44:35 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/13 13:44:37 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
				if (c > pc)
				{
					c = pc;
				}					
			pc++;
		}	
		pl++;
	}
	return (c);
}

int		lst_star_lin(t_fil *node)
{
	int pc;
	int pl;
	int l;

	l = 0;
	pl = 0;
	while (pl < node->plin)
	{
		pc = 0;
		while(pc < node->pcol)
		{
			if (node->pp[pl][pc] == '*')
			{
				if(l < pl)
					l = pl;
			}
			pc++;
		}	
		pl++;
	}
	return (node->plin - l);
}

int		lst_star_col(t_fil *node)
{
	int pc;
	int pl;
	int c;

	pc = 0;
	pl = 0;
	c = 0;
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
	return (node->pcol - c);
}
