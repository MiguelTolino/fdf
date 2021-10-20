/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:05:56 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/20 12:40:47 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define N_COLORS 6

unsigned int	set_color(int x, int y, s_map map, s_range r)
{
	int z;
	float inc;

	z = map.map[y][x];
	inc = (float)r.range / N_COLORS;
	if (z <= r.min + inc)
		return (WHITE);
	else if (z <= (r.min + 2 * inc))
		return (YELLOW);
	else if (z <= (r.min + 3 * inc))
		return (BLUE);
	else if (z <= (r.min + 4 * inc))
		return (GREEN);
	else if (z <= (r.min + 5 * inc))
		return (PURPLE);
	else if (z <= (r.min + 6 * inc))
		return (RED);
}

void my_mlx_pixel_put(fdf *data, int x, int y)
{
	char *dst;

	if (x >= SIZE_X || x < 0 || y >= SIZE_Y || y < 0)
		return;
	dst = data->mlx.img.data + (y * data->mlx.img.size_line + x * (data->mlx.img.bbp / 8));
	*(unsigned int *)dst = data->mlx.color;
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
			data->mlx.color = set_color(x, y, data->map, data->map.range);
			if (x < data->map.width - 1)
				plotline(x, y, x + 1, y, data);
			if (y < data->map.height - 1)
				plotline(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->mlx.img.ptr, 0, 0);
	put_controls(data->mlx);
}
