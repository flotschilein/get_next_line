/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:21:59 by fbraune           #+#    #+#             */
/*   Updated: 2025/04/03 15:06:54 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *extract_line(char **future_parts)
{
	int i;
	char *line;
	char *temp;

	i = 0;
	while ((*future_parts)[i] != '\n' && (*future_parts)[i] != '\0')
		i++;
	if((*future_parts)[i] != '\n')
		line = (ft_substr(*future_parts, 0, i));
	else
		line = (ft_substr(*future_parts, 0, i + 1));
	if((*future_parts)[i] == '\n')
		i++;
	temp = ft_substr(*future_parts, i, ft_strlen(*future_parts) - i);
	free(*future_parts);
	*future_parts = temp;

	return (line);
}

char *read_file(int fd, char *future_parts)
{
	char *buffer;
	char *temp;
	int read_count;

	read_count = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (read_count > 0 && !ft_strchr(future_parts, '\n'))
	{
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (read_count == -1)
			return (NULL);
		buffer[read_count] = '\0';
		if (!future_parts)
			future_parts = ft_substr("", 0, 0);
		temp = future_parts;
		future_parts = ft_strjoin(future_parts, buffer);
		free(temp);
	}
	return (future_parts);
}

char *get_next_line(int fd)
{
	static char *future_parts;
	char *line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	future_parts = read_file(fd, future_parts);
	if(!future_parts)
		return (NULL);
	if(future_parts[0] == '\0')
	{
		free(future_parts);
		future_parts = NULL;
		return (NULL);
	}
	line = extract_line(&future_parts);

	return (line);
}
