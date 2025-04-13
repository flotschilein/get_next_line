/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:21:59 by fbraune           #+#    #+#             */
/*   Updated: 2025/04/13 22:49:39 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static char *get_line_stash(char *buffer)
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
static void buffer_move(char *buffer)
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

static char *read_to_stash(int fd, char *buffer, char *temp)

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*temp;

	if(fd < 0 || BUFFER_SIZE < 1)
		return (buffer[0] = '\0' , NULL);
	if (ft_strchr(buffer, '\n'))
		return (line = get_line_stash(buffer), buffer_move(buffer), line);
	temp = ft_strdup(buffer);
	if (!temp)
		return (NULL);
	buffer[0] = '\0';
	temp = read_to_stash(fd, buffer, temp);
	if (!temp)
		return (NULL);
	line = get_line_stash(temp);
	if (line && temp[0])
		ft_strlcpy(buffer, temp + ft_strlen(line), BUFFER_SIZE + 1);
	free (temp);
	return (line);
}

 #include <stdio.h>
#include <fcntl.h>
// int main(int argc, char **argv)
// {
// 	int fd;
// 	char *line;
// 	int i;

// 	i = 0;
// 	if(argc != 2)
// 	{
// 		write(1, "Error", 5);
// 		return (1);
// 	}
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 	{
// 		write(1, "Error", 5);
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		i++;
// 		printf("in line %i there is :%s", i, line);
// 		free(line);
// 	}
// 	close(fd);
// 	line = get_next_line(-1);
// 	if(line == NULL)
// 	{
// 		printf("\ninvalid fd handled correct\n");
// 	}
// 	else
// 	{
// 		printf("invalid fd handled not correct\n");
// 		free(line);
// 	}
// 	return (0);
// }
int main(void)
{
	int fd;
	char *next_line;
	int i = 0;

	fd = open("test.txt", O_RDONLY);
	while (i ++ < 2)
	{
		next_line = get_next_line(fd);
		printf("Line: %s", next_line);
		free(next_line);
	}
	close(fd);
	return (0);
}