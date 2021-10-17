/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:25:14 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/17 18:36:17 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void test(s_map map)
{
	int i = 0;
	int j;
	while (i < map.x)
	{
		j = 0;
		while (j < map.y[i])
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

int *convertoint(s_map *map, int x)
{
	int i;
	int *array;

	i = 0;
	array = (int *)malloc(sizeof(int) * map->y[x]);
	while (i < map->y[x])
	{
		array[i] = ft_atoi(map->buffer[i]);
		i++;
	}
	return (array);
}

int get_x(char *filename)
{
	int x;
	int fd;
	char *line;

	x = 0;
	fd = open_map(filename);
	while (get_next_line(fd, &line))
	{
		x++;
		free(line);
	}
	close(fd);
	free(line);
	return (x);
}

int *get_y(char *filename, int x)
{
	int *width;
	int fd;
	char *line;
	char **buffer;
	int i;

	i = 0;
	fd = open_map(filename);
	width = (int*)calloc(sizeof(int) , x);
	while (get_next_line(fd, &line))
	{
		buffer = ft_split(line, ' ');
		width[i] = array_length(buffer);
		i++;
		free(line);
		dfree(buffer);
	}
	free(line);
	close(fd);
	return (width);
}

s_map parse_map(char *filename)
{
	s_map map;
	int i;

	i = 0;
	map.x = get_x(filename);
	map.y = get_y(filename, map.x);
	map.fd = open_map(filename);
	map.map = (int **)malloc(sizeof(int *) * map.x);
	while (i < map.x)
	{
		map.map[i] = (int *)malloc(sizeof(int) * map.y[i]);
		i++;
	}
	i = 0;
	while ((get_next_line(map.fd, &map.line)) > 0)
	{
		map.buffer = ft_split(map.line, ' ');
		map.map[i] = convertoint(&map, i);
		i++;
		dfree(map.buffer);
		free(map.line);
	}
	free(map.line);
	test(map);
	return(map);
}
