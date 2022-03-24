/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun-zhe <hyun-zhe@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:51:16 by hyun-zhe          #+#    #+#             */
/*   Updated: 2021/06/29 14:49:16 by hyun-zhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_current_line(int fd, int rv, char **line, char **strs)
{
	char	*newline;
	char	*temp;

	newline = ft_strchr(strs[fd], '\n');
	if (newline)
	{
		*line = ft_strtrimchr(strs[fd], '\n');
		if (*(newline + 1))
			temp = ft_strdup(newline + 1);
		else
			temp = NULL;
		free(strs[fd]);
		strs[fd] = temp;
		rv = 1;
	}
	else if (rv == 0 && strs[fd])
	{
		*line = ft_strdup(strs[fd]);
		free(strs[fd]);
		strs[fd] = NULL;
	}
	return (rv);
}

int	get_next_line(int fd, char **line)
{
	static char	*strs[OPEN_MAX];
	char		*buffer;
	int			rv;

	if (fd < 0 || fd >= OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	buffer = malloc((BUFFER_SIZE * sizeof(char)) + 1);
	if (!buffer)
		return (-1);
	rv = 1;
	while (rv > 0 && !ft_strchr(strs[fd], '\n'))
	{
		rv = read(fd, buffer, BUFFER_SIZE);
		buffer[rv] = 0;
		if (rv >= 0)
			strs[fd] = ft_strupdate(strs[fd], buffer);
		if (!strs[fd])
			rv = -1;
	}
	free(buffer);
	buffer = NULL;
	return (get_current_line(fd, rv, line, strs));
}
