/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 13:46:30 by mmateo-t          #+#    #+#             */
/*   Updated: 2019/12/09 20:30:07 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int			new_line(char **s, char **line)
{
	int		len;
	char	*aux;

	len = 0;
	while (((*s)[len] != '\n' && (*s)[len] != '\0'))
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_substr(*s, 0, len);
		aux = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = aux;
	}
	else
	{
		*line = ft_strdup(*s);
		free(*s);
		*s = NULL;
		return (0);
	}
	return (1);
}

int			return_value(int fd, int n_bytes, char **s, char **line)
{
	if (n_bytes < 0)
		return (-1);
	else if (n_bytes == 0 && s[fd] == '\0')
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (new_line(&s[fd], line));
}

int			get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	int				n_bytes;
	static char		*s[FD_SIZE];
	char			*aux;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while ((n_bytes = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[n_bytes] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			aux = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = aux;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (return_value(fd, n_bytes, s, line));
}
