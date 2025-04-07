/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:21:59 by fbraune           #+#    #+#             */
/*   Updated: 2025/04/07 19:03:00 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static char	*read_into_stash(int fd, char *buffer)
{
	// use read to read from fd into stash
}
static char *get_line_from_stash(char *buffer)
{
	int 	i;
	char 	*line;

	i = 0;
	if(!buffer)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_substr(buffer, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

static char	*remove_line_from_stash(char *buffer)
{
	int		i;
	char	*new_buffer;

	i = 0;
	if(!buffer)
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
	return (buffer);
}

char	*get_next_line(int fd)
{
	s

	if(!buffer)
	{
		buffer = malloc(1);
		if (!buffer)
			return (NULL);
		stash[0] = '\0';
	}
	buffer = read_into_stash(fd, buffer);
	if (!stash)
		return (NULL);
	line = get_line_from_stash(buffer);
	buffer = remove_line_from_stash(buffer);
	return (line);
}
