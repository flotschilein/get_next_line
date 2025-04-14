/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:21:59 by fbraune           #+#    #+#             */
/*   Updated: 2025/04/14 17:45:19 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line_buffer(char *buffer)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!buffer || buffer[0] == '\0')
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static void	buffer_move(char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i] != '\0')
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
}

char	*read_to_buffer(int fd, char *buffer, char *temp)
{
	char	buffer_read[BUFFER_SIZE + 1];
	int		read_bytes;
	char	*temp_old;

	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(temp, '\n'))
	{
		read_bytes = read(fd, buffer_read, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(temp), buffer[0] = '\0', NULL);
		if (read_bytes == 0)
			break ;
		buffer_read[read_bytes] = '\0';
		temp_old = temp;
		temp = ft_strjoin(temp_old, buffer_read);
		free(temp_old);
		if (!temp)
			return (NULL);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (buffer[0] = '\0', NULL);
	if (ft_strchr(buffer, '\n'))
		return (line = get_line_buffer(buffer), buffer_move(buffer), line);
	temp = ft_strdup(buffer);
	if (!temp)
		return (NULL);
	buffer[0] = '\0';
	temp = read_to_buffer(fd, buffer, temp);
	if (!temp)
		return (NULL);
	line = get_line_buffer(temp);
	if (line && temp[0])
		ft_strlcpy(buffer, temp + ft_strlen(line), BUFFER_SIZE + 1);
	free(temp);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>
// int main(void)
// {
// 	int fd;
// 	char *next_line;
// 	int i = 0;

// 	fd = open("test.txt", O_RDONLY);
// 	while (i ++ < 3)
// 	{
// 		next_line = get_next_line(fd);
// 		printf("Line: %s", next_line);
// 		free(next_line);
// 	}
// 	close(fd);
// 	return (0);
// }