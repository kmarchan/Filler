/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrcount.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:15:45 by kmarchan          #+#    #+#             */
/*   Updated: 2018/06/12 08:54:14 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_chrcount(const char *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}
