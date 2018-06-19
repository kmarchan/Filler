/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 07:09:52 by kmarchan          #+#    #+#             */
/*   Updated: 2018/06/19 13:50:31 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

char                    **ft_strspliter(char const *s, char c)
{
        size_t          w;
        char            **ar;

        if (!s)
                return (NULL);
        w = 3; 
        ar = (char **)ft_memalloc(sizeof(char *) * (w + 1));
        ft_strarr(s, ar, c, w);
        if (!ar)
                return (NULL);
        return (ar);
}

int		read_player(int fd)
{
	int		ret;
	char	*player;
	while ((ft_strstr(player, "p1")) == NULL)
	{
		ret = (get_next_line(fd, &player));
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

int	mapsize(int fd)
{
	int		ret;
	int		n;
	char	*ptr;
	char	**ptr2;
	char	*plateau;
	n = 1;
	ret = 0;
	while (ft_strstr(plateau, "Plateau") == NULL)
	{
		ret = (get_next_line(fd, &plateau));
//		printf(" read %s\n", plateau);
	}
//	if ((ptr = ft_strstr(plateau, "Plateau")))
//	{
//		while (!(ft_isdigit(*ptr)))
//			ptr++;
		printf("read %s\n", plateau);
		ptr2 = ft_strspliter(plateau, ' ');
	//	while (n < 3)
	//	{
			printf("%s", ptr2[1]);
			printf("%s", ptr2[2]);
	//		n++;
	//	}
//	}
	return (ret);
}

//void	map()
//{
//
//}
//
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
	int fd;

	fd = open("file.txt", O_RDONLY);
//	printf("out %d", read_player(fd));
	mapsize(fd);
	return (0);
}
