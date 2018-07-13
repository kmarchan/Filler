/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 13:47:19 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/10 06:45:46 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include <stdio.h>

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
void	malloc_temp(char **ar, t_fil *node)
{
	int line;
	line = 0;
	ar = (char **)ft_memalloc(sizeof(char *) * node->mlin);
	while (line < node->mlin)
	{
		ar[line] = (char *)ft_memalloc(sizeof(char) * node->mcol +1);
		ft_strcpy(node->tm[line], node->mp[line]);
		line++;
	}
}

void	bzero_array(char **ar, int n)
{
	int line;
	line = 0;
	while(line < n)
	{
		ft_bzero(ar[line], n);
		line++;
	}
}

void	update_map(t_fil *node)
{
	int line;
	line = 0;
	char **temp;
	int	ret;
	char *read;
	(void)ret;
	(void)temp;

	ret = get_line(node->fd, &read);
	while (ft_strstr(read, "012345") == NULL && ret != 0)
	{
		ret = get_line(node->fd, &read);
		// ft_putchar_fd('{', 2);
		// ft_putnbr_fd(ret, 2);
		// ft_putchar_fd('}', 2);
	}
	while (line < node->mlin)
	{

		ret = get_line(node->fd, &read);
		// ft_putchar_fd('{', 2);
		// ft_putendl_fd(read, 2);
		// ft_putchar_fd('}', 2);
		temp = ft_strspliter(read, ' ');
		ft_strcpy(node->mp[line], temp[1]);
		
		line++;
		ft_strclr(read);
	}
}

void	map(t_fil *node)
{
	int		ret;
	int		line;
	char	**temp;
	char	*read;

	(void)ret;
	(void)temp;
	if (!node->mp)
	{
		node->mp = (char **)ft_memalloc(sizeof(char *) * node->mlin);
	}
	if (!node->mp)
		return ;
	
	
	ret = (get_line(node->fd, &read));
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
}
