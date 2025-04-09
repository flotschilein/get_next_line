/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbraune <fbraune@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:14:43 by fbraune           #+#    #+#             */
/*   Updated: 2025/04/08 14:25:30 by fbraune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	ptr = malloc(i + 1);
	if (!ptr)
		return (NULL);
	while (j < i)
	{
		ptr[j] = s1[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	const char	*counter;

	counter = (char *)s;
	while (*counter++ != '\0')
		;
	return (counter - s - 1);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;
	size_t	s_len;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	while (i < len && s[start + i])
	{
		sub[j++] = s[start + i];
		i++;
	}
	sub[j] = '\0';
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	char	*new;

	len = 0;
	i = 0;
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	i = 0;
	len = 0;
	while (s1[i] != '\0')
		new[len++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		new[len++] = s2[i++];
	new[len] = '\0';
	return (new);
}
