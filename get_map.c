/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 13:47:19 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/05 13:13:26 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

int		get_line(int fd, char **line)
{
	int		byter;
	char	*buff;
	char	*ret;
	int		i;

	buff = (char*)ft_memalloc(sizeof(char) * 1);
	ret = (char*)ft_memalloc(sizeof(char) * 200);
	while ((byter = read(fd, buff, 1)) > 0)
	{
		ft_strcat(ret, buff);
		if (ft_strchr(buff, '\n'))
		{
			break ;
		}
	}
	i = ft_strlen(ret);
	ret[i - 1] = '\0';
	*line = ft_strdup(ret);
	return (byter);
}

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
	return (0);
}

void	map(t_fil *node)
{
	int		ret;
	int		line;
	char	**temp;
	char	*read;

	(void)ret;
	if (!node->mp)
	{
		node->mp = (char **)ft_memalloc(sizeof(char *) * node->mlin);
		mapsize(node);
	}
	if (!node->mp)
		return ;
	ret = get_line(node->fd, &read);
	line = 0;
	while (line < node->mlin)
	{
		node->mp[line] = (char *)ft_memalloc(sizeof(char) * node->mcol);
		ret = get_line(node->fd, &read);
		temp = ft_strspliter(read, ' ');
		ft_strcpy(node->mp[line], temp[1]);
		line++;
		ft_strdel(&read);
	}
	ft_putchar('\n');
}
