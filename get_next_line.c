#include "so_long.h"

#define BUFFER_SIZE 1000

char	*ft_line(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] && buf[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*next_line(char *buf)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buf) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buf[i])
		line[j++] = buf[i++];
	free(buf);
	return (line);
}

char	*to_clean(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin (buffer, buf);
	free (buffer);
	return (temp);
}

char	*read_file(int fd, char *buf, char *buffer)
{
	int		contador;

	if (!buf)
		buf = ft_calloc (1, 1);
	contador = 1;
	while (contador > 0)
	{
		contador = read(fd, buffer, BUFFER_SIZE);
		if (contador == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[contador] = 0;
		buf = to_clean(buf, buffer);
		if (ft_strrchr(buffer, '\n'))
			break ;
	}
	free (buffer);
	return (buf);
}

char	*get_next_line(int fd)
{
	char		*buf_read;
	static char	*buffer;
	char		*line;

	buf_read = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		free(buf_read);
		buffer = NULL;
		buf_read = NULL;
		return (NULL);
	}
	if (!buf_read)
		return (NULL);
	buffer = read_file(fd, buffer, buf_read);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	line = ft_line(buffer);
	buffer = next_line(buffer);
	return (line);
}