/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:08:02 by arahmoun          #+#    #+#             */
/*   Updated: 2023/11/21 03:44:02 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_rest(char *ptr)
{
	int		i;
	int		j;
	char	*sv;

	i = 0;
	while (ptr[i] != '\0' && ptr[i] != '\n')
		i++;
	if (ptr[i] == '\0')
	{
		free(ptr);
		return (NULL);
	}
	sv = (char *)malloc(ft_strlen(ptr) - i + 1);
	if (!sv)
		return (NULL);
	j = 0;
	while (ptr[i] != '\0')
		sv[j++] = ptr[++i];
	free(ptr);
	sv[j] = '\0';
	return (sv);
}

char	*ft_line(char *ptr)
{
	char	*line;
	int		i;

	i = 0;
	if (!ptr[i])
		return (NULL);
	while (ptr[i] != '\0' && ptr[i] != '\n')
		i++;
	if (ptr[i] == '\0')
		line = (char *)malloc(i + 1);
	else
		line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	if (ptr[i] == '\0')
		ft_strlcpy(line, ptr, i + 1);
	else
		ft_strlcpy(line, ptr, i + 2);
	return (line);
}

char	*gnl_read(int fd, char *ptr)
{
	ssize_t	a;
	char	*dst;

	if (!ptr)
		ptr = ft_strdup("");
	dst = (char *)malloc(BUFFER_SIZE + 1);
	if (!dst)
		return (NULL);
	a = 1;
	while (!ft_strchr(ptr, '\n') && a != 0)
	{
		a = read(fd, dst, BUFFER_SIZE);
		if (a == -1)
		{
			free(ptr);
			free(dst);
			return (NULL);
		}
		dst[a] = '\0';
		ptr = ft_strjoin(ptr, dst);
	}
	free(dst);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*ptr;
	char		*re;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	ptr = gnl_read(fd, ptr);
	if (!ptr)
		return (NULL);
	re = ft_line(ptr);
	ptr = gnl_rest(ptr);
	return (re);
}
