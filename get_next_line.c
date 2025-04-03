/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:21:59 by fbraune           #+#    #+#             */
/*   Updated: 2025/04/03 20:44:40 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static char	*read_into_stash(int fd, char *stash)
{
	// use read to read from fd into stash
}
static char *get_line_from_stash(char *stash)
{
	// use strchr to find the first newline and return the line
}

static char	*remove_line_from_stash(char *stash)
{
	// use substr to remove the line from the stash
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if(!stash)
	{
		buffer = malloc(1);
		if (!buffer)
			return (NULL);
		stash[0] = '\0';
	}
	stash = read_into_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line_from_stash(stash);
	stash = remove_line_from_stash(stash);
	return (line);
}
