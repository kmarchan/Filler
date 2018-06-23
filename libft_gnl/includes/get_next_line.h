/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 08:19:18 by kmarchan          #+#    #+#             */
/*   Updated: 2018/06/23 13:34:51 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <fcntl.h>

# define BUFF_SIZE 1 

typedef struct	s_list
{
	char		*ovr;
	char		*hold;
	int			fd;
}				t_ins;

int				get_next_line(const int fd, char **line);

#endif
