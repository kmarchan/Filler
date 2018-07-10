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

void    placementoutput(int y, int x)
{
    char *ret;

    ret = ft_strjoin(ft_itoa(y), " ");
    ft_strcat(ret, ft_itoa(x));
    ft_putendl_fd(ret, 1);
    ft_putendl_fd(ret, 2);
    free(ret);
}

int		main()
{
	t_fil	*node;
	int l = 0;
	int m = 0;
	(void)l;

	node = (t_fil*)ft_memalloc(sizeof(t_fil));
	node->mlin = 0;
	node->mcol = 0;
	node->fd = 0;//open("map_o2.txt", O_RDONLY);
	
	ft_putchar_fd('a', 2);
	read_player(node);
	ft_putchar_fd('b', 2);
	mapsize(node);
	ft_putchar_fd('c', 2);
//	malloc_map(node->mp, node);
  	map(node);
	if (strstr(node->mp[0], "."))
		m = 1;
	ft_putchar_fd('d', 2);
	piece(node);
// malloc_temp(node->tm, node);
//	printf("mlin%d: mcol%d\n", node->mlin, node->mcol);
//	ft_putnbr(node->player);
//t_putchar(node->me);
	// int ddn = node->mlin;
	while (1)
	{
		// if (m == 0)
		// {
		
  			
		// }
		ft_putchar_fd('A', 2);
		heatmap(node);
		ft_putchar_fd('B', 2);
		check_map(node);
 		//find_valid(node);
		ft_putchar_fd('C', 2);
		// 
		// ft_putchar_fd('C', 2);
		// printf("%d %d\n", node->ret_lin, node->ret_col);
			// ft_putnbr(node->ret_lin);
			// ft_putchar(' ');
			// ft_putnbr(node->ret_col);
			// ft_putchar('\n');
		ft_putchar_fd('D', 2);
		placementoutput(node->ret_lin, node->ret_col);
			// ft_putnbr_fd(node->ret_lin, 2);
			// ft_putchar_fd(' ', 2);
			// ft_putnbr_fd(node->ret_col, 2);
			// ft_putchar_fd('\n', 2);
		ft_putchar_fd('E', 2);
		// ft_putchar_fd('F', 2);
		free(node->pp);
		// free(node->hm);
		node->score = 0;
		
		//bzero_array(node->mp, node->mlin);
		
		update_map(node);
		update_piece(node);
		ft_putchar_fd('F', 2);
		// bzero_array(node->tm, node->mlin);
	}
	return (0);
}	
