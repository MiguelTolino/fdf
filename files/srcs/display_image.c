/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:05:56 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/19 20:29:44 by mmateo-t         ###   ########.fr       */
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
