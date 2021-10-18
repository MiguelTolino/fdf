/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:05:56 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/18 23:29:34 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	set_color(int x, int y, s_map map)
{
	int z;

	z = map.map[y][x];
	if (!z)
		return (WHITE);
	else if (z <= 10)
		return (RED);
	else if (z < 0 && z >= -20)
		return (BLUE);
	else if (z < -20)
		return (GREEN);
	else if (z > 10 && z < 20)
		return (PURPLE);
	else if (z > 20)
		return (AQUAMARINA);
	else
		return (YELLOW);
}


void display_img(fdf *data)
{
	int y;
	int x;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			data->mlx.color = set_color(x, y, data->map);
			if (x < data->map.width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->map.height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->mlx.img.ptr, 0, 0);
}