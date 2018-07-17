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

void	divide_map(t_fil *node)
{
	int e;
	int i;
	int c;
	int r;

	e = 0;
	r = start_row(node);
	c = start_col(node);
	while (e < node->mlin)
	{
		i = 0;
		while (node->mp[e][i] != '\0')
		{
			if ((e == r || i == c) && node->hm[e][i] != 1)
				node->hm[e][i] = 3;
			i++;
		}
		e++;
	}
}