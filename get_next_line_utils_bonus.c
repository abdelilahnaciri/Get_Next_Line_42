/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:48:37 by abnaciri          #+#    #+#             */
/*   Updated: 2023/12/29 10:06:50 by abnaciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	newl_check(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

size_t	ft_stringlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		return (0);
	}
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (free(s1), s1 = NULL, NULL);
	res = malloc((ft_stringlen(s1) + ft_stringlen(s2) + 1) * sizeof(char));
	if (!res)
		return (free(s1), s1 = NULL, NULL);
	while (s1 != NULL && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 != NULL && s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (free(s1), s1 = NULL, res);
}

char	*get_theline(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (str == NULL || str[i] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	res = malloc(i + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*get_rest(char *str)
{
	int		i;
	char	*res;
	int		j;

	j = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (str[i] == '\0')
		return (free(str), str = NULL, NULL);
	res = malloc(ft_stringlen(str) - i + 1);
	if (!res)
		return (free(str), str = NULL, NULL);
	while (str[i])
		res[j++] = str[i++];
	res[j] = '\0';
	return (free(str), str = NULL, res);
}
