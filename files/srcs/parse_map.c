/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:25:14 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/11/09 17:56:23 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	open_map(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY, 0);
	if (fd <= 0)
		throw_error("Map could not be opened");
	return (fd);
}

int	*get_wh(char *filename)
{
	int		*wh;
	int		fd;
	char	*line;
	char	**buffer;

	wh = malloc(sizeof(int) * 2);
	wh[1] = 0;
	fd = open_map(filename);
	while (get_next_line(fd, &line))
	{
		buffer = ft_split(line, ' ');
		wh[0] = array_length(buffer);
		wh[1]++;
		free(line);
		dfree(buffer);
	}
	free(line);
	close(fd);
	return (wh);
}

void	fill_line(char *line, int *map_line)
{
	char	**buffer;
	int		i;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
	{
		map_line[i] = ft_atoi(buffer[i]);
		i++;
	}
	dfree(buffer);
}

t_map	parse_map(char *filename)
{
	t_map	map;
	int		i;
	int		*wh;

	i = 0;
	wh = get_wh(filename);
	map.width = wh[0];
	map.height = wh[1];
	free(wh);
	map.fd = open_map(filename);
	map.map = (int **)malloc(sizeof(int *) * map.height);
	while (i < map.height)
	{
		map.map[i] = (int *)malloc(sizeof(int) * map.width);
		i++;
	}
	i = 0;
	while ((get_next_line(map.fd, &map.line)) > 0)
	{
		fill_line(map.line, map.map[i++]);
		free(map.line);
	}
	close(map.fd);
	free(map.line);
	return (map);
}
