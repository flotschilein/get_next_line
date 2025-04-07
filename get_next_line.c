/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:21:59 by fbraune           #+#    #+#             */
/*   Updated: 2025/04/07 18:27:20 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_fd_list	*search_node(int fd, t_fd_list **lst)
{
	t_fd_list	*cur;
	t_fd_list	*new;

	cur = *lst;
	while (cur->next != NULL)
	{
		if (cur->fd == fd)
			return (cur);
		cur = cur->next;
	}
	new = malloc(sizeof(t_fd_list));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->buffer = NULL;
	new->next = *lst;
	*lst = new;
	return (new);
}

static void	remove_node(int fd, t_fd_list **lst)
{
	t_fd_list	*cur;
	t_fd_list	*pre;

	cur = *lst;
	pre = NULL;
	if (cur->next != NULL && cur->fd == fd)
	{
		*lst = cur->next;
		free (cur->buffer);
		free (cur);
		return ;
	}
	while (cur->next != NULL && cur.fd != fd)
	{
		pre = cur;
		cur = cur->next;
	}
	if (cur->next != NULL)
	{
		pre->next = cur->next;
		free(cur->buffer);
		free(cur);
	}
}

static char	*read_buffer(int fd, char *buffer)
{
	char	*temp;
	char	*reading_buffer;
	int		i;

	i = 1;
	reading_buffer = malloc(BUFFER_SIZE + 1);
	if (!reading_buffer)
		return (NULL);
	while (i > 0 && (!buffer || !ft_strchr(buffer, '\n')))
	{
		i = read(fd, reading_buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free(reading_buffer);
			return (NULL);
		}
		reading_buffer[i] = '\0';
		temp = ft_strjoin(buffer, reading_buffer);
		free(buffer);
		buffer = temp;
		if (!buffer)
			break ;
	}
	free(reading_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static t_fd_list	*fd_list;
	t_fd_list			*node;
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = search_node(fd, &fd_list);
	if (!node)
		return (NULL);
	node->buffer = read_buffer(fd, node->buffer);
	if (!node->buffer)
	{
		remove_node(fd, &fd_list)
		return (NULL);
	}
	line = line_extractor(&node->buffer);
	if (!line || !node->buffer)
		remove_node(fd, &fd_list);
	return (line);
}
