/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:21:59 by fbraune           #+#    #+#             */
/*   Updated: 2025/04/07 21:33:32 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_part(int fd, char *reading_buffer, char **buffer)
{
	int	read_bytes;
	char *temp;

	read_bytes = read(fd, reading_buffer, BUFFER_SIZE);
	if (read_bytes == -1)
	{
		free(*buffer);
		*buffer = NULL;
		return (-1);
	}
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
	{
		free (buffer);
		return (NULL);
	}
	if (!buffer)
	{
		buffer = ft_strdup("");
		if (!buffer)
		{
			free(reading_buffer);
			return (NULL);
		}
	}
	while (read_check > 0)
	{
		read_check = read_part(fd, reading_buffer, &buffer);
		if (read_check == -1)
		{
			free(reading_buffer);
			return (NULL);
		}
	}
	free(reading_buffer);
	return (buffer);
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
	{
		free(buffer);
		return (NULL);
	}
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

	if(fd < 0 || BUFFER_SIZE < 1)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = read_into_stash(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line_from_stash(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = remove_line_from_stash(buffer);
	return (line);
}
