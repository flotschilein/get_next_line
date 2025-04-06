/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next linepropper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:59:16 by fbraune           #+#    #+#             */
/*   Updated: 2025/04/06 14:59:31 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

static char	*read_into_stash(int fd, char *stash)
{
	char	*buffer;
	char    *new_stash;
	int		bytes_done;
	int		stash_len;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(stash);
		return (NULL);
	}
	stash_len = ft_strlen(stash);
	bytes_done = 1;
	while (bytes_done > 0 && !ft_strchr(stash, '\n'))
	{
		bytes_done = read(fd, buffer, BUFFER_SIZE);
		if (bytes_done <= 0)
			break ;
		buffer[bytes_done] = '\0';
		new_stash = malloc(stash_len + bytes_done + 1);
		if (!new_stash)
		{
			free(stash);
			free(buffer);
			return (NULL);
		}
		ft_strcpy(new_stash, stash);
		free(stash);
		ft_strcpy(new_stash + stash_len, buffer);
		stash = new_stash;
		stash_len += bytes_done;
	}
	free(buffer);
	if (bytes_done == -1)
	{
		free(stash);
		return (NULL);
	}
	return (stash);
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
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_substr(buffer, i, ft_strlen(buffer) - i);
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	if (!buffer)
	{
		buffer = malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
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
