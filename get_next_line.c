/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:21:59 by fbraune           #+#    #+#             */
/*   Updated: 2025/04/13 22:04:23 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{

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