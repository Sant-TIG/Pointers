#include "get_next_line.h"
#include <unistd.h>

char	*ft_get_new_holder(char *holder)
{
	printf ("\n----- GET NEW HOLDER ----\n");
	char	*dst;
	size_t	i;
	size_t	j;

	i = 0;
	while (holder[i] != '\n' && holder[i])
		i++;
	j = 0;
	while (holder[i + j])
		j++;
	if (!holder[j])
	{
		free(holder);
		return (NULL);
	}
	dst = (char *)malloc(sizeof(char) * (j + 1));
	if (!dst)
		return (NULL);
	j = 0;
	while (holder[++i])
		dst[j++] = holder[i];
	dst[j] = '\0';
	free(holder);
	return (dst);
}

char	*ft_get_new_line(char *holder)
{
	printf ("\n----- GET NEW LINE ----\n");
	char	*dst;
	ssize_t	i;

	i = 0;
	if (!holder)
		return (NULL);
	while (holder[i] && holder[i] != '\n')
		i++;
	dst = (char *)malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (holder[i])
	{
		dst[i] = holder[i];
		if (dst[i++] == '\n')
			break;
	}
	dst[i] = '\0';
	return (dst);
}

char	*get_next_line(int fd)
{
	printf ("\n----- GET NEXT LINE ----\n");
	static char	*holder;
	char		*buffer;
	char		*new_line;
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = 1;
	buffer = (char	*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!holder)
	{
		holder = (char *)malloc(sizeof(char) * 1);
		*holder = '\0';
	}
	while (!ft_check_line_break(holder) && bytes > 0)
	{
		printf("\nno line break\n");
		bytes = read(fd, buffer, BUFFER_SIZE);
		printf("bytes = |%ld|\n", bytes);
		if (bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		printf("BUFFER = |%s|\n", buffer);
		holder = ft_strjoin(holder, buffer);
		printf("HOLDER = |%s|\n", holder);
	}
	free(buffer);
	new_line = ft_get_new_line(holder);
	holder = ft_get_new_holder(holder);
	if (bytes == 0)
		return (NULL);
	printf("new_line = |%s|\n", new_line);
	return (new_line);
}
