/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:59:54 by ochoumou          #+#    #+#             */
/*   Updated: 2022/04/04 02:59:09 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(char *str)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	char	buff[1];
	char	line[1000000];
	int		i;
	int		n;

	if (fd < 0)
		return (NULL);
	i = 0;
	line[0] = 0;
	n = read(fd, buff, 1);
	while (n > 0)
	{
		line[i++] = buff[0];
		line[i] = '\0';
		if (buff[0] == '\n')
			return (ft_strdup(line));
		n = read(fd, buff, 1);
	}
	if (!line[0])
		return (NULL);
	return (ft_strdup(line));
}
