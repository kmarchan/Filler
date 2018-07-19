#include "filler.h"
#include "libft.h"

int		start_emcol(t_fil *node)
{
	int	e;
	int	i;

	e = 0;
	while (e < node->mlin)
	{
		i = 0;
		while (node->mp[e][i] != '\0')
		{
			if (node->mp[e][i] == node->em ||
			node->mp[e][i] == node->em - 32)
			{
				return (i);
			}
			i++;
		}
		e++;
	}
	return (i);
}

int		start_emlin(t_fil *node)
{
	int e;
	int i;

	e = 0;
	while (e < node->mlin)
	{
		i = 0;
		while (node->mp[e][i] != '\0')
		{
			if (node->mp[e][i] == node->em ||
			node->mp[e][i] == node->em - 32)
			{
				return (e);
			}
			i++;
		}
		e++;
	}
	return (e);
}

int		start_col(t_fil *node)
{
	int e;
	int i;

	e = 0;
	while (e < node->mlin)
	{
		i = 0;
		while (node->mp[e][i] != '\0')
		{
			if (node->mp[e][i] == node->me ||
			node->mp[e][i] == node->me - 32)
			{
				return (i);
			}
			i++;
		}
		e++;
	}
	return (i);
}

int		start_row(t_fil *node)
{
	int e;
	int i;

	e = 0;
	while (e < node->mlin)
	{
		i = 0;
		while (node->mp[e][i] != '\0')
		{
			if (node->mp[e][i] == node->me ||
			node->mp[e][i] == node->me - 32)
			{
				return (e);
			}
			i++;
		}
		e++;
	}
	return (e);
}

void	straight_up(t_fil *node)
{
	int e;
	int i;
	if (node->mlin == 15)
	{
		
		e = 0;
		i = 14;
	}
	if (node->mlin == 24)
	{
		e = 0;
		i = 27;
	}
	while (e < node->mlin)
	{
				node->hm[e][i] = 10;
		e++;
	}
}

void	divide_map(t_fil *node, int e, int i)
{
	int l;
	int c;

	l = 0;
	while (l < node->mlin)
	{
		c = 0;
		while (node->mp[l][c] != '\0')
		{
			if (/*l == e ||*/ c == 14)// && node->hm[l][c] != 1)
				node->hm[e][i] = 10;
			c++;
		}
		l++;
	}
}