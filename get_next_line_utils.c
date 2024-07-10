/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:10:14 by pschemit          #+#    #+#             */
/*   Updated: 2021/12/02 19:56:09 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		a;
	char	*str;

	i = 0;
	a = 0;
	str = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[a])
	{
		str[i] = s2[a];
		a++;
		i++;
	}
	free(s1);
	str[i] = '\0';
	return (str);
}

int	ft_strchr(char *s, int c)
{
	int		i;
	char	*str;

	str = (char *) s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	if (str[i] == (char)c)
		return (1);
	return (0);
}
