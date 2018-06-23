#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd;
	char *line;

	fd = open("other.txt", O_RDONLY);
	while (get_next_line(fd, &line))
		printf("%s\n", line);
	close(fd);
	return (0);
}
