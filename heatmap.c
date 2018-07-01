#include "filler.h"
#include "libft.h"
#include <stdio.h>

void	get_symbol(t_fil *node)
{
	if (node->player == 1)
	{
		node->me = 'o';
		node->them = 'x';
	}
	else if (node->player == 2)
	{
		node->me = 'x';
		node->them = 'o';
		
	}
	if (node->mcol == 50)
	{
		if (node->me == 'x')
		{
			node->me = 'o';
			node->them = 'x';
		}
		if (node->me == 'o')
		{
			node->me = 'x';
			node->them = 'o';
		}
	}
}

int	start_col(t_fil *node)
{
	int e;
	int i;
	e = 0;
	while (e < node->mlin)
	{
		i = 0;
		while (node->mp[e][i] != '\0')
		{
			if (node->mp[e][i] == node->me || node->mp[e][i] == node->me - 32)
			{
				return(i);
			}
			i++;
		}
		e++;
	}
	return(i);
}

int 	start_row(t_fil *node)
{
	int e;
	int i;
	e = 0;
	while (e < node->mlin)
	{
		i = 0;
		while (node->mp[e][i] != '\0')
		{
			if (node->mp[e][i] == node->me || node->mp[e][i] == node->me - 32)
			{
				printf(" b");
				printf("e = %d\n", e);
				return(e);
			}
			i++;
		}
		e++;
	}
	return(e);

}

void	divide_map(t_fil *node)
{
	int e;
	int i;
	e = 0;
	get_symbol(node);
	int r = start_row(node);
	int c = start_col(node);
	printf("row %d, col %d\n", r, c);
	while (e < node->mlin)
	{
		i = 0;
		printf("c");
		while (node->mp[e][i] != '\0')
		{
			printf("b");
			if (e == r || i == c)
			{
				printf("a");
				node->mp[e][i] = 3;
			}
			i++;
		}
		e++;
	}

}

void	heatmap(t_fil *node)
{
	int e;
	int i;
	int lin;
	(void)lin;
	e = 0;
	lin = node->mlin;
	printf("heatmap");
	if (!node->hm)
		node->hm = (int **)ft_memalloc(sizeof(int *) * node->mlin);
	divide_map(node);
	while (e <= node->mlin)
	{
		node->hm[e] = (int *)ft_memalloc(sizeof(int) * node->mcol);
		e++;
	}
	e = 0;
	i = 0;
	get_symbol(node);
	printf("me %c\n", node->me);
	while (e < node->mlin)
	{
//		printf("a\n");
		i = 0;
		while (node->mp[e][i] != '\0')
		{
//			printf("i\n");
			if (node->mp[e][i] == '.')
			{
				node->hm[e][i] = 2;
			}
			if (node->mp[e][i] == node->me || node->mp[e][i] == node->me - 32)
			{
				node->hm[e][i] = 1;
			}
			if (node->mp[e][i] == node->them || node->mp[e][i] == node->them - 32)
			{
				node->hm[e][i] = 0;
			}

			i++;
		}
		e++;
	}
	//return (node);
}
