#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
//	int fd;
	char *line;

//	fd = open("txt.txt", O_RDONLY);
	while (get_next_line(0, &line))
		printf("%s\n", line);
//	close(fd);
	return (0);
}
