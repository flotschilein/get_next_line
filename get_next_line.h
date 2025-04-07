/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:22:24 by fbraune           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/04/07 18:26:59 by fbraune          ###   ########.fr       */
=======
/*   Updated: 2025/04/03 14:52:06 by fbraune          ###   ########.fr       */
>>>>>>> parent of 37dba49... semi working solution
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_fd_list
{
	int					fd;
	char				*buffer;
	struct s_fd_list	*next;
}				t_fd_list;

<<<<<<< HEAD
char	*get_next_line(int fd);

=======
>>>>>>> parent of 37dba49... semi working solution
#endif