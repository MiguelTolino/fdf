/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:25:14 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/06 12:37:36 by mmateo-t         ###   ########.fr       */
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
			printf("%i ", map.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int open_map(char *map_name)
{
	int fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		throw_error("Map could not be opened");
	return (fd);
}

int *convertoint(s_map *map)
{
	int i;
	int *strint;

	i = 0;
	map->y[map->x] = array_length(map->buffer);
	strint = (int *)malloc(sizeof(int) * map->y[map->x]);
	while (i < map->y[map->x])
	{
		strint[i] = ft_getnbr(map->buffer[i]);
		i++;
	}
	return (strint);
}

/*
TODO:Guardar mapa como un doble array de enteros
Steps:
1ºSplit line in individual string of chars
2ºCreate int* with the appropiate size=y=nºcolumns -> Solution: Calculate the length of the array and alloc heap memory
	2.b: Save nºcolumns into an array
3ºConvert chars into integers
4ºfree char*
*/

s_map parse_map(char *argv)
{
	s_map map;

	map.map = (int **)malloc(sizeof(int *) * 50); //FIXME:Hacer la reserva de memoria dinamica
	map.fd = open_map(argv);
	map.y = (int *)malloc(sizeof(int) * 50);
	map.x = 0;
	while ((get_next_line(map.fd, &map.line)) > 0)
	{
		map.buffer = ft_split(map.line, ' ');
		map.map[map.x] = convertoint(&map);
		map.x++;
		dfree(map.buffer);
	}
	test(map);
}
