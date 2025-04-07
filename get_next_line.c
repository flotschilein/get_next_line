/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:21:59 by fbraune           #+#    #+#             */
/*   Updated: 2025/04/07 16:29:31 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fd_list	*search_node(int fd, t_fd_list **lst)
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
	new->fd		= fd;
	new->buffer = NULL;
	new->next	= *lst;
	*lst = new;
	return (new);
}

char		*get_next_line(int fd)
{
	static t_fd_list 	*fd_list;
	t_fd_list 			*node;
	int 				read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = search_node(fd, &fd_list);

}

