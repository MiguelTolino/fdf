/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 13:46:30 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/08 18:37:20 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	new_line(char **s, char **line)
{
	int		len;
	char	*aux;

	len = 0;
	while (((*s)[len] != '\n' && (*s)[len] != '\0'))
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_substr_gnl(*s, 0, len);
		aux = ft_strdup_gnl(&((*s)[len + 1]));
		free(*s);
		*s = aux;
	}
	else
	{
		*line = ft_strdup_gnl(*s);
		free(*s);
		*s = NULL;
		return (0);
	}
	return (1);
}

int	return_value(int fd, int n_bytes, char **s, char **line)
{
	if (n_bytes < 0)
		return (-1);
	else if (n_bytes == 0 && s[fd] == '\0')
	{
		*line = ft_strdup_gnl("");
		return (0);
	}
	else
		return (new_line(&s[fd], line));
}

int	get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	int				n_bytes;
	static char		*s[FD_SIZE];
	char			*aux;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	n_bytes = read(fd, buff, BUFFER_SIZE);
	while (n_bytes > 0)
	{
		buff[n_bytes] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup_gnl(buff);
		else
		{
			aux = ft_strjoin_gnl(s[fd], buff);
			free(s[fd]);
			s[fd] = aux;
		}
		if (ft_strchr_gnl(s[fd], '\n'))
			break ;
		n_bytes = read(fd, buff, BUFFER_SIZE);
	}
	return (return_value(fd, n_bytes, s, line));
}
