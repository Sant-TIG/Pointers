#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	char	*line;
	int		i;
	int		fd;
	fd = open("textos/empty.txt", O_RDONLY);
	i = 10;
	printf("fd = %d\n", fd);
	while(i--)
	{
		line = get_next_line(fd);
		printf("line [%02d]: %s\n", i, line);
		free(line);
	}
	close(fd);
	return (0);
}
