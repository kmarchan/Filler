/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 07:09:52 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/06 14:30:48 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"
#include "filler.h"

void	ft_arrpop(int w, char **ret, char *str, char c)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (str[len] && str[len] != c)
		len++;
	ret[w] = (char*)ft_memalloc(len + 1);
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
	int		i;
	char	**ret;

	words = 3;
	ret = (char**)malloc(sizeof(*ret) * words + 1);
	i = 0;
	while (i <= words)
	{
		while (*str == c && *str != '\0')
			str++;
		ft_arrpop(i, ret, str, c);
		while (*str != c && *str != '\0')
			str++;
		i++;
	}
	ret[words] = NULL;
	return (ret);
}

void		read_player(t_fil *node)
{
	int		ret;
	char	*player;

	(void)ret;
	ret = (get_next_line(node->fd, &player));
	while ((ft_strstr(player, "p1")) == NULL)
	{
		ret = (get_next_line(node->fd, &player));
	}
	if (ft_strstr(player, "p1"))
	{
		if (ft_strstr(player, "fluffy.filler"))
			node->player = 1;
		else
			node->player = 2;
	}
}

int		main()
{
	t_fil	*node;
	int l = 0;

	node = (t_fil*)ft_memalloc(sizeof(t_fil));
	node->fd = open("file.txt", O_RDONLY);
	
	read_player(node);
	ft_putnbr(node->player);
//	mapsize(node);
	map(node);
	
//	while (l < node->mlin)
//	{
//		printf("%s\n", node->mp[l]);
//		l++;
//	}
	int i;
//	while (l <  node->mlin)
//	{
//		i = 0;
//		while (i < node->mcol)
//		{
//			printf("%c", node->mp[l][i]);
//			i++;
//		}
//		printf("\n");
//		l++;
//	}

	piece(node);
	printf("plin %d, pcol %d\n", node->plin, node->pcol);
//	l = 0;
	
//	while (l < node->plin)
//	{
//		printf("%s\n", node->pp[l]);
//		l++;
//	}
	l = 0;
	i = 0;
	heatmap(node);
//	printf("%d\n", node->mlin);
//	while (l < node->mlin)
//	{
//		i = 0;
//		while (i < node->mcol)
//		{
//			printf("%d", node->hm[l][i]);
//			i++;
//		}
//		printf("\n");
//		l++;
//	}
//	while (l <  node->mlin)
//	{
//		i = 0;
//		while (i < node->mcol)
//		{
//			printf("%c", node->mp[l][i]);
//			i++;
//		}
//		printf("\n");
//		l++;
//	}
	temp_map(node);
	l= 0;
	while (l <  node->mlin)
	{
		i = 0;
		while (i < node->mcol)
		{
			printf("%c", node->tm[l][i]);
			i++;
		}
		printf("\n");
		l++;
	}
//	printf(" stars %d\n", find_stars(node));
	return (0);
}
