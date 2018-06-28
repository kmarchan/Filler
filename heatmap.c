#include "filler.h"
#include "libft.h"
#include <stdio.h>

void	heatmap(t_fil *node)
{
	int e;
	int i;
	e = 0;
	lin = node->mlin;
	printf("heatmap\n");
	if (!node->hm)
	{
		printf("- malloc array\n");
		node->hm = (int **)ft_memalloc(sizeof(int *) * node->mlin);
	}
	while (e <= node->mlin)
	{
		printf("- malloc element\n");
		node->hm[e] = (int *)ft_memalloc(sizeof(int) * node->mcol);
		e++;
	}
	e = 0;
	i = 0;
	printf("- begin heatmep\n");
//	printf("mp %s\n", node->mp[0]);
	while (e < node->mlin)
	{
		printf("a\n");
		while (node->mp[e][i] != '\0')
		{
			printf("i\n");
			if (node->mp[e][i] == '.')
			{
				node->hm[e][i] = 1;
			}
			else
			{
				node->hm[e][i] = 0;
			}
			i++;
		}
		e++;
	}
	//return (node);
}
