/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:05:56 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/10/14 14:46:38 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	set_color(int x, int y, s_map map)
{
	int z;

	z = map.map[y][x];
	if (!z)
		return (WHITE);
	else if (z > 0 && z <= 10)
		return (RED);
	else if (z < 0)
		return (BLUE);
	else
		return (YELLOW);
}


void display_img(s_mlx *mlx, s_map map)
{
	int x;
	int y;

	y = 0;
	while (y < map.x)
	{
		x = 0;
		while (x < map.y[y])
		{
			mlx->color = set_color(x, y, map);
			if (x < map.y[y] - 1)
				bresenham(x, y, x + 1, y, mlx, map);
			if (y < map.x - 1)
				bresenham(x, y, x, y + 1, mlx, map);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, SIZE_X / 3, SIZE_Y / 3);
}