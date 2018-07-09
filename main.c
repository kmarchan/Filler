/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 13:56:21 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/09 12:04:03 by kmarchan         ###   ########.fr       */
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
	node->fd = open("file.txt", O_RDONLY);
	
	read_player(node);
	mapsize(node);
//	printf("mlin%d: mcol%d\n", node->mlin, node->mcol);
//_putnbr(node->player);
//t_putchar(node->me);
//	while (1)
//	{
		//ft_putchar_fd('A', 2);
  		map(node);
		//ft_putchar_fd('B', 2);
		piece(node);
		//ft_putchar_fd('C', 2);
		heatmap(node);
		//ft_putchar_fd('D', 2);
 		find_valid(node);
		//ft_putchar_fd('E', 2);
//		ft_putnbr_fd(node->ret_lin, 2);
		ft_putnbr(node->ret_lin);
//		ft_putchar_fd(' ', 2);
		ft_putchar(' ');
//		ft_putnbr_fd(node->ret_col, 2);
		ft_putnbr(node->ret_col);
//		ft_putchar_fd('\n', 2);
		ft_putchar('\n');
//		free((void**)node->pp);
//		free((void**)node->hm);
//		free((void**)node->mp);
//	}
	return (0);
}	
