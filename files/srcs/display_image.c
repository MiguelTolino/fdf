/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:05:56 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/19 18:55:58 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	set_color(int x, int y, s_map map, int range)
{
	int z;
	float percent;

	z = map.map[y][x];
	percent = ((float)z / (float)range) * 100;
	//printf("P:%f\n", percent);
	if (percent < 5)
		return (WHITE);
	else if (percent <= 20)
		return (YELLOW);
	else if (percent <= 40)
		return (BLUE);
	else if (percent <= 60)
		return (GREEN);
	else if (percent <= 80)
		return (PURPLE);
	else if (percent > 80)
		return (RED);
	else
		return (AQUAMARINA);
}

int range(fdf *data)
{
	int x;
	int y;
	int max;
	int min;

	y = 0;
	max = __INT_MAX__ * -1;
	min = __INT_MAX__;
	while (y < data->map.height)
	{
		x = 0;
 		while (x < data->map.width)
		{
			if (data->map.map[y][x] < min)
				min = data->map.map[y][x];
			if (data->map.map[y][x] > max)
				max = data->map.map[y][x];
			x++;
		}
		y++;
	}
	return (abs(max - min));
}


void display_img(fdf *data)
{
	int y;
	int x;

	y = 0;
	int r = range(data);
	printf("R:%i\n", r);
	while (y < data->map.height)
	{
		x = 0;
 		while (x < data->map.width)
		{
			data->mlx.color = set_color(x, y, data->map, r);
			if (x < data->map.width - 1)
				plotline(x, y, x + 1, y, data);
				//bresenham(x, y, x + 1, y, data);
			if (y < data->map.height - 1)
				//bresenham(x, y, x, y + 1, data);
				plotline(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->mlx.img.ptr, 0, 0);
}
