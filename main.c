/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 13:56:21 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/08 13:49:16 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "filler.h"
#include <stdio.h>
int		main()
{
	t_fil	*node;
	int l = 0;
	(void)l;

	node = (t_fil*)ft_memalloc(sizeof(t_fil));
	node->mlin = 0;
	node->mcol = 0;
	node->fd = 0; //open("file.txt", O_RDONLY);
	
	read_player(node);
//	ft_putnbr(node->player);
	while (1)
	{
  		map(node);
		piece(node);
		heatmap(node);
 		find_valid(node);
		ft_putnbr(node->ret_lin);
		ft_putchar(' ');
		ft_putnbr(node->ret_col);
		ft_putchar(' ');
	}

	

//	temp_map(node);
/*  	printf("mlin=%d,mcol%d\n", node->mlin, node->mcol);
	while (l < node->mlin)
	{
		printf("%s\n", node->mp[l]);
		l++;
	}
  int i;
	while (l <  node->mlin)
	{
		i = 0;
		while (i < node->mcol)
		{
			printf("%c", node->mp[l][i]);
			i++;
		}
		printf("\n");
		l++;
	}

	printf("plin %d, pcol %d\n", node->plin, node->pcol);
	l = 0;
  
	while (l < node->plin)
	{
		printf("%s\n", node->pp[l]);
		l++;
		}
	  l = 0;
	  i = 0;
	printf("mlin %d\n", node->mlin);
	while (l < node->mlin)
	{
		i = 0;
		while (i < node->mcol)
		{
			printf("%d", node->hm[l][i]);
			i++;
		}
		printf("\n");
		l++;
	}
	while (l <  node->mlin)
	{
		i = 0;
		while (i < node->mcol)
		{
			printf("%c", node->mp[l][i]);
			i++;
		}
		printf("\n");
		l++;
	}
  l= 0;
  find_valid(node);
//  while (l <  node->mlin)
//	 {
  //		i = 0;
  //		while (i < node->mcol)
  //		{
  //			printf("%c", node->tm[l][i]);
  //			i++;
//		}
//		printf("\n");
//		l++;
//	}
	printf(" stars %d\n", find_stars(node));
	printf("retl=%d,retc%d\n", node->ret_lin, node->ret_col);*/
	return (0);
}
