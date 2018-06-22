/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 07:09:52 by kmarchan          #+#    #+#             */
/*   Updated: 2018/06/20 12:27:05 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"
#include "filler.h"

void	ft_strpull(int w,char **ret, char *str, char c)
{
	int		i;
	int 	len;

	len = 0;
	i = 0;
	while (str[len] && str[len] != c)
		len++;
	ret[w] = (char*)malloc(len + 1);
	while (i <= len)
	{
		ret[w][i] = *str;
		i++;
		str++;
	}
	ret[w][i] = '\0';
}

char	**ft_strspliter(char *str, char c)
{
	int		words;
	char	**ret;
	int 	i;

	words = 3;
	ret = (char**)malloc(sizeof(*ret) * words + 1);
	i = 0;
	while (i <= words)
	{
		while (*str == c && *str != '\0')
			str++;
		ft_strpull(i, ret, str, c);
		while (*str != c && *str != '\0')
			str++;
		i++;
	}
	ret[words] = NULL;
	return (ret);
}

int		read_player(t_fil *node)
{
	int		ret;
	char	*player;
	while ((ft_strstr(player, "p1")) == NULL)
	{
		ret = (get_next_line(node->fd, &player));
//		ft_putstr("2\n");
	}
	if (ft_strstr(player, "p1"))
	{
		if (ft_strstr(player, "fluffy.filler"))
			return (1);
		else
			return (2);
	}
	if (ret != 1)
		return (-1);
	else 
		return (-2);
}

void **mapsize(t_fil *node)
{
	int		ret;
//	int		n;
//	int		col;
//	int		lin;
//	char	*ptr;
	char	**ptr2;
	char	*plateau;
//	n = 1;
	ret = 0;
	ret = (get_next_line(node->fd, &plateau));
//	if (!node->mcol)
//		node->mcol = (int)ft_memalloc(sizeof(int));
//	if (!node->mlin)
//		node->mlin = (int)ft_memalloc(sizeof(int));
	while (ft_strstr(plateau, "Plateau") == NULL && ret != 0)
	{
		ret = (get_next_line(node->fd, &plateau));
	//	ft_putstr(plateau);
	}
	ptr2 = ft_strspliter(plateau, ' ');
	node->mlin = (ft_atoi(ptr2[1]));
	node->mcol = (ft_atoi(ptr2[2]));
		printf("col %d, lin %d\n", node->mcol, node->mlin);
//	return (ptr2);
	return (0);
}

void	map(t_fil *node)
{
	int ret;
	int line;
	char *read;

	line = 0;
//	ft_putendl("a");
	if (!node->mp)
	{
//		ft_putendl("c");
		node->mp = (char **) malloc(sizeof(char *) * node->mlin);
		mapsize(node);
	}
	if (!node->mp)
		return ;
//	ft_putendl("d");
	ret = get_next_line(node->fd, &read);
	while (line <= node->mlin || ret != 0)
	{
		ft_putendl("e");
//		node->mp[line] = (char *)ft_memalloc(sizeof(char *) * node->mcol);
		ret = get_next_line(node->fd, &read);
		ft_putendl("f");
		char *strrrr = ft_strchr(read, ' ');
		node->mp[line] = ft_strdup(strrrr);
//		node->mp[line] = ft_strdup(ft_strchr(read, ' ') + 1);
//		ft_putendl("Hi");
//		ft_memcpy((char *)node->mp[line], (char *)read + 4, node->mcol);
//		ft_putendl(node->mp[line]);
		ft_putendl(read);
//		ft_putendl("e2");
		line++;
	}
}

//void	piecesize()
//{
//
//}
//
//void	piece()
//{
//
//}

int		main()
{
	static	t_fil	*node;
	int l = 0;

	if (!node)
		node = (t_fil*)ft_memalloc(sizeof(t_fil));
	node->fd = open("file.txt", O_RDONLY);
//	ft_putnbr(read_player(fd));
	//mapsize(node);
	map(node);
	while (l >= node->mlin)
	{
		ft_putendl("b");
		printf("%s\n", node->mp[l]);
		l++;
	}
	return (0);
}
