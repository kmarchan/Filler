/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 13:47:19 by kmarchan          #+#    #+#             */
/*   Updated: 2018/06/29 09:07:15 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

void	**mapsize(t_fil *node)
{
	int		ret;
	char	**ptr2;
	char	*plateau;
	ret = 0;
	ret = (get_next_line(node->fd, &plateau));
	while (ft_strstr(plateau, "Plateau") == NULL && ret != 0)
	{
		ret = (get_next_line(node->fd, &plateau));
	}
	ptr2 = ft_strspliter(plateau, ' ');
	node->mlin = (ft_atoi(ptr2[1]));
	node->mcol = (ft_atoi(ptr2[2]));
//		printf("col %d, lin %d\n", node->mcol, node->mlin);
	return (0);
}


void	map(t_fil *node)
{
	int ret;
	int line;
	char *read;
	char *temp;
	if (!node->mp)
	{
		node->mp = (char **) ft_memalloc(sizeof(char *) * node->mlin);
		mapsize(node);
	}
	if (!node->mp)
		return ;
	ret = get_next_line(node->fd, &read);
	line = 0;
	while (line < node->mlin)
	{
		ret = get_next_line(node->fd, &read);
		node->mp[line] = (char *)ft_memalloc(sizeof(char) * 22);//node->mcol);
		temp = ft_strdup(read);
		ft_memcpy((char *)node->mp[line], ft_strchr(temp, ' ') + 1, node->mcol);
//		ft_putendl(node->mp[line]);
//		ft_putendl(read);
		ft_putnbr(ft_strlen(read));
		ft_putnbr(ft_strlen(node->mp[line]));
		ft_putendl(temp);
		line++;
		ft_strdel(&temp);
		ft_strdel(&read);
	}
//	ft_putchar('\n');
}
