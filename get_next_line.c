/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:21:59 by fbraune           #+#    #+#             */
/*   Updated: 2025/04/07 22:27:12 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_part(int fd, char *reading_buffer, char **buffer)
{
	int		read_bytes;
	char	*temp;

	read_bytes = read(fd, reading_buffer, BUFFER_SIZE);
	if (read_bytes == -1)
		return (free(*buffer), *buffer = NULL, -1);
	reading_buffer[read_bytes] = '\0';
	temp = *buffer;
	*buffer = ft_strjoin(temp, reading_buffer);
	free(temp);
	if (!*buffer)
		return (-1);
	if (read_bytes == 0 || ft_strchr(reading_buffer, '\n'))
		return (0);
	return (1);
}

static char	*read_into_stash(int fd, char *buffer)
{
	char	*reading_buffer;
	int		read_check;

	read_check = 1;
	reading_buffer = malloc(BUFFER_SIZE + 1);
	if (!reading_buffer)
		return (free(buffer), NULL);
	if (!buffer)
	{
		buffer = ft_strdup("");
		if (!buffer)
			return (free(reading_buffer), NULL);
	}
	while (read_check > 0)
	{
		read_check = read_part(fd, reading_buffer, &buffer);
		if (read_check == -1)
			return (free(reading_buffer), NULL);
	}
	return (free(reading_buffer), buffer);
}

static char	*get_line_from_stash(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer || buffer[0] == '\0')
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_substr(buffer, 0, i);
	return (line);
}

static char	*remove_line_from_stash(char *buffer)
{
	int		i;
	char	*new_buffer;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	if (buffer[i] == '\0')
		return (free(buffer), NULL);
	new_buffer = ft_substr(buffer, i, ft_strlen(buffer) - i);
	free(buffer);
	if (!new_buffer)
		return (NULL);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (free(buffer), buffer = NULL, NULL);
	buffer = read_into_stash(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line_from_stash(buffer);
	if (!line)
		return (free(buffer), buffer = NULL, NULL);
	buffer = remove_line_from_stash(buffer);
	return (line);
}
