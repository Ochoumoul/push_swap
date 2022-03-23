/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:23:44 by ochoumou          #+#    #+#             */
/*   Updated: 2022/03/23 12:29:47 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract_line(char **buffer_original, char **line)
{
	int		len;
	char	*temp;

	temp = NULL;
	len = 0;
	while ((*buffer_original)[len] != '\0' && (*buffer_original)[len] != '\n')
		len++;
	if ((*buffer_original)[len] == '\n')
	{
		*line = ft_substr(*buffer_original, 0, len + 1);
		temp = ft_substr(*buffer_original + len + 1, 0, \
		ft_strlen(*buffer_original) - len);
	}
	else
		*line = ft_strdup(*buffer_original);
	free(*buffer_original);
	*buffer_original = NULL;
	return (temp);
}

char	*ft_read_buffer(int fd, char *static_buffer)
{
	int		ret;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	ret = 1;
	while (ret != 0 && !ft_strchr(static_buffer, '\n'))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[ret] = '\0';
		static_buffer = ft_strjoin(static_buffer, buffer);
	}
	free(buffer);
	return (static_buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_buffer = ft_read_buffer(fd, static_buffer);
	if (!static_buffer)
		return (NULL);
	static_buffer = ft_extract_line(&static_buffer, &line);
	if (*line == '\0')
	{
		free(line);
		line = NULL;
	}
	return (line);
}
