/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 13:47:19 by kmarchan          #+#    #+#             */
/*   Updated: 2018/06/24 13:47:21 by kmarchan         ###   ########.fr       */
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
	(void)ret;

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
		
		node->mp[line] = (char *)ft_memalloc(sizeof(char *) * node->mcol);
		ft_memcpy((char *)node->mp[line], ft_strchr(read, ' ') + 1, node->mcol);
//		ft_putendl(node->mp[line]);
//		ft_putendl(read);
		line++;
		ft_strdel(&read);
	}
}
