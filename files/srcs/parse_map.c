/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:25:14 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/18 12:40:36 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void test(s_map map)
{
	int i = 0;
	int j;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			printf("%3i ", map.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int open_map(char *map_name)
{
	int fd;

	fd = open(map_name, O_RDONLY, 0);
	if (fd <= 0)
		throw_error("Map could not be opened");
	return (fd);
}

int get_height(char *filename)
{
	int height;
	int fd;
	char *line;

	height = 0;
	fd = open_map(filename);
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	free(line);
	return (height);
}

int get_width(char *filename)
{
	int width;
	int fd;
	char *line;
	char **buffer;

	fd = open_map(filename);
	get_next_line(fd, &line);
	buffer = ft_split(line, ' ');
	width = array_length(buffer);
	free(line);
	dfree(buffer);
	close(fd);
	return (width);
}

void fill_line(char *line, int *map_line)
{
	char **buffer;
	int i;

	i = 0;
	buffer = ft_split(line, ' ');
	while (buffer[i])
	{
		map_line[i] = ft_atoi(buffer[i]);
		i++;
	}
	dfree(buffer);
}

s_map parse_map(char *filename)
{
	s_map map;
	int i;

	i = 0;
	map.width = get_width(filename);
	map.height = get_height(filename);
	map.fd = open_map(filename);
	map.map = (int **)malloc(sizeof(int *) * map.height + 1);
	while (i < map.width)
	{
		map.map[i] = (int *)malloc(sizeof(int) * map.width + 1);
		i++;
	}
	i = 0;
	while ((get_next_line(map.fd, &map.line)) > 0)
	{
		fill_line(map.line,map.map[i]);
		i++;
		free(map.line);
	}
	map.map[i] = NULL;
	printf("W:%i\n", map.width);
	printf("H:%i\n", map.height);
	close(map.fd);
	free(map.line);
	test(map);
	return (map);
}
