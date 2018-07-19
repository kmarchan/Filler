/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 07:09:52 by kmarchan          #+#    #+#             */
/*   Updated: 2018/07/19 17:06:48 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"
#include "filler.h"

void		ft_arrpop(int w, char **ret, char *str, char c)
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

char		**ft_strspliter(char *str, char c)
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
	while ((ft_strstr(player, "exec")) == NULL)
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
	else if (ft_strstr(player, "p2"))
	{
		if (ft_strstr(player, "fluffy.filler"))
			node->player = 2;
		else
			node->player = 1;
	}
}
