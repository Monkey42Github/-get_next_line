/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:54:18 by pschemit          #+#    #+#             */
/*   Updated: 2021/12/02 19:56:27 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		ft_strchr(char *s, int c);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
//
char	*get_next_line(int fd);
char	*ft_stat(char *stati);
char	*line(char *stati);
char	*verfi(char	*buffer, int fd, char *stati);
#endif