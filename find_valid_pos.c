/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_valid_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:29:37 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/06 13:54:02 by kmarchan         ###   ########.fr       */
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

void	set_coordinate(t_fil *node, int lin, int col)
{
	node->ret_col = col;
	node->ret_lin = lin;
}

int		check_token_point(t_fil *node, int lin, int col)
{
	int	count;
	int tc;
	int tl;

	count = 0;
	tc = node->ret_col;
	tl = node->ret_lin;
	if (node->pp[lin][col] == '*' && (tl + lin >= 0 && tc + col >= 0) &&
			(tl = lin < node->mlin && tc + col < node->mcol))
		count++;
	return (count);
}

void    temp_map(t_fil *node)
{
    int     line;

    if (!node->tm)
    {
        node->tm = (char **)ft_memalloc(sizeof(char *) * node->mlin);
        mapsize(node);
    }
    if (!node->mp)
        return ;
    line = 0;
    while (line < node->mlin)
    {
        node->tm[line] = ft_strdup(node->mp[line]);
        line++;
    }
}

/*
int		place_pos(t_fil *node)
{
	int col;
	int lin;

	lin = 0;
	col = 0;
	while (node->
}*/
