/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 13:56:21 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/10 06:23:42 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "filler.h"
#include <stdio.h>
int		main()
{
	t_fil	*node;
	int l = 0;
	int m = 0;
	(void)l;

	node = (t_fil*)ft_memalloc(sizeof(t_fil));
	node->mlin = 0;
	node->mcol = 0;
	node->fd = 0;//open("file.txt", O_RDONLY);
	
	read_player(node);
	mapsize(node);
//	malloc_map(node->mp, node);
  	map(node);
	if (strstr(node->mp[0], "."))
		m = 1;
	piece(node);
// malloc_temp(node->tm, node);
//	printf("mlin%d: mcol%d\n", node->mlin, node->mcol);
//	ft_putnbr(node->player);
//t_putchar(node->me);
	while (1)
	{
		// if (m == 0)
		// {
		
  			
		// }
		
		heatmap(node);
		ft_putchar_fd('A', 2);
		check_map(node);
 		//find_valid(node);
		ft_putchar_fd('B', 2);
		// 
		// ft_putchar_fd('C', 2);
		ft_putnbr(node->ret_lin);
		ft_putchar(' ');
		ft_putnbr(node->ret_col);
		ft_putchar('\n');
		// ft_putchar_fd('D', 2);
		ft_putnbr_fd(node->ret_lin, 2);
		ft_putchar_fd(' ', 2);
		ft_putnbr_fd(node->ret_col, 2);
		ft_putchar_fd('\n', 2);
		
		// ft_putchar_fd('F', 2);
		free(node->pp);
		// free(node->hm);
		node->score = 0;
		
		//bzero_array(node->mp, node->mlin);
		ft_putchar_fd('G', 2);
		update_map(node);
		update_piece(node);
		// bzero_array(node->tm, node->mlin);
	}
	return (0);
}	
