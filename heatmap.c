#include "filler.h"
#include "libft.h"
#include <stdio.h>

void	heatmap(t_fil *node)
{
	int e;
	int i;
	int lin;
	(void)lin;
	e = 0;
	lin = node->mlin;
	printf("heatmap lin:");
	if (!node->hm)
	{
		node->hm = (int **)ft_memalloc(sizeof(int *) * node->mlin);
	}
	while (e <= node->mlin)
	{
		node->hm[e] = (int *)ft_memalloc(sizeof(int) * node->mcol);
		e++;
	}
	e = 0;
	i = 0;
//	printf("mp %s\n", node->mp[0]);
	while (e < node->mlin)
	{
//		printf("a\n");
		i = 0;
		while (node->mp[e][i] != '\0')
		{
//			printf("i\n");
			if (node->mp[e][i] == '.')
			{
				node->hm[e][i] = 1;
			}
			i++;
		}
		e++;
	}
	//return (node);
}
