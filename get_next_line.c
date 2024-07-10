/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:09:39 by pschemit          #+#    #+#             */
/*   Updated: 2024/07/10 15:50:10 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*stati;
	char		buffer[BUFFER_SIZE + 1];
	char		*ligne;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stati)
	{
		stati = malloc(1);
		stati[0] = '\0';
	}
	stati = verfi(buffer, fd, stati);
	if (stati == NULL)
		return (NULL);
	ligne = line(stati);
	stati = ft_stat(stati);
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
