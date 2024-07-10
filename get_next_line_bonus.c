/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:40:44 by pschemit          #+#    #+#             */
/*   Updated: 2024/07/10 16:05:27 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include <stdio.h>

char	*verfi(char	*buffer, int fd, char *stati)
{
	int			i;

	i = 1;
	while (!(ft_strchr(stati, '\n')) && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(stati);
			return (NULL);
		}
		buffer[i] = '\0';
		stati = ft_strjoin(stati, buffer);
	}
	return (stati);
}

char	*line(char *stati)
{
	char	*ligne;
	int		i;

	i = 0;
	if (!stati[0])
		return (NULL);
	while (stati[i] != '\0' && stati[i] != '\n')
		i++;
	ligne = malloc((sizeof(char) * i) + 2);
	i = 0;
	while (stati[i] != '\0' && stati[i] != '\n')
	{
		ligne[i] = stati[i];
		i++;
	}
	if (stati[i] == '\n')
		ligne[i++] = '\n';
	ligne[i] = '\0';
	return (ligne);
}

char	*ft_stat(char *stati)
{
	char	*result;
	int		i;
	int		a;

	a = 0;
	i = 0;
	while (stati[i] != '\0' && stati[i] != '\n')
		i++;
	if (!stati[i])
	{
		free(stati);
		return (NULL);
	}
	result = malloc(ft_strlen(stati) - i + 1);
	if (result == NULL)
		return (NULL);
	i++;
	while (stati[i])
	{
		result[a++] = stati[i++];
	}
	result[a] = '\0';
	free(stati);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*stati[FOPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	char		*ligne;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	if (!stati[fd])
	{
		stati[fd] = malloc(1);
		stati[fd][0] = '\0';
	}
	stati[fd] = verfi(buffer, fd, stati[fd]);
	if (stati[fd] == NULL)
		return (NULL);
	ligne = line(stati[fd]);
	stati[fd] = ft_stat(stati[fd]);
	return (ligne);
}

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
