/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:42:50 by abnaciri          #+#    #+#             */
/*   Updated: 2023/12/28 20:43:19 by abnaciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*reading_line(int fd, char *placed)
{
	char	*buffer;
	ssize_t	readed;

	readed = 1;
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (free(placed), placed = NULL, NULL);
	while (newl_check(placed) && readed > 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buffer);
			return (free(placed), placed = NULL, NULL);
		}
		buffer[readed] = '\0';
		placed = ft_strjoin(placed, buffer);
	}
	free(buffer);
	return (placed);
}

char	*get_next_line(int fd)
{
	static char	*placed;
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (free(placed), placed = NULL, NULL);
	placed = reading_line(fd, placed);
	line = get_theline(placed);
	if (!line)
		return (free(placed), placed = NULL, NULL);
	placed = get_rest(placed);
	return (line);
}
