/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:41:23 by abnaciri          #+#    #+#             */
/*   Updated: 2023/12/28 20:16:14 by abnaciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*placed[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	placed[fd] = reading_line(fd, placed[fd]);
	line = get_theline(placed[fd]);
	if (!line)
		return (free(placed[fd]), placed[fd] = NULL, NULL);
	placed[fd] = get_rest(placed[fd]);
	return (line);
}
